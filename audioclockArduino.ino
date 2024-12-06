/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

#ifndef _SEV_SEG_H
#define _SEV_SEG_H
#include <Simple5641AS.h>
#endif  //_SEV_SEG_H

#ifndef _AUDIO_C_H
#define _AUDIO_C_H
#include <DFRobotDFPlayerMini.h>
#endif

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#define BUTTON_PIN A5

#include "audioController.h"
#include "displayController.h"

#define TIME_INTERVAL_MILLIS 1000

// SETUP AUDIO
DFRobotDFPlayerMini audio_player;
RTCTime currentTime;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);

  currentTime = initializeTimeDisplay();
  AUDIOCONTROLLER_setup(&audio_player);
}

void loop() {
  RTC.getTime(currentTime);
  updateDisplay(&currentTime);

    // Check for button input
  int buttonState = analogRead(BUTTON_PIN); // Read the analog value
  Serial.println(buttonState);
  if (buttonState > 512) { // Adjust threshold as needed
    // Button pressed, play audio
    Serial.println("Button pressed, playing audio...");
    AUDIOCONTROLLER_play_time(&audio_player, &currentTime);
  }

  delay(10); // Add a short delay for button debounce
}