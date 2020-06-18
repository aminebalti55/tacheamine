/** 
* @file minimap.c
* @brief Testing Program.
* @author amine balti
* @version 0.1
* @date jul 14 ,2020
*
* Testing program for a minimap
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
int main (int argc ,char *argv[])
{

SDL_Surface *ecran=NULL;
SDL_Surface *background=NULL;

SDL_Rect position;

position.x=0;
position.y=0;

background= IMG_Load("background.jpg");

int done =1 ;
SDL_Event event ;


SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF) ;
SDL_WM_SetCaption("minimap",NULL);
barrier b;
mini M ;
perso p ;
map (&M,&p,&b);

while(done){
SDL_WaitEvent(&event) ;

switch(event.type)
{
case SDL_QUIT :
done = 0 ;
break ;

case SDL_KEYDOWN :
switch (event.key.keysym.sym){
case SDLK_ESCAPE :
done =0 ;
break;
}
}



deplacer (&p,ecran,&M,background,position,&b);
SDL_Flip (M.imagemini);
SDL_Flip (M.imagenokta);
SDL_Flip(p.personnage);
SDL_Flip(background);
SDL_Flip(ecran);
}
SDL_FreeSurface(p.personnage);
SDL_FreeSurface(ecran);
SDL_QUIT ;
return 0 ;
}

