// C++ code
//
class IntervalCode {
  private:
      int interval = 500;

  public:
      void setInterval(int val) {
          interval = val;
      }

  public:
      int getInterval() {
          return interval;
      }
};

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
}

int redLight = 2;
int yellowLight = 4;
int greenLight = 7;
IntervalCode interval;

// IntervalCode::getInterval()

void loop()
{
  interval.setInterval(interval.getInterval() - 20);
  digitalWrite(greenLight, LOW);
  digitalWrite(redLight, HIGH);
  delay(interval.getInterval()); // Wait for 1000 millisecond(s)
  digitalWrite(redLight, LOW);
  digitalWrite(yellowLight, HIGH);
  delay(interval.getInterval());
  digitalWrite(yellowLight, LOW);
  digitalWrite(greenLight, HIGH);
  delay(interval.getInterval());
}
