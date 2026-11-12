
#ifndef MV_SCENES_H
#define MV_SCENES_H

#include "mv.h"

typedef enum {
    FX_POWERLINE = 0, FX_SHIELD, FX_BLOCKS, FX_DATASTREAM, FX_GLOBE, FX_GRIDWORLD,
    FX_CODE, FX_POINTS, FX_CIRCLE, FX_SINE, FX_INFINITY, FX_WAVE, FX_BLIND,
    FX_SPIN, FX_STARS, FX_TIMELINE, FX_MERGE, FX_TUNNEL, FX_PULSE, FX_HEART,
    FX_SMILE, FX_CAGE, FX_SPRITE, FX_CAT, FX_GOD, FX_GENDER, FX_MORPH, FX_CLOCK,
    FX_CHAIN, FX_TRANCE, FX_VIBRATE, FX_COMPLETE, FX_DISSOLVE, FX_VOID,
    FX_SHATTER, FX_LONELY, FX_ALERT, FX_BUILDUP, FX_EXECSTORM, FX_COUNT,
    FX_FORMULA, FX_HEART_CAGE, FX_OUTRO, FX_END,
    FX_COUNT_ID
} Fx;

typedef struct {
    int         line;        
    int         lead_ms;     
    Fx          fx;
    const char *sprite;      
    Rgb         c1, c2;      
    int         trans;       
    int         trans_ms;
    int         seed;
    int         intensity;   
    float       p1, p2;      
    const char *caption;     
} Scene;

typedef struct {
    Frame      *f;
    const Scene *sc;
    int         t_ms;
    double      t;           
    double      dur;         
    double      prog;        
    double      beat;        
    double      phase;       
    int         w, h;
    uint32_t    rnd;         
} Ctx;

extern const Scene SCENES[];
extern const int   SCENE_COUNT;

void scene_resolve(void);                 
int  scene_start_ms(int idx);
int  scene_end_ms(int idx);
int  scene_at(int t_ms);                  
int  scene_duration_ms(int idx);
void scene_render(Frame *f, int idx, int t_ms);


void scene_render_at(Frame *out, Frame *tmp_new, Frame *tmp_old, int t_ms);

void scene_list(FILE *out);
const char *fx_name(Fx fx);
const char *tr_name(int tr);


void fx_panel(Frame *f, int x, int y, int w, int h, const char *title, Rgb border,
              Rgb title_col);
void fx_scan_dots(Frame *f, Rgb col, double density, int seed);

#endif 