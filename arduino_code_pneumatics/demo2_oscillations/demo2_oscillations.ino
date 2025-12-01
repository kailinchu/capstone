
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
  Serial.println("Found MPRLS sensor");
}

int lastUpdate = millis();
int pressureValues[] = {10,50,100,150, 200};

int speed_pwm = 92;
int hold_delay_ms = 7000;
int numPressures = sizeof(pressureValues)/sizeof(pressureValues[0]);

void loop() {

  // wait to start
  int pressure_reached[] = {0,0,0,0,0};
  while(digitalRead(GREEN_BTN) ==0){  
    };
    if(digitalRead(GREEN_BTN) ==1){
      while(digitalRead(GREEN_BTN) ==1){};
        delay(50);
        digitalWrite(GREEN_LED,1);
      }
  float startingPressure = 740;
  for (int i=0; i<numPressures; i++){
      while(pressure_reached[i]==0){
        analogWrite(PUMP_PIN, speed_pwm);
        float pressure_hPa = mpr.readPressure();
        float pressure_mmHg = (pressure_hPa*0.75006) - startingPressure;
        Serial.println(pressure_mmHg);
        
        if (digitalRead(GREEN_BTN)==1){
          delay(50);
          digitalWrite(GREEN_LED, 0);
          analogWrite(PUMP_PIN, 0);
          break;
        }
        if (pressure_mmHg > pressureValues[i]){
          analogWrite(PUMP_PIN, 0);
          pressure_reached[i] =1;
          digitalWrite(GREEN_LED,0);
          int pauseTime = millis();
          while (millis() - pauseTime< hold_delay_ms){
            float pressure_hPa = mpr.readPressure();
            float pressure_mmHg = (pressure_hPa*0.75006) - startingPressure;
            Serial.println(pressure_mmHg);
          }
          digitalWrite(GREEN_LED,1);
        }
      }
  } 
  digitalWrite(GREEN_LED,0);
  digitalWrite(VALVE_PIN, 1);
  digitalWrite(RED_LED,1);
  int endTime = millis();
  // deflation period
  while (millis() - endTime < 5000){
    float pressure_hPa = mpr.readPressure();
    float pressure_mmHg = (pressure_hPa*0.75006) - startingPressure;
    Serial.println(pressure_mmHg);
  }
  digitalWrite(VALVE_PIN, 0);
  digitalWrite(RED_LED,0);


}
