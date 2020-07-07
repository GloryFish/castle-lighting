/**
 * @class Fade
 *
 * Implements a periodic fade in/out effect.
 */
class Fade
{
  int pin;
  unsigned long interval;
  long elapsed;

  int fadeAmount;
  int brightness;

  long timeRemaining;

  public:

  Fade(int ledPin, unsigned long theInterval) {
    pin = ledPin;
    pinMode(pin, OUTPUT);
    interval = theInterval;
    elapsed = 0;

    fadeAmount = 1;
    brightness = 0;

    timeRemaining = interval;
  }

  void Update(unsigned long dt) {
    timeRemaining -= dt;

    if (timeRemaining < 0) {
      analogWrite(pin, brightness);

      brightness = brightness + fadeAmount;

      if (brightness == 0 || brightness == 255) {
        fadeAmount = -fadeAmount ;
      }

      timeRemaining = interval;
    }
  }
};
