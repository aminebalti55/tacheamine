/** 
* @file animate.c
* @brief Testing Program.
* @author amine balti
* @version 0.1
* @date jul 14 ,2020
*
* Testing program for an animation
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "animate.h"

int main (int argc ,char *argv[])
{

SDL_Surface *ecran=NULL;
SDL_Surface *background=NULL;

SDL_Rect position;

position.x=0;
position.y=0;

background= IMG_Load("background.jpg");

int continuer =1 ;
SDL_Event event ;


SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF) ;
SDL_WM_SetCaption("Animation",NULL);

enemie e;

load_enemi (&e);



while(continuer){
SDL_WaitEvent(&event) ;

switch(event.type)
{
case SDL_QUIT :
continuer = 0 ;
break ;

case SDL_KEYDOWN :
switch (event.key.keysym.sym){
case SDLK_ESCAPE :
continuer =0 ;
break;
}
}
afficher(e,background,ecran,position);
annimation(&e);
SDL_Flip(e.sprite);
SDL_Flip(ecran);
}

SDL_FreeSurface(ecran);
SDL_QUIT ;
return 0 ;
}

