/** 
* @file save file
* @brief test the ability to save game progress
* @author amine balti
* @version 0.1
* @date jul 15 ,2020
*
* Testing program for a save game
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "save.h"

int main (int argc ,char *argv[])
{

SDL_Surface *screen=NULL;
SDL_Surface *bg=NULL;

perso p;
camera c;
mini m;
FILE* f=NULL;


int continuer =1 ;
SDL_Event event ;


SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF) ;
SDL_WM_SetCaption("save",NULL);


SDL_Event event ;
while(continuer){
SDL_WaitEvent(&event) ;

switch(event.type)
{
case SDL_QUIT :
continuer = 0 ;
break ;

case SDL_KEYDOWN :
switch (event.key.keysym.sym){
case SDLK_UP :
continuer =0 ;
break;
}
}
quitscreen(c,p,m,&screen,&bg );
loadgame(p,c,m)
SDL_Flip(screen);
}

SDL_FreeSurface(screen);
SDL_QUIT ;
return 0 ;
}


