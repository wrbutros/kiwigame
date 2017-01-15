/*** ================================= **
 **          < ENTITIES >              **
 *** ================================= **/
#include "SDL/SDL.h"
#include "stdutils.h"

// =================
// < SPRITE OBJECT >
// =================
typedef struct SpriteObj_Struct *SpriteObj;


/* - Sprite Object -*/
struct SpriteObj_Struct
{
  // == ATTRIBUTES ==
  SDL_Surface *surface;
  SDL_Rect rect;
  string *sprites;

  // == FUNCTIONS CALLS ==
  SDL_Surface* (*getSurface)       (const void *self);
  void         (*setSurface)       (const void *self, SDL_Surface *value);
  SDL_Rect*    (*getRect)          (const void *self);
  void         (*setRect)          (const void *self, SDL_Rect value);
  void         (*setSprites)       (const void* self, string *sprites);
  void         (*setRectValues)    (const void *self, int x, int y, int w, int h);
  void         (*changeCurrSprite) (const void *self);
};

/* - Sprite Object Functions - */
SDL_Surface* getSurfaceSprite        (const void *self);
void         setSurfaceSprite        (const void *self, SDL_Surface *newSurface);
SDL_Rect*    getRectSprite           (const void *self);
void         setRectSprite           (const void *self, SDL_Rect newRect);
void         setSprites              (const void* self, string *sprites);
void         setRectSpriteValues     (const void *self, int x, int y, int w, int h);
void         changeCurrentSprite     (const void *self);
SpriteObj    newSpriteObj            ();
SpriteObj    newSpriteObjWithSprites (string *sprites, int startIndex);
