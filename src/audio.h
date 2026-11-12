
#ifndef MV_AUDIO_H
#define MV_AUDIO_H

#include <sys/types.h>

typedef struct {
    pid_t       pid;
    int         active;
    const char *player;
} Audio;


char *audio_find_file(const char *argv0, const char *explicit_path);


int  audio_start(Audio *a, const char *path, const char *force_player, int lead_ms,
                 int seek_ms, int quiet);
void audio_stop(Audio *a);

#endif 