#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>





typedef struct
{
   
    SDL_Surface* imagemini;
SDL_Rect posmini;
SDL_Surface* imagenokta;
SDL_Rect posnokta;

}mini;


typedef struct
{
SDL_Surface *personnage;
SDL_Rect posperso;
}perso;

typedef struct 
{ SDL_Surface *ligne ;
SDL_Rect posligne1,posligne2 ;
} barrier ;
void map (mini *M,perso *p,barrier *b)
{
b->ligne=IMG_Load("ligne.png");
b->posligne1.x=120 ;
b->posligne1.y=20;
b->posligne1.w=3;
b->posligne1.h=80;
b->posligne2.x=620;
b->posligne2.y=20;
b->posligne2.w=3;
b->posligne2.h=80;
M->imagemini=IMG_Load("mini.png");
M->imagenokta=IMG_Load("nokta.png");
M->posmini.x=120;
M->posmini.y=20;
M->posnokta.x=168;
M->posnokta.y=78;
M->posnokta.w=5;
M->posnokta.h=5;
p->personnage=IMG_Load("pac.png");
p->posperso.x =180 ;
p->posperso.y=250 ;

}


void deplacer (perso *p,SDL_Surface *ecran,mini *M,SDL_Surface *background,SDL_Rect position,barrier *b){
//int collisionRightSide = 0;
//int collisionLeftSide = 0;



SDL_EnableKeyRepeat(20,20);
int continuer =1;
SDL_Event event ;

while (continuer)
{
SDL_PollEvent(&event);
switch (event.type)
{
case SDL_KEYDOWN :
switch (event.key.keysym.sym)
{ case SDLK_UP :
p->posperso.y-=10 ;
SDL_WaitEvent(&event);
break ;
case SDLK_DOWN :
p->posperso.y+=10 ;
SDL_WaitEvent(&event);
break ;
case SDLK_RIGHT :
p->posperso.x+=10 ;
SDL_WaitEvent(&event);
M->posnokta.x+=2;
break;
case SDLK_LEFT :
p->posperso.x-=10 ;
SDL_WaitEvent(&event);
M->posnokta.x-=2;
break ;


break ;
//if(M->posnokta.x + M->posnokta.w< b->posligne1.x)
                //collisionRightSide=0;
           // else
           //     collisionRightSide=1;
            //if(M->posnokta.x > b->posligne2.x + b->posligne2.w)
               // collisionLeftSide=0;
            //else
              //  collisionLeftSide=1;




}}
SDL_BlitSurface (background,NULL,ecran,&position);
SDL_BlitSurface (p->personnage,NULL,ecran,&p->posperso);
SDL_BlitSurface(M->imagemini,NULL,ecran,&M->posmini);
SDL_BlitSurface(b->ligne,NULL,ecran,&b->posligne1);
SDL_BlitSurface(b->ligne,NULL,ecran,&b->posligne2);
SDL_BlitSurface(M->imagenokta,NULL,ecran,&M->posnokta);
SDL_Flip(ecran) ;
SDL_Flip(p->personnage) ;
SDL_Flip(M->imagemini) ;
SDL_Flip(M->imagenokta);
}

}



#endif // MINIMAP_H_INCLUDED
