/**
 * @class Fire
 *
 * Implements an analog fire effect.
 */
class Fire
{
  int pin;
  int currentValue;

  public:

  Fire(int ledPin) {
    pin = ledPin;
    pinMode(pin, OUTPUT);
    currentValue = 0;
  }

  void Update(unsigned long dt) {
    int delta = random(-5, 5);

    currentValue += delta;

    currentValue = constrain(currentValue, 0, 255);

    analogWrite(pin, currentValue);
  }
};
