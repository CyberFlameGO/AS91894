/* 
 * Doesn't work, refer to the following link
 * for pin mapping as this one is incorrect.
 * https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino
 */
int eLeft = 3;
int mLeft = 12;
int eRight = 11;
int mRight = 13;
int speed = 255;

void setup() {
  pinMode(mLeft, OUTPUT);
  pinMode(mRight, OUTPUT);
}

void loop() {
  digitalWrite(mLeft, LOW);
  digitalWrite(mRight, LOW);
  analogWrite(eLeft, speed);
  analogWrite(eRight, speed); 
}
