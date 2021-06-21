#include <WiFi.h>
#include <esp_now.h>

/*
   charger 1
   32 -> 30 min
   35 -> 45 min
   34 -> 60 min
   10 -> cancle
   22 -> voltage output
   charger 2
   33 -> 30 min
   25 -> 45 min
   26 -> 60 min
   11 -> cancle
   23 -> voltage output

   charger_status[i]
   i -> 0 = charger1, 1 = charger2
   0 -> off
   1 -> on
*/

//  esp32 adress
uint8_t espAddress[][6] = {
  {0x3C, 0x61, 0x05, 0x13, 0x9B, 0x1C},
  {0x24, 0x0A, 0xC4, 0xEE, 0x76, 0x0C}
};

// IOXGD variable communication
const int duration[][2] = {
  { -2, 1},
  {3, 5},
};  // change time
const int chargerInput[][2] = {  // pin
  {36, 39},
  {34, 35}
};
const int stopchargerOutput[] = {32, 33};  // stop charging pin
const int successfullyOutput[] = {25, 26};  // verify data pin

// led OUTPUT
const int ledPin[][2] = {  // pin
  {15, 3},  // box1, 15 -> green, 3 -> red,
  {4, 16},  // box2, 4 -> green, 16 -> red
};

// relay OUTPUT
const int elecDoor[] = {22, 23};  // 22 -> door lock 1, 23 -> door lock 2
bool doorOpen[] = {false, false};
const int chargerOutput[] = {14, 27};  // 14 -> voltage output1, 27 -> volate output2
bool chargerTurnon[] = {false, false};

// switch INPUT
const int doorSwitch[] = {21, 19};  // 21 -> box1, 19 -> box2
// bool doorStatus[] = {false, false};
const int trackSwitch[] = {5, 18};  // 5 -> box1 -> 18 -> box2
// bool trackStatus[] = {false, false};

unsigned long startTime[] = {0, 0};
const int numData = 2;

int chargerDuration[] = {0, 0};
bool chargerStatus[] = {false, false};
bool stopCharger = false;
// esp_err_t result[] = {!ESP_OK, !ESP_OK};

bool sendSuccess[] = {false, false};

// send data
typedef struct struct_sender {
  int duration_ = 0;
} struct_sender;
struct_sender chargerSender[2];

// receive data
typedef struct struct_receiver {
  bool hold3Sec = false;
} struct_receiver;
struct_receiver chargerReceiver;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0) {
    Serial.println("Delivery success");
  }
  else {
    Serial.println("Delivery fail");
  }
}

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  memcpy(&chargerReceiver, incomingData, sizeof(chargerReceiver));
  Serial.print("Bytes received: ");
  Serial.println(len);
  stopCharger = chargerReceiver.hold3Sec;
}

