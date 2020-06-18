/**
* @file animate.h
*/
#ifndef ANIMATE_H_INCLUDED
#define ANIMATE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/**
* @struct enemie
* @brief struct for enemie
*/
typedef struct{
SDL_Surface *sprite ;
SDL_Rect positionsprite;
int actframe;
int maxframe ;
SDL_Rect frame ;
}enemie ;

/**
* @brief To initialize the enemie e .
* @param e enemie
* @return Nothing
*/
void load_enemi (enemie *e)
{
e->sprite=IMG_Load("aa.png");
e->positionsprite.x=400 ;
e->positionsprite.y=300;
e->actframe=0;
e->maxframe=4;
e->frame.x=0 ;
e->frame.y=0;
e->frame.w = 88 ;
e->frame.h =80 ;

}

void afficher(enemie e,SDL_Surface *background,SDL_Surface *ecran,SDL_Rect position)
{
SDL_BlitSurface (background,NULL,ecran,&position);
SDL_BlitSurface (e.sprite,&e.frame,ecran,&e.positionsprite);

}


void annimation(enemie *e)
{
e->actframe +=1 ;
        SDL_Delay(50);

if ( e->actframe > e->maxframe) 
{
e->actframe =0;
} 
e->frame.x= e->actframe * e->frame.w ;
}




#endif
