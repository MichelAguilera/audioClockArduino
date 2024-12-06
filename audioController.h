
#pragma once
#ifndef _RTC_H
#define _RTC_H
#include "RTC.h"
#endif

#ifndef _AUDIO_C_H
#define _AUDIO_C_H
#include <DFRobotDFPlayerMini.h>
#endif

#define RX 1 // Example RX pin on the R4
#define TX 0 // Example TX pin on the R4

#define FPSerial Serial1

void AUDIOCONTROLLER_setup(DFRobotDFPlayerMini* audio_player);
void AUDIOCONTROLLER_play_time(DFRobotDFPlayerMini* audio_player, RTCTime* _time);