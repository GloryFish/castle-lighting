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
      // set the brightness of pin 9:
      analogWrite(pin, brightness);
  
      // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;
  
      // reverse the direction of the fading at the ends of the fade:
      if (brightness == 0 || brightness == 255) {
        fadeAmount = -fadeAmount ;
      }

      timeRemaining = interval;      
    }
  }
};
