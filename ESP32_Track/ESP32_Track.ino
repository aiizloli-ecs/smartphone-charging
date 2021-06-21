#include <WiFi.h>
#include <esp_now.h>
#include <Ticker.h>
#include <TM1637Display.h>

// led varialbe
const int DIO = 13;
const int CLK = 26;
TM1637Display ledDisplay(CLK, DIO);
bool ledTurnon = true;

// motor variable
const int motorPin = 27;
bool motorEverOn = false;

// button variable
const int buttonPin = 14;

// interrupt variable
void displayLed();
Ticker timerInterrupt(displayLed, 1000);

// esp_now variable
uint8_t espAddress[] = {0x30, 0xAE, 0xA4, 0x7A, 0xE3, 0x3C};  // REPLACE WITH THE MAC Address of your receiver

// charger variable
int chargerDuration = -1;
bool chargerStatus = false;

// bool hold3sec = false;
bool motorStatus = false;
// esp_err_t result = !ESP_OK;

// time
int secondRemaining = 0;
unsigned long lastShowTime;
unsigned long lastStopTime;
unsigned long startTime;
unsigned long currTime;
unsigned long lastTime;

// receive data
typedef struct struct_sender {
  bool hold3Sec = true;
} struct_sender;
struct_sender chargerSender;

// send data
typedef struct struct_receiver {
  int duration_ = 0;
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
  // chargerDuration = chargerReceiver.duration_;
  if (chargerReceiver.duration_ == -2) {
    lastShowTime = millis();
    lastStopTime = millis();
  }
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("chargerReceiver.duration_: ");
  Serial.println(chargerReceiver.duration_);
}

// interrupt function
void displayLed() {
  String minuteStr = String(chargerDuration);
  String secondStr = "";
  if (secondRemaining < 10) {
    secondStr = "0" + String(secondRemaining);
  }
  else {
    secondStr = String(secondRemaining);
  }
  Serial.print("timeRemaining: ");
  Serial.println((minuteStr + secondStr));
  int timeRemaining = (minuteStr + secondStr).toInt();
  ledDisplay.showNumberDecEx(timeRemaining, 0b01000000, true);

  // if seconds step down to zero then sub chargerDuration with 1
  if (!secondRemaining) {
    Serial.println("Second = 0");
    chargerDuration--;
    secondRemaining = 60;
  }
  secondRemaining--;
}

void setup() {
  // serial setup
  Serial.begin(115200);

  // wifi setup
  Serial.println("WIFI SETUP");
  WiFi.mode(WIFI_STA);

  // led Setup'
  ledDisplay.clear();
  ledDisplay.setBrightness(1, true);
  ledDisplay.showNumberDecEx(chargerDuration + 1, 0b01000000, true);

  // buttonVariable
  pinMode(buttonPin, INPUT_PULLUP);

  // motor
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);

  // esp_now setup
  Serial.println("ESP_NOW SETUP");
  while (esp_now_init() != 0) {
    Serial.print(".");
  }
  esp_now_register_send_cb(OnDataSent);
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, espAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(OnDataRecv);
  startTime = millis();
  Serial.println("Setup Complete");
  // chargerDuration = 10;
}

void loop() {
  currTime = millis();
  if (chargerStatus) {  // if charger is turn on

    // time update
    if (chargerDuration >= 0) {
      timerInterrupt.update();
    }

    status_t timerStatus = timerInterrupt.state();
    // read button, activate low;
    bool pushButton = !digitalRead(buttonPin);
    // Serial.print("pushButton : ");
    // Serial.println(pushButton);

    // if time out
    if (chargerDuration == -1) {
      // stop timer first.
      if (timerStatus) {
        Serial.println("TIMER INTERRUPT IS STOP");
        timerInterrupt.stop();
      }
      // if motor never on, then turn on motor
      if (!motorEverOn) {
        Serial.println("TURN ON MOTOR");
        digitalWrite(motorPin, HIGH);
        motorEverOn = true;
        motorStatus = true;
      }
      else {
        Serial.println("MOTOR!!!");
        if ( (pushButton) && (motorStatus) ) {
          Serial.println("TURN OFF MOTOR");
          digitalWrite(motorPin, LOW);
          motorStatus = false;
        }
      }
    }

    // if user touch "cancle charger" on IOXGD screen.
    // it's mean cancle from user.
    if (chargerReceiver.duration_ == -2) {
      // Serial.println(currTime - lastShowTime);
      int stopDuration = (currTime - lastStopTime) / 1000;
      bool notsameDuration = (chargerReceiver.duration_ != chargerDuration);
      // if not cancle in 30 second then turn to normal state
      if ( ( stopDuration > 30) && (notsameDuration) ) {
        Serial.println("Not Cancle in 30sec");
        chargerReceiver.duration_ = chargerDuration;
        ledTurnon = true;
        ledDisplay.setBrightness(1, ledTurnon);
      }

      // blink led
      if (ledTurnon) {
        if ( (currTime - lastShowTime) > 3000 ) {
          ledTurnon = false;
          ledDisplay.setBrightness(1, ledTurnon);
          lastShowTime = millis();
        }
      }
      else {
        if ( (currTime - lastShowTime) > 1000 ) {
          ledTurnon = true;
          ledDisplay.setBrightness(1, ledTurnon);
          lastShowTime = millis();
        }
      }




      // let's user hold button for 3 second.
      if (pushButton) {
        // turn on motor when push button
        if (!motorStatus) {
          Serial.println("Turnon Motor");
          digitalWrite(motorPin, HIGH);
          motorStatus = true;
        }
        startTime = millis();
        while (pushButton) {
          currTime = millis();
          // blink led
          if (ledTurnon) {
            if ( (currTime - lastShowTime) > 3000 ) {
              ledTurnon = false;
              ledDisplay.setBrightness(1, ledTurnon);
              lastShowTime = millis();
            }
          }
          else {
            if ( (currTime - lastShowTime) > 1000 ) {
              ledTurnon = true;
              ledDisplay.setBrightness(1, ledTurnon);
              lastShowTime = millis();
            }
          }

          // timer push button for 3 sec
          bool hold3sec = (currTime - startTime) >= 3000;
          Serial.println(currTime - startTime);
          if (hold3sec) {
            esp_err_t result = esp_now_send(espAddress,
                                            (uint8_t *) &chargerSender,
                                            sizeof(chargerSender));
            if (result == ESP_OK) {
              Serial.println("MISSION COMPLETE");
              // stop timer first.
              if (timerStatus) {
                Serial.println("TIMER INTERRUPT IS STOP");
                timerInterrupt.stop();
              }
              ledDisplay.showNumberDecEx(0, 0b01000000, true);
              ledTurnon = true;
              ledDisplay.setBrightness(1, ledTurnon);
              motorEverOn = false;
              chargerStatus = false;
              // result = !ESP_OK;
            }
            break;
          }
          pushButton = !digitalRead(buttonPin);
          delay(100);
        }
        digitalWrite(motorPin, LOW);
        motorStatus = false;
      }
    }
  }

  else {  // if charger is turn off

    if (chargerReceiver.duration_ > 0) {  // if duration > 0
      Serial.println("Turnon LED");
      chargerDuration = chargerReceiver.duration_;
      ledDisplay.clear();
      ledDisplay.setBrightness(1, true);
      secondRemaining = 0;
      ledTurnon = true;
      chargerStatus = true;
      timerInterrupt.start();  // turn on interrupt
    }

    else {  // if Duration < 0
      // if led is turn on more than 30 sec with out doing anything
      // then turn off LED
      if (ledTurnon) {
        unsigned long tempDuration = (currTime - startTime) / 1000;
        bool longTime = (tempDuration > 30);
        if (lastTime != tempDuration) {
          lastTime = tempDuration;
          Serial.print("Free Duration : ");
          Serial.println(tempDuration);
        }

        if (longTime) {  // turn off led
          Serial.println("TURNOFF LED");
          ledDisplay.clear();
          ledDisplay.setBrightness(1, false);
          ledTurnon = false;
        }
      }
      // if user is hole button 3 second then send stop charger
      // and return your phone
    }
  }
  delay(100);
}
