// C++ code
//

private int interval = 1000;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
}

protected int setInterval(int val) {
  interval = val;
}

public int getInterval() {
  return interval;
}


void loop()
{
  int redLight = 2;
  int yellowLight = 4;
  int greenLight = 7;
  setInterval(getInterval() - 20);
  digitalWrite(greenLight, LOW);
  digitalWrite(redLight, HIGH);
  delay(interval); // Wait for 1000 millisecond(s)
  digitalWrite(redLight, LOW);
  digitalWrite(yellowLight, HIGH);
  delay(interval);
  digitalWrite(yellowLight, LOW);
  digitalWrite(greenLight, HIGH);
  delay(interval);
}
