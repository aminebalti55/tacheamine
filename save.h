/**
* @file save.h
*/

#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
/**
* @struct personnage
* @brief struct for personnage
*/
typedef struct perso
{
	SDL_Surface *image2;
	SDL_Rect posPlayer;
   	int done ;
   	int right,left,sprint;
  	 int maxspeed;
   	double xVel,yVel,canJump;
   	double v_jump;
   	double gravity ;
	int acc;
	int ianim,ianim_c,timer,maxtimer;
	char playerX[50];
	char animchar[50];
	TTF_Font *textF ;
}perso;

/**
* @struct camera
* @brief struct for camera
*/
typedef struct camera
{
	SDL_Rect posdT;
	SDL_Rect pXR;
	SDL_Rect cXR;
	double FPS;
	int dT;
   double FrmStrt,FrmEnd;
	char DT[50];
	SDL_Rect cam;
	char camX[50];
}camera;

/**
* @struct mini
* @brief struct for a minimap
*/
typedef struct
{

    SDL_Surface* imagemini;
SDL_Rect posmini;
SDL_Surface* imagenokta;
SDL_Rect posnokta;

}mini;
FILE* f=NULL;

typedef struct{
SDL_Surface *sprite ;
SDL_Rect positionsprite;
int actframe;
int maxframe ;
SDL_Rect frame ;
}enemie ;


 void quitscreen(camera c,perso p,mini m, ,enemie e,SDL_Surface *screen,SDL_Surface* bg )
{

	SDL_Surface* background=IMG_Load("background.jpg");
	SDL_Surface* quit=IMG_Load("quit.png");
	SDL_Surface* yes=IMG_Load("yes.png");
	SDL_Surface* no=IMG_Load("no.png");
	SDL_Surface* yes2=IMG_Load("yes2.png");
	SDL_Surface* no2=IMG_Load("no2.png");
	SDL_Rect posquit,posyes,posno,posyes2,posno2,posback;
				posback.x=0
				posback.y=0
				posquit.x=100;
				posquit.y=100;
				posyes.x=140;
                posyes.y=220;
                posno.x=300;
                posno.y=220;
                posyes2.x=200;
                posyes2.y=200;
                posno2.x=300;
                posno2.y=200;


	int continuer=1;
	SDL_Flip(screen);
	SDL_Event event;
	
	SDL_Event event;
	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
					case SDL_KEYDOWN :
					{
      if(event.key.keysym.sym==SDLK_ESCAPE)
        {

            SDL_BlitSurface (quit,NULL,screen,&posquit);
            SDL_BlitSurface (yes,NULL,screen,&posyes);
            SDL_BlitSurface (no,NULL,screen,&posno);}}
					break ;
	case SDL_MOUSEMOTION : 
			{
				if(event.motion.x>205 && event.motion.x<540 && event.motion.y>200 && event.motion.y<230)
				{
           				 SDL_BlitSurface (background,NULL,screen,&posback);
           				 SDL_BlitSurface (quit,NULL,screen,&posquit);
            				SDL_BlitSurface (yes2,NULL,screen,&posyes2);
					SDL_Flip(screen);
				}
				else if(event.motion.x>450 && event.motion.x<600 && event.motion.y>220 && event.motion.y<264)
				{
					
           				 SDL_BlitSurface (background,NULL,screen,&posback);
           				 SDL_BlitSurface (quit,NULL,screen,&posquit);
            				SDL_BlitSurface (no2,NULL,screen,&posno2);
					SDL_Flip(screen);
				}
				break ;
				}
				
				case SDL_MOUSEBUTTONDOWN :
				{
				if(event.button.x>205 && event.button.x<540 && event.button.y>200 && event.button.y<230)
				{
					f=fopen("savedgame.txt","w");
					fprintf(f,"%d %d %d %d %d %d 		\n",p.posPlayer.x,p.posPlayer.y,c.cam.x,c.cam.y,m.posnokta.x,m.posnokta.y);
					fclose(f);
					continuer=0;
				}
				}

			
				else if(event.button.x>450 && event.button.x<600 && event.button.y>220 && event.button.y<264)
				{
					continuer=0;
					
				}}}}
				
				void loadgame(perso p,camera c,mini m,enemie e){

				f=fopen("savedgame.txt","r");
					fscanf(f,"%d %d %d %d %d %d %d %d ",&p.posPlayer.x,&p.posPlayer.y,&c.cam.x,&c.cam.y,&m.posnokta.x,&m.posnokta.x);
					fclose(f);

				}

				
				
	