void setup() {
  // serial setup
  Serial.begin(115200);

  // wifi setup
  Serial.println("WIFI SETUP");
  WiFi.mode(WIFI_STA);

  // esp_now setup
  Serial.println("ESP SETUP");
  while (esp_now_init() != 0) {
    Serial.print(".");
    delay(10);
  }
  esp_now_register_send_cb(OnDataSent);  // send fn
  esp_now_peer_info_t peerInfo;

  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  // add first peer
  memcpy(peerInfo.peer_addr, espAddress[0], 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  // add second peer
  memcpy(peerInfo.peer_addr, espAddress[1], 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(OnDataRecv);

  // setup
  Serial.println("CHARGER SETUP");
  // int numData = sizeof(charger1Input) / 4;
  for (int i = 0; i < numData; i++) {
    // charger
    pinMode(chargerInput[0][i], INPUT);
    pinMode(chargerInput[1][i], INPUT);
    pinMode(stopchargerOutput[i], OUTPUT);
    pinMode(successfullyOutput[i], OUTPUT);

    // switch
    pinMode(doorSwitch[i], INPUT_PULLUP);
    pinMode(trackSwitch[i], INPUT_PULLUP);

    // led
    pinMode(ledPin[0][i], OUTPUT);  // box1
    pinMode(ledPin[1][i], OUTPUT);  // box2

    // relay
    pinMode(elecDoor[i], OUTPUT);
    pinMode(chargerOutput[i], OUTPUT);

    // init setup
    digitalWrite(stopchargerOutput[i], LOW);  // send to ioxgd
    digitalWrite(successfullyOutput[i], LOW);  // send to ioxgd
    digitalWrite(elecDoor[i], LOW);  // open door
    doorOpen[i] = true;  // init door is open

    digitalWrite(chargerOutput[i], HIGH);  // HIGH - turn off charger
    chargerTurnon[i] = false;

    digitalWrite(ledPin[0][i], LOW);  // turn off led
    digitalWrite(ledPin[1][i], LOW);  // turn off led
  }
  // turn both green led on
  for (int i = 0; i < numData; i++) {
    digitalWrite(ledPin[i][0], HIGH);
    digitalWrite(ledPin[i][1], LOW);
  }
}

void chargerFunction(int chargerNumber) {
  Serial.print("chargerNumber: ");
  Serial.println(chargerNumber + 1);

  int arrCharger[numData];
  for (int i = 0; i < numData; i++) {
    arrCharger[i] = digitalRead(chargerInput[chargerNumber][i]);
  }

  Serial.print("chargerInput[");
  Serial.print(chargerInput[chargerNumber][0]);
  Serial.print(",");
  Serial.print(chargerInput[chargerNumber][1]);
  Serial.print("] : [");
  Serial.print(arrCharger[0]);
  Serial.print(",");
  Serial.print(arrCharger[1]);
  Serial.println("]");

  unsigned long currTime = millis() / 1000;
  int Duration = duration[arrCharger[0]][arrCharger[1]];
  bool trackStatus = !digitalRead(trackSwitch[chargerNumber]);
  bool doorStatus = !digitalRead(doorSwitch[chargerNumber]);
  bool valueChange = (chargerSender[chargerNumber].duration_ != Duration);
  bool isCancle = (Duration == -2);  // if duration == 0 mean cancle

  /*
    Serial.print("trackStatus[");
    Serial.print(trackSwitch[chargerNumber]);
    Serial.print("] : ");
    Serial.println(trackStatus);

    Serial.print("doorStatus[");
    Serial.print(doorSwitch[chargerNumber]);
    Serial.print("] : ");
    Serial.println(doorStatus);
  */

  if (valueChange) {
    Serial.print("Duration : ");
    Serial.println(Duration);
    // protected overload

    if (chargerStatus[chargerNumber]) {
      unsigned long workDuration = (currTime - startTime[chargerNumber]) / 1000;
      if (workDuration > 3) {
        chargerSender[chargerNumber].duration_ = Duration;
      }
    }
    else {
      chargerSender[chargerNumber].duration_ = Duration;
    }

    // if charger turn on and get cancle command from IOXGD and never send cancle data to track
    // then set sendSuccess to false.
    if ( (chargerStatus[chargerNumber]) && (isCancle) ) {
      Serial.println("Cancle");
      if (Duration == -2) {
        sendSuccess[chargerNumber] = false;
      }
    }
  }

  if (chargerStatus[chargerNumber]) { // charger turn on
    bool isTimeout = (currTime - startTime[chargerNumber]) > chargerDuration[chargerNumber];
    if (doorOpen[chargerNumber]) {  // if door is open
      Serial.println("GET TRACK AND CLOSE DOOR");
      if ( (!trackStatus) && (doorStatus) ) {  // if track is empty and door is close
        Serial.println("ALREADY CLOSE DOOR");
        digitalWrite(elecDoor[chargerNumber], HIGH);  // door lock
        doorOpen[chargerNumber] = false;
        Serial.println("RED LED TURN ON");
        digitalWrite(ledPin[chargerNumber][0], LOW);  // turn off green led
        digitalWrite(ledPin[chargerNumber][1], HIGH);  // turn on red led
      }
    }
    else {  // if door is close
      if (isTimeout) {  // if time out
        Serial.println("TIMEOUT");
        // if charger output is turn on
        if (chargerTurnon[chargerNumber]) {
          Serial.println("STOP CHARGER");
          digitalWrite(chargerOutput[chargerNumber], HIGH);  // stop charger
          chargerTurnon[chargerNumber] = false;
        }
      }
      // if cancle from IOXGD
      if (isCancle) {
        Serial.println("CANCLE");
        // send stop charger data to track
        if (!sendSuccess[chargerNumber]) {
          Serial.println("SEND STOP CHARGER DATA");
          esp_err_t result = esp_now_send(espAddress[chargerNumber],
                                          (uint8_t *) &chargerSender[chargerNumber],
                                          sizeof(chargerSender[chargerNumber]));
          // if send data success
          if (result == ESP_OK) {
            digitalWrite(successfullyOutput[chargerNumber], HIGH);
            Serial.println("SEND CANCLE DATA TO TRACK SUCCESS");
            sendSuccess[chargerNumber] = true;
            delay(1000);
            digitalWrite(successfullyOutput[chargerNumber], LOW);
          }

        }
        else {  // (sendSuccess[chargerNumber])
          Serial.println("WAIT FOR HOLD BUTTON FOR 3 SECOND");
          // if user hold button for 3 sec then open the door
          if (stopCharger) {
            Serial.println("CANCLE FROM TRACK");
            digitalWrite(stopchargerOutput[chargerNumber], HIGH);
            delay(1000);
            digitalWrite(stopchargerOutput[chargerNumber], LOW);

            // if chargerOutput is turn on then turn off
            if (chargerTurnon[chargerNumber]) {
              digitalWrite(chargerOutput[chargerNumber], HIGH);  // stop charger
              chargerTurnon[chargerNumber] = false;
            }

            digitalWrite(elecDoor[chargerNumber], LOW);  // door open
            doorOpen[chargerNumber] = true;  // door status

            // turn green led on
            digitalWrite(ledPin[chargerNumber][0], HIGH);  // turn on green led
            digitalWrite(ledPin[chargerNumber][1], LOW);  // turn off red led

            // set to default value
            chargerStatus[chargerNumber] = false;
            stopCharger = false;
          }
        }
      }
    }
  }

  else {  // charger is turn off

    if (doorOpen[chargerNumber]) {  // if door is open
      Serial.println("DOOR IS OPEN");
      if (trackStatus && doorStatus) {  // if track is place and door is close
        Serial.println("DOOR LOCK");
        digitalWrite(elecDoor[chargerNumber], HIGH);  // door lock
        doorOpen[chargerNumber] = false;
      }
    }

    else {  // door is close
      if (Duration > 0) {
        esp_err_t result = esp_now_send(espAddress[chargerNumber],
                                        (uint8_t *) &chargerSender[chargerNumber],
                                        sizeof(chargerSender[chargerNumber]));

        if (result == ESP_OK) {
          digitalWrite(successfullyOutput[chargerNumber], HIGH);
          Serial.println("SEND SUCCESSFULLY");

          chargerDuration[chargerNumber] = (Duration * 60) + 2;
          chargerStatus[chargerNumber] = true;

          // open door
          digitalWrite(elecDoor[chargerNumber], LOW);
          doorOpen[chargerNumber] = true;

          // turn on charger output
          digitalWrite(chargerOutput[chargerNumber], LOW);
          chargerTurnon[chargerNumber] = true;

          delay(1000);
          digitalWrite(successfullyOutput[chargerNumber], LOW);
          startTime[chargerNumber] = millis() / 1000;
          // result[chargerNumber] = !ESP_OK;
        }
      }
    }
  }
}


void loop() {
  Serial.println();
  chargerFunction(0);
  Serial.println("---------------------------------------------------------");
  chargerFunction(1);
  //Serial.println("");
  Serial.println("_________________________________________________________");
  delay(100);

}
