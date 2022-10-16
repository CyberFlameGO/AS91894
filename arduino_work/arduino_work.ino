#include <IRLremote.h>
#include <IRL_Decode.h>
#include <IRL_Keycodes.h>
#include <IRL_Nec.h>
#include <IRL_NecAPI.h>
#include <IRL_Platform.h>
#include <IRL_Protocol.h>
#include <IRL_Receive.h>
#include <IRL_Time.h>

#include <Wire.h>
#include <Adafruit_MotorShield.h>  // https://github.com/CyberFlameGO/Adafruit_Motor_Shield_V2_Library
#include <Ultrasonic.h>

#include "utility/Adafruit_MS_PWMServoDriver.h"

/*
   Doesn't work, refer to the following link
   for pin mapping as this one is incorrect.
   https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino
*/

// potentially use the #define directive?
short ir_pin = 3;
short trigger = 5;
short echo = 6;
uint8_t distance;
short speed = 255;



Ultrasonic us(trigger, echo);
CNec IRLremote;
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
  if (!IRLremote.begin(ir_pin))
    Serial.println(F("You did not choose a valid pin."));  // change msg
}

void loop() {
  if (!IRLremote.receiving()) {
    Serial.println(us.read());
    // TODO: Look into using the NEC API for the IRLremote library, so I'm utilising the library and also not having to figure out everything myself.
    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);
    delay(500);
    rightMotor->run(RELEASE);
    leftMotor->run(RELEASE);
    delay(500);
    rightMotor->run(BACKWARD);
    leftMotor->run(BACKWARD);
    delay(500);
    rightMotor->run(RELEASE);
    leftMotor->run(RELEASE);
    delay(10);
  }
  if (IRLremote.available())
  {

    // Get the new data from the remote
    auto data = IRLremote.read();

    // Print the protocol data
    Serial.print(F("Address: 0x"));
    Serial.println(data.address, HEX);
    Serial.print(F("Command: 0x"));
    Serial.println(data.command, HEX);
    Serial.println();

  }
}
