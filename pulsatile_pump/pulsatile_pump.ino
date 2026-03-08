/*
  Pulsatile Pump
  Last Edit: July 6, 2024
  Authors: Herwald SE, Sze DY, Ennis DB, Vezeridis AM.
  License: CC BY-NC-SA 4.0

*/

#include <Wire.h>

#define MOTOR_PWM 14
#define MOTOR_EN 27
#define A1 2
#define A0 4
#define PRESSURE_TRANS 32

// declare pulse wave flow vector
// data from http://haemod.uk/aortic
int flowVector[100] = {5,54,107,158,201,233,251,255,253,243,230,213,196,178,162,146,132,119,107,95,82,67,47,22,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
int pulseRate = 60;
int pulseFraction = 25;
int baseline = 5;

void setup() {
  Serial.begin(115200);         

  // INITIALIZE ANALOG OUT OF PULSE (FOR COMPARING PULSE WAVEFORM TO PRESSURE WAVEFORM)
  pinMode(A1, OUTPUT);
  // INITIALIZE DIGITAL OUT TO SYNC PULSE CYCLE TO EXTERNAL EQUIPMENT
  pinMode(13, OUTPUT);
  // initialize digital pin for relay of solenoid valve as an output.
  pinMode(A0, OUTPUT);

  

}
int adcValue;
// the loop function runs over and over again forever
void loop() {
  digitalWrite(MOTOR_EN, HIGH); // enable forward moving of motor
  uint8_t i;

  //myMotor->run(FORWARD);
  int bufferLength = 125-pulseFraction;
  digitalWrite(13, HIGH);
  for (i=0; i<bufferLength; i++) {
    int currentFlow = flowVector[i];
    if (currentFlow < baseline) currentFlow = baseline;

    analogWrite(A1, currentFlow);
    if (i>0) digitalWrite(13, LOW); //
    
    analogWrite(MOTOR_PWM,currentFlow);
    //Serial.println(currentFlow);
    // pressure gauge measurement
    adcValue = analogRead(PRESSURE_TRANS);
    Serial.println(adcValue);
    // currently delays between readings, but we can smoothen this out w non time blocking delays
   
    delay(60*1000/(pulseRate*bufferLength));
  }
  
}
