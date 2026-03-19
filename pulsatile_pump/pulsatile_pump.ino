/*
  Pulsatile Pump
  Last Edit: July 6, 2024
  Authors: Herwald SE, Sze DY, Ennis DB, Vezeridis AM.
  License: CC BY-NC-SA 4.0

*/

#include <Wire.h>


#define MOTOR_PWM 14
#define MOTOR_EN 27

#define BUTTON_LOW 13
#define LED_LOW 25
#define BUTTON_MID 32
#define LED_MID 26
#define BUTTON_HIGH 21
#define LED_HIGH 23

// declare pulse wave flow vector
// data from http://haemod.uk/aortic
int flowVector[100] = {5,54,107,158,201,233,251,255,253,243,230,213,196,178,162,146,132,119,107,95,82,67,47,22,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
//int pulseRate = 60;
int pulseRates[8] = {60,100,140};
int pulseFraction = 25;
int baseline = 5;

void setup() {
  Serial.begin(115200);     

  // INITIALIZE PERIPHERALS
  pinMode(BUTTON_LOW, INPUT_PULLUP);
  pinMode(BUTTON_MID, INPUT_PULLUP);
  pinMode(BUTTON_HIGH, INPUT_PULLUP);
  // initialize digital pin for relay of solenoid valve as an output.
  pinMode(LED_LOW, OUTPUT);
  pinMode(LED_MID, OUTPUT);
  pinMode(LED_HIGH, OUTPUT);
}
uint8_t i;
bool low_reading = 0;
bool mid_reading = 0;
bool high_reading=0;
int pulseRate = 0;
// the loop function runs over and over again forever
void loop() {
  int bufferLength = 125-pulseFraction;
  digitalWrite(13, HIGH);
  if (pulseRate!=0){
    digitalWrite(MOTOR_EN, HIGH); // enable forward moving of motor
    for (i=0; i<bufferLength; i++) {
      int currentFlow = flowVector[i];
      if (currentFlow < baseline) currentFlow = baseline;
      // analogWrite(A1, currentFlow);
      // if (i>0) digitalWrite(13, LOW); //
      analogWrite(MOTOR_PWM,currentFlow);
    
      delay(60*1000/(pulseRate*bufferLength));
    }
  }
  else{
    digitalWrite(MOTOR_EN, LOW); // stop motor
  }

  if (digitalRead(BUTTON_LOW) == LOW && !low_reading){
    low_reading = 1;
    delay(20);
    
    pulseRate = 60;
    digitalWrite(LED_LOW, HIGH);
    digitalWrite(LED_MID, LOW);
    digitalWrite(LED_HIGH,LOW);
    // pulseRate = pulseRates[pulseRateIndex];
    Serial.print("60 BPM");
  }
  else{
    if (digitalRead(BUTTON_LOW) == HIGH){
    low_reading = 0;
    }
  }

  if (digitalRead(BUTTON_MID) == LOW && !mid_reading){
    mid_reading = 1;
    delay(20);
    
    pulseRate = 100;
    digitalWrite(LED_LOW, LOW);
    digitalWrite(LED_MID, HIGH);
    digitalWrite(LED_HIGH,LOW);
    // pulseRate = pulseRates[pulseRateIndex];
    Serial.print("100 BPM");
  }
  else{
    if (digitalRead(BUTTON_MID) == HIGH){
    mid_reading = 0;
    }
  }

  if (digitalRead(BUTTON_HIGH) == LOW && !high_reading){
    high_reading = 1;
    delay(20);
    
    pulseRate = 140;
    digitalWrite(LED_LOW, LOW);
    digitalWrite(LED_MID, LOW);
    digitalWrite(LED_HIGH,HIGH);
    Serial.print("120 BPM");
  }
  else{
    if (digitalRead(BUTTON_HIGH) == HIGH){
    high_reading = 0;
    }
  }
}
