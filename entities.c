#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "SDL/SDL.h"
#include "SDLKiwiUtils.h"
#include "entities.h"
#include "stdutils.h"


// ======================
//   < SPRITE OBJECT >
// ======================

SpriteObj newSpriteObj()
{
  SpriteObj self = (SpriteObj)malloc(sizeof(struct SpriteObj_Struct));


  //Se asignan las funciones a los atributos de la estructura
  self->getSurface       = &getSurfaceSprite;
  self->setSurface       = &setSurfaceSprite;
  self->getRect          = &getRectSprite;
  self->setRect          = &setRectSprite;
  self->setSprites       = &setSprites;
  self->setRectValues    = &setRectSpriteValues;
  self->changeCurrSprite = &changeCurrentSprite;

  //Se inicializa el Sprite como vacío
  self->setSurface (self, NULL);
  //self->sprites = (string*)malloc(sizeof(char *)*6);

  return self;
}


SpriteObj newSpriteObjWithSprites (string *sprites, int startIndex)
{
  SpriteObj self = newSpriteObj();
  self->setSprites(self, sprites);
  self->setSurface(self, get_LoadedBMP (sprites[startIndex]));
  return self;
}

SDL_Surface* getSurfaceSprite(const void *self)
{
  return ((SpriteObj)self)->surface;
}

void setSurfaceSprite (const void *self, SDL_Surface *newSurface)
{
  ((SpriteObj)self)->surface = newSurface;
}

SDL_Rect* getRectSprite (const void* self)
{
  return &((SpriteObj)self)->rect;
}

void setRectSprite (const void* self, SDL_Rect newRect)
{
  ((SpriteObj)self)->rect = newRect;
}

void setSprites (const void* self, string *sprites)
{
  ((SpriteObj)self)->sprites = sprites;
}

void setRectSpriteValues (const void* self, int x, int y, int w, int h)
{
  ((SpriteObj)self)->rect.x = x;
  ((SpriteObj)self)->rect.y = y;
  ((SpriteObj)self)->rect.w = w;
  ((SpriteObj)self)->rect.h = h;
}

void changeCurrentSprite (const void *self)
{
  static int index = 0;
  static _Bool ida = true;
  SDL_Surface *newSurface;

  string *sprites = ((SpriteObj)self)->sprites;

  newSurface = get_LoadedBMP(sprites[index]);
  ida ? index++ : index--;

  if (ida==false && index==0) ida=true;
  else if (ida==true && index==getLenAllocArrStr(sprites)-1) ida=false;

  ((SpriteObj)self)->setSurface(self, newSurface);
}
