
#include <Wire.h>
#include "Adafruit_MPRLS.h"

// SCL Pin is 22, SDA Pin is 21
#define RESET_PIN  -1  
#define EOC_PIN    -1  
Adafruit_MPRLS mpr = Adafruit_MPRLS(RESET_PIN, EOC_PIN);

#define PUMP_PIN 26
#define VALVE_PIN 10

#define PUMP_BTN 4
#define VALVE_BTN 27

void setup() {
  Serial.begin(115200);
  pinMode(VALVE_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(PUMP_BTN, INPUT);
  pinMode(VALVE_BTN, INPUT);
  if (! mpr.begin()) {
    while (! mpr.begin()){
    Serial.println("Failed to communicate with MPRLS sensor, check wiring?");
    }
  }
  Serial.println("Found MPRLS sensor");
}

int lastUpdate = millis();
bool valve_toggle = 1;
int pwm_sw[] = {0,96};
int pwm_toggle = 0;

void loop() {
    analogWrite(PUMP_PIN, pwm_sw[pwm_toggle]);
    float pressure_hPa = mpr.readPressure();
    Serial.println((pressure_hPa*0.75) - 750);
  if (digitalRead(PUMP_BTN)==1){
    delay(50);
    while(digitalRead(PUMP_BTN) ==1){};
    pwm_toggle = !pwm_toggle;
    analogWrite(PUMP_PIN, pwm_sw[pwm_toggle]);

  } 
  if (digitalRead(VALVE_BTN)==1){
    delay(50);
    while(digitalRead(VALVE_BTN) ==1){};
    valve_toggle = !valve_toggle;
    digitalWrite(VALVE_PIN, valve_toggle);
  } 
  // if (millis() - lastUpdate > 3000){
  //   valve_toggle = !valve_toggle;
  //   digitalWrite(VALVE_PIN, valve_toggle);
  //   lastUpdate = millis();
  // }

}
