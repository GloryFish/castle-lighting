class Flicker
{
  int pin;
  long timeRemaining;

  public:
  
  Flicker(int ledPin) {
    pin = ledPin;
    pinMode(pin, OUTPUT);
    timeRemaining = 0;         
  }

  void Update(unsigned long dt) {
    timeRemaining -= dt;
    
    if (timeRemaining < 0) {
      analogWrite(pin, random(120, 255));
      timeRemaining = random(10, 30);     
    }
  }
};
