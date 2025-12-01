
#include <Wire.h>
#include "Adafruit_MPRLS.h"

// SCL Pin is 22, SDA Pin is 21
#define RESET_PIN  -1  
#define EOC_PIN    -1  
Adafruit_MPRLS mpr = Adafruit_MPRLS(RESET_PIN, EOC_PIN);

#define PUMP_PIN 26
#define VALVE_PIN 10

#define GREEN_BTN 4
#define RED_BTN 27

#define GREEN_LED 33
#define RED_LED 32

void setup() {
  Serial.begin(115200);
  pinMode(VALVE_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(GREEN_BTN, INPUT);
  pinMode(RED_BTN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  if (! mpr.begin()) {
    while (! mpr.begin()){
    Serial.println("Failed to communicate with MPRLS sensor, check wiring?");
    }
  }
}

int lastUpdate = millis();
int pwm_list[] = {75,102,153,204};
int measureLimit = 100;


void loop() {
  float startingPressure = 740;
  int done_measuring[] = {0,0,0,0};
  for (int i=0; i<4; i++){
    // press green button to start each reading. Wait for green button to start
    
    while(digitalRead(GREEN_BTN) ==0){  
    };
    if(digitalRead(GREEN_BTN) ==1){
      while(digitalRead(GREEN_BTN) ==1){};
        delay(50);
        digitalWrite(GREEN_LED,1);
      }
      

    int startTime = millis();
    while(done_measuring[i]==0){
      analogWrite(PUMP_PIN, pwm_list[i]);
        float pressure_hPa = mpr.readPressure();
        float pressure_mmHg = (pressure_hPa*0.75006) - 740;
        Serial.println(pressure_mmHg);
        startTime = millis();
      
      if (digitalRead(GREEN_BTN)==1){
        delay(50);
        digitalWrite(GREEN_LED, 0);
        analogWrite(PUMP_PIN, 0);
        delay(5000);
      }
      if (digitalRead(RED_BTN)==1){
        delay(50);
        digitalWrite(RED_LED, 1);
        analogWrite(PUMP_PIN, 0);
        break;
      }
      
      if (pressure_mmHg > measureLimit){
        digitalWrite(GREEN_LED, 0);
        analogWrite(PUMP_PIN, 0);
        done_measuring[i] = 1;
        break;
      }
    }
    int endTime = millis();

    // wait for click pressure to release
    while(digitalRead(RED_BTN) ==0){};
    if(digitalRead(RED_BTN) ==1){
      while(digitalRead(RED_BTN) ==1){};
      delay(50);
      digitalWrite(VALVE_PIN, 1);
      digitalWrite(RED_LED,1);
      }
    while(digitalRead(RED_BTN) ==0){};
    if(digitalRead(RED_BTN) ==1){
      while(digitalRead(RED_BTN) ==1){};
      delay(50);
      digitalWrite(VALVE_PIN, 0);
      digitalWrite(RED_LED,0);
    }
  }

}
