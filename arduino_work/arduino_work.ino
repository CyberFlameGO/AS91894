#include <Wire.h>
#include <Adafruit_MotorShield.h>  // https://github.com/CyberFlameGO/Adafruit_Motor_Shield_V2_Library
#include "utility/Adafruit_MS_PWMServoDriver.h"

/* 
 * Doesn't work, refer to the following link
 * for pin mapping as this one is incorrect.
 * https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino
 */
short eLeft = 3;
short mLeft = 12;
short eRight = 11;
short mRight = 13;
short speed = 255;
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);


void setup() {
//  pinMode(mLeft, OUTPUT);
//  pinMode(mRight, OUTPUT);
  AFMS.begin();
  leftMotor->setSpeed(speed);
  //leftMotor->run(FORWARD);
  rightMotor->setSpeed(speed);
  //rightMotor->run(FORWARD);
}

void loop() {
  /*
  digitalWrite(mLeft, HIGH);
  digitalWrite(mRight, HIGH);
  analogWrite(eLeft, speed);
  analogWrite(eRight, speed); 
  */
}
