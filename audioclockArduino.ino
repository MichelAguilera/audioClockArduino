/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

#define RX 1 // Example RX pin on the R4
#define TX 0 // Example TX pin on the R4

#define FPSerial Serial1

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

#define TIME_INTERVAL_MILLIS 1000

// SoftwareSerial FPSerial(/*rx =*/10, /*tx =*/11);

// SETUP SEVEN SEGMENT DISPLAY
//            segmentPins[] = { a, b, c, d, e, f, g, dot };
const uint8_t segmentPins[] = { 4, 6, 3, 10, 9, 2, 5, 13 };
//            digitSelectionPins[] = { D1, D2, D3, D4 };
const uint8_t digitSelectionPins[] = { 12, 11, 8, 7 };
Simple5641AS sevseg(segmentPins, digitSelectionPins);

// SETUP CONTROLLER STATE
// CONTROLLER_State controller_state;

// SETUP AUDIO
DFRobotDFPlayerMini audio_player;

void setup() {
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  FPSerial.begin(9600);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!audio_player.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0);
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  
  audio_player.volume(30);  //Set volume value. From 0 to 30
  audio_player.play(1);  //Play the first mp3

  // CONTROLLER_Time start_time = { 0, 0 };
  // CONTROLLER_set_time(&controller_state, start_time);
}
/*
void blink() {
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  // wait for a second
  delay(1000);
}

void print_time(CONTROLLER_Time time) {
  String time_str = "00:00";
  time_str.setCharAt(0, '0' + (time.ct_hour / 10) % 2);
  time_str.setCharAt(1, '0' + (time.ct_hour % 10));
  time_str.setCharAt(3, '0' + (time.ct_minutes / 10) % 6);
  time_str.setCharAt(4, '0' + (time.ct_minutes % 10));

  Serial.println("TIME " + time_str);
}

CONTROLLER_Time parse_time(unsigned long current_time_stamp, CONTROLLER_Time *old_time) {
  int secs = current_time_stamp / 1000;
  int mins = secs / 60;

  CONTROLLER_Time out_time = { 0, 0 };

  unsigned long minutes = current_time_stamp / (1000 * 60);
  out_time.ct_minutes = (short)(old_time->ct_minutes + minutes % 60);
  out_time.ct_hour = (short)((old_time->ct_hour + (old_time->ct_minutes + minutes / 60)) % 24);

  return out_time;
}
*/

unsigned long play_time() {

}

unsigned long previous_time_stamp = millis();
void loop() {
  unsigned long current_time_stamp = millis();

  audio_player.next();
  delay(2000);

  if (current_time_stamp - previous_time_stamp >= TIME_INTERVAL_MILLIS) {

    // CONTROLLER_Time state_time = CONTROLLER_get_time(&controller_state);
    // CONTROLLER_Time parsed_time = parse_time(current_time_stamp, &state_time);

    // print_time(parsed_time);
    //sevseg.displayNumber(1, out_time, 2);


    // CONTROLLER_set_time(new_time);
    // CONTROLLER_display_time(const CONTROLLER_Time *current_time, Simple5641AS *sevseg);

    previous_time_stamp = current_time_stamp;
  }
}