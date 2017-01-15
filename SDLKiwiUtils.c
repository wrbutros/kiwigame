#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"

SDL_Surface * get_SDLSurface(ushort x, ushort y, Uint8 depth, Uint32 flags)
{
  SDL_Surface *screen;
  screen = SDL_SetVideoMode (x, y, depth, flags);
  if (screen == NULL)
    {
      printf ("Error to load Graphics: %s\n",SDL_GetError());
      exit(1);
    }
  return screen;
}

SDL_Surface * get_LoadedBMP (char * name)
{
  SDL_Surface *image;
  image = SDL_LoadBMP (name);
  if (image == NULL)
    {
      printf ("Error to load image: %s\n", SDL_GetError());
      exit(1);
    }
  return image;
}
