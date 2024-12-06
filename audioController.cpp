
#include "audioController.h"

void AUDIOCONTROLLER_setup(DFRobotDFPlayerMini* audio_player) {
  FPSerial.begin(9600);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!audio_player->begin(FPSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0);
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  
  audio_player->volume(30);  //Set volume value. From 0 to 30
  audio_player->playMp3Folder(60);  //Play the first mp3
}

void AUDIOCONTROLLER_play_time(DFRobotDFPlayerMini* audio_player, RTCTime* _time) {
  uint8_t audio_player_state = audio_player->readType();
  // auto current_hour = _time->getHour();
  // auto current_minu = _time->getMinutes();

  // int audio_hour = 0;
  // int mode = 0;
  // if (current_hour > 12) {
  //   audio_hour = current_hour - 12;
  //   mode = 62;
  // } else {
  //   audio_hour = current_hour;
  //   mode = 61;
  // }

  audio_player->playMp3Folder(_time->getHour());
  delay(2000);
  audio_player->playMp3Folder(_time->getMinutes());
  delay(2000);
  // audio_player->playMp3Folder(mode);
  // delay(1500);
}
