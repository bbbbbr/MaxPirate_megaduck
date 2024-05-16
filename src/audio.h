#ifndef __AUDIO_H__
#define __AUDIO_H__

void initAudio(void);

void muteAudio(void);

void unmuteAudio(void);

void updateAudio(void);

void disableAudio(void);

#define AUDTERM_ALL_LEFT  (AUDTERM_4_LEFT | AUDTERM_3_LEFT | AUDTERM_2_LEFT | AUDTERM_1_LEFT)
#define AUDTERM_ALL_RIGHT (AUDTERM_4_RIGHT | AUDTERM_3_RIGHT | AUDTERM_2_RIGHT | AUDTERM_1_RIGHT)

#endif