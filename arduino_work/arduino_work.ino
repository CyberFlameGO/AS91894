// C++ code
//
#include <Servo.h>

int servoDegrees = 0;

Servo servo;

void setup()
{
  servo.attach(3, 500, 2500);
  servoDegrees = 0;
  servo.write(0);
  Serial.begin(9600);
}

void loop()
{
  do {
  servoDegrees += 1;
  //delay(5);
  servo.write(servoDegrees);
  Serial.println(servo.read());
  } 
  while (!(servoDegrees == 180));
  servoDegrees = 0;
  delay(50);
  // todo: make it a for loop
  }
