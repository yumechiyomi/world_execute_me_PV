
#ifndef MV_LYRICS_H
#define MV_LYRICS_H

#include "mv.h"


int  lyric_display_line(int t_ms);
int  lyric_line_at(int t_ms);


void lyrics_draw(Frame *f, int t_ms, Rgb base, Rgb accent, int show_progress);


void lyrics_draw_keywords(Frame *f, int t_ms, Rgb accent, Rgb base);


void lyrics_draw_hud(Frame *f, int t_ms, Rgb dim, int show_hud);


const char *lyric_text(int index);
int         lyric_keyword_at(int t_ms, const char **text, double *age);

#endif 