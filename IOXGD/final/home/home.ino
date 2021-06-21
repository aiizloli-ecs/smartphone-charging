#include <IOXGD.h>

/*
  extern lv_obj_t* b301Btn;
  extern lv_obj_t* b451Btn;
  extern lv_obj_t* b601Btn;
  extern lv_obj_t* cancle1Btn;

  extern lv_obj_t* b302Btn;
  extern lv_obj_t* b452Btn;
  extern lv_obj_t* b602Btn;
  extern lv_obj_t* cancle2Btn;
*/

// constant charger command
const int chargerCommand[][2] = {
  {0, 0},// cancle
  {0, 1},//30sec
  {1, 0},
  {1, 1}
};

const String chargerDuration[] = {"0", "30", "45", "60"};

// constantcharger pin
const int chargerOutput[][2] = {
  {8, 9},  // charger1 output connected to {32, 33}
  {10, 11}  // charger2 output charger2 pin connected to {34, 35}
};
const int stopchargerInput[] = {12, 13};  // cancle pin connected to {32, 33}
const int successfullyInput[] = {14, 15};  // check receive pin connected to {25, 26}

// temp data
int commandNumber = -1;
int chargerNumber = 0;  // number charger command,  keep data from button

// long term data
int oldCommand[] = { -1, -1};
bool waitStopCharger[] = {false, false};
bool chargerStatus[] = {false, false};  // charger status : 0 - off, 1 - on

unsigned long screenTime = 0;
unsigned long startTime[] = {0, 0};

unsigned long currTime = 0;
const int numData = 2;
int currPage = 0;  // 0 = normal page, 1 = warning page

void checkStopCharger(int chargerIDX) {
  //Serial.print("checkStopCharger : ");
  //Serial.println(chargerIDX);

  bool successfullyCommand = digitalRead(stopchargerInput[chargerIDX]);  // 5
  String remainingTime = "";

  Serial.print("stopchargerInput[");
  Serial.print(chargerIDX);
  Serial.print("] : ");
  Serial.println(successfullyCommand);

  if (successfullyCommand) {
    Serial.println("SUCCESSFULLY STOP CHARGER");

    oldCommand[chargerIDX] = -1;
    chargerStatus[chargerIDX] = false;
    waitStopCharger[chargerIDX] = false;
    remainingTime = "Stop Charger " + String(chargerIDX + 1);
    timeRemaining(chargerIDX, remainingTime);
    homeDisplay();
  }
  else {
    int stopChargerDuration = currTime - startTime[chargerIDX];
    if (stopChargerDuration < 30) {
      remainingTime = 30 - stopChargerDuration;
      timeRemaining(chargerIDX, remainingTime);
    }
    else {
      Serial.println("NOT HOLD TRACK BUTTON 3 SECOND IN 30 SENCOND");
      for (int i = 0; i < numData; i++) {
        digitalWrite(chargerOutput[chargerIDX][i], chargerCommand[oldCommand[chargerIDX]][i]);
      }
      waitStopCharger[chargerIDX] = false;
      remainingTime = "Stop Charger " + String(chargerIDX + 1);
      timeRemaining(chargerIDX, remainingTime);
      homeDisplay();
    }
  }
}

void setup() {
  Serial.begin(115200);
  gd.begin(SETUP_LVGL);
  ESP32.begin();

  for (int i = 0; i < numData; i++) {
    pinMode(chargerOutput[0][i], OUTPUT);
    pinMode(chargerOutput[1][i], OUTPUT);
    pinMode(stopchargerInput[i], INPUT);
    pinMode(successfullyInput[i], INPUT);

    digitalWrite(chargerOutput[0][i], LOW);
    digitalWrite(chargerOutput[1][i], LOW);
  }
  screenTime = millis() / 1000;
  Serial.println("SETUP COMPLEETE");
  xTaskCreate([](void*) {
    load_page();// Show page

    while (true) {
      currTime = millis() / 1000;
      int screenDuration = currTime - screenTime;
      if (screenDuration > 3) {
        // if warning page then change to normal page
        if (currPage == 2) {
          currPage = 0;
          homeDisplay();
        }
        // if display not home screen for 30 sec then back to home screen
        if (screenDuration > 30) {
          if (currPage == 1) {
            currPage = 0;
            // commandNumber = -1;
            // chargerNumber = 0;
            homeDisplay();
          }
        }
      }

      if (chargerStatus[0]) {
        if (waitStopCharger[0]) {
          checkStopCharger(0);
        }
      }
      if (chargerStatus[1]) {
        if (waitStopCharger[1]) {
          checkStopCharger(1);
        }
      }

      delay(10);
    }
  }, "mainTask", 1024, NULL, 1, NULL);
  gd.startFreeRTOS();
}

void loop() { }
