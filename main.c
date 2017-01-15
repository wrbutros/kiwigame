#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "SDL/SDL.h"
#include "SDLKiwiUtils.h"
#include "entities.h"



void key_event_action (Uint8 *keys, SpriteObj player)
{
  if (keys[SDLK_UP] && player->getRect(player)->y > 0)
    player->getRect(player)->y -= 2;

  if (keys[SDLK_DOWN] &&
      player->getRect(player)->y < 600-player->getRect(player)->h)
    player->getRect(player)->y += 2;

  if (keys[SDLK_LEFT] && player->getRect(player)->x > 0)
    player->getRect(player)->x -= 2;

  if (keys[SDLK_RIGHT] &&
      player->getRect(player)->x < 800-player->getRect(player)->w)
    player->getRect(player)->x += 2;

  //Each movement over player change the sprite to animate it
  if (keys[SDLK_LEFT] || keys[SDLK_RIGHT] ||
      keys[SDLK_UP]   || keys[SDLK_DOWN]   )

    //playerSprt = get_LoadedBMP ( (cambio1 ^= true) ?
    //"turtle1.bmp" : "turtle2.bmp");
    player->changeCurrSprite(player);

}


int main(int argc, char *argv[])
{

  SDL_Surface *screen; //Main Surface
  SpriteObj player;      //Player Sprite
  //string sprites[] =  {"turtle1.bmp","turtle.bmp","turtle2.bmp"};

  //TODO: Get sprites name dynamicly with guile
  string *sprites = malloc(sizeof(string)*3);
  sprites[0] = "turtle1.bmp";
  sprites[1] = "turtle.bmp";
  sprites[2] = "turtle2.bmp";

  player = newSpriteObjWithSprites(sprites, 1);

  SDL_Rect currPlayerPos; //Current Player Rectangle Sprite

  SDL_Event event;
  int done = 0;
  Uint8 *keys;
  _Bool cambio1 = false;

  //Call SDL_Quit when this app ends.
  atexit(SDL_Quit);

  //Starting SubSystems
  if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO)<0)
    {
      printf ("Its not possible start SDL: %s\n",SDL_GetError());
      return 1;
    }

  screen = get_SDLSurface (800,600,24, SDL_HWSURFACE);
  //player->setSurface(player, get_LoadedBMP ("turtle.bmp"));

  player->setRectValues(player, 100, 100,
                        player->getSurface(player)->w,
                        player->getSurface(player)->h);

  SDL_BlitSurface (player->getSurface(player), NULL, screen,
                   player->getRect(player));

  SDL_Flip(screen);
  //SDL_FreeSurface(playerSprt);


  while (done == 0)
    {
      //Getting keyboard status
      keys = SDL_GetKeyState(NULL);

      currPlayerPos = *(player->getRect(player));

      //Re-Draw player
      SDL_FillRect (screen, &currPlayerPos, SDL_MapRGB(screen->format, 0,0,0));

      //Key events
      key_event_action (keys, player);

      //Drawing full frame
      SDL_BlitSurface (player->getSurface(player), NULL, screen,
                       player->getRect(player));

      //Split the full frame on screen
      SDL_Flip(screen);

      SDL_Delay(60);
      while (SDL_PollEvent(&event))
        {
          if(event.type == SDL_KEYDOWN)
            if(event.key.keysym.sym == SDLK_ESCAPE)
              done = 1;
        }
    }

  return 0;
}
