/**
 * @file hogwarts.ino
 * @author Jay Roberts <jay@gloryfish.org>
 */

#include "fade.h"
#include "flicker.h"
#include "fire.h"

//  2   Blue      Patronus Ambient
//* 3   Blue      Patronus
//  4   Blue      Castle Ambient 1
//* 5   Blue      Castle Ambient 2
//* 6   Ice Blue  Goblet of Fire
//  7   Blue      Castle Ambient 3
//  8   Blue      Castle Ambient 4
//* 9   Ice Blue  Pensieve
//* 10  Red       Hagrid Hut
//* 11  Red       Great Hall Window
//  12  Green     Cauldron
//  14  White     Torch 1
//  15  White     Torch 2
//  16  White     Torch 3
//  17  White     Torch 4
//  18  White     Car

int leds[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18 };
int ledCount = 16;

Fade patronus(3, 25);
Fade goblet(6, 10);
Fade pensieve(9, 30);
Fire hagrids(10);
Fire greatHall(11);
Flicker cauldron(12);
Flicker torch1(14);
Flicker torch2(15);
Flicker torch3(16);
Flicker torch4(17);

unsigned long previousMillis = millis();

void setup() {
  Serial.begin(9600);

  for (int led = 0; led < ledCount; led++) {
    pinMode(leds[led], OUTPUT);
  }

  startupRoutine();

  // Always on
  digitalWrite(2, HIGH);  // Patronus Ambient
  digitalWrite(4, HIGH);  // Goblet of Fire
  // digitalWrite(5, HIGH);  // Unused
  digitalWrite(7, HIGH);  // Castle Ambient 1
  digitalWrite(8, HIGH);  // Castle Ambient 2
  digitalWrite(18, HIGH); // Car
}

void loop() {
  unsigned long dt = millis() - previousMillis;
  previousMillis = millis();

  patronus.Update(dt);
  goblet.Update(dt);
  pensieve.Update(dt);
  hagrids.Update(dt);
  greatHall.Update(dt);

  cauldron.Update(dt);
  torch1.Update(dt);
  torch2.Update(dt);
  torch3.Update(dt);
  torch4.Update(dt);
}

/**
 * Turns on all LEDs then illuminates each one in sequence. Useful for verifying
 * connected LEDs when setting up the display.
 */
void startupRoutine() {
  // All on for two sec
  for (int led = 0; led < ledCount; led++) {
    digitalWrite(leds[led], HIGH);
  }

  delay(2000);

  // All off
  for (int led = 0; led < ledCount; led++) {
    digitalWrite(leds[led], LOW);
  }

  // Flash each in sequence
  for (int led = 0; led < ledCount; led++) {
    digitalWrite(leds[led], HIGH);
    delay(200);
    digitalWrite(leds[led], LOW);
  }

  // Blink all twice
  for (int led = 0; led < ledCount; led++) {
    digitalWrite(leds[led], HIGH);
  }

  delay(500);

  // All off
  for (int led = 0; led < ledCount; led++) {
    digitalWrite(leds[led], LOW);
  }
}
