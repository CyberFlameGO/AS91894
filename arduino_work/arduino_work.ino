#include <Wire.h>
#include <Adafruit_MotorShield.h>  // https://github.com/CyberFlameGO/Adafruit_Motor_Shield_V2_Library
#include <Ultrasonic.h>
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
short trigger = 5;
short echo = 6;
uint8_t distance;
short speed = 255;



Ultrasonic us(trigger,echo);
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);


void setup() {
//  pinMode(mLeft, OUTPUT);
//  pinMode(mRight, OUTPUT);
  AFMS.begin();
  Serial.begin(9600);
  leftMotor->setSpeed(speed);
  //leftMotor->run(FORWARD);
  rightMotor->setSpeed(speed);
  //rightMotor->run(FORWARD);
}

void loop() {
  Serial.println(us.read());
  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
  delay(100);
  rightMotor->run(RELEASE);
  leftMotor->run(RELEASE);
  delay(10);
  rightMotor->run(BACKWARD);
  leftMotor->run(BACKWARD);
  delay(100);
  rightMotor->run(RELEASE);
  leftMotor->run(RELEASE);
  delay(10);
}
