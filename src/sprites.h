#ifndef MV_SPRITES_H
#define MV_SPRITES_H


typedef struct {
    const char       *name;
    const char *const *rows;
    int               w;
    int               h;
} MvSprite;

extern const MvSprite MV_SPRITES[];
extern const int MV_SPRITE_COUNT;


const MvSprite *mv_sprite(const char *name);

#endif 
