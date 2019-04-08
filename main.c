#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
#include "animate.c"
#include "enig.h"
#include "scroll.h"
#include "sous.h"
#include "collision.h"

int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}

int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}


void UpdateEvents(Input* in);

int main(int argc, char *argv[])

{
//debut
    if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :

    {

        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur

        exit(EXIT_FAILURE); // On quitte le programme

    }
TTF_Init();
 	    int continuer = 1, reception = 0,TA=0,TA2=0,direction = 0,direction1 = 0, i,map=1,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
TTF_Font *police = NULL;
     SDL_Color noire={100,0,0};
    SDL_Event event;
	char v[50], temps[20], temps2[20];
	Input in;
	memset(&in,0,sizeof(in));
	perso p,p2;
	SDL_Surface *background = NULL,*background2 = NULL;
SDL_Surface *collisionMap = NULL,*collisionMap2 = NULL, *vies[11], *time=NULL, *time2=NULL;
SDL_Surface *joueur = NULL,*joueur1 = NULL;
	SDL_Surface *ecran = NULL;
	SDL_Rect camera,camera2;
    p.image = IMG_Load("joueur.png");
    p2.image = IMG_Load("joueur.png");
    joueur1 = IMG_Load("joueur1.png");
    collisionMap =SDL_LoadBMP("i1.bmp");
    collisionMap2 =SDL_LoadBMP("i1.bmp");
	police = TTF_OpenFont("de.ttf",20);
	SDL_Color blanc={255,255,255};
	SDL_Rect positionBack,positionBack2;
	SDL_Rect positionT;
	SDL_Rect coll,coll2;
	SDL_Rect col,col2;
	SDL_Rect coll1,coll12;
	ecran = SDL_SetVideoMode(1200,720,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_RESIZABLE );
	 system("stty -F /dev/ttyUSB0 9600 -parenb cs8 -cstopb");
	for(i=0;i<6;i++)
	{
		sprintf(v,"vie/%d.png",i);
		vies[i]=IMG_Load(v);
	}
	Mix_Music *musique;
	background = SDL_LoadBMP("i2.bmp");
	background2 = SDL_LoadBMP("i2.bmp");
	positionBack.x = 0;
	positionBack.y = 0;
	positionBack2.x = 600;
	positionBack2.y = 0;
	coll.x=350;
	coll.y=400;
	col.x=350;
	col.y=1830;
	coll2.x=950;
	coll2.y=400;
	col2.x=350;
	col2.y=1830;
	coll1.x=400;
	coll1.y=0;
	coll12.x=1000;
	coll12.y=0;
	camera.x = 0;
        camera.y = 1430;
	camera.w = 595;
        camera.h = 720;
	camera2.x = 0;
        camera2.y = 1430;
	camera2.w = 600;
        camera2.h = 720;
	initialiser_joueur(&p);
	initialiser_joueur(&p2);
		 musique = Mix_LoadMUS("jeu.mp3");
     Mix_PlayMusic(musique, -1);
	Mix_VolumeMusic(30);
	//SDL_BlitSurface(collisionMap, NULL, ecran, &positionBack);
	SDL_BlitSurface(background, &coll1, ecran, &positionBack);
	SDL_BlitSurface(vies[p.vi], NULL, ecran, &positionBack);
	SDL_BlitSurface(vies[p2.vi], NULL, ecran, &positionBack2);
	SDL_BlitSurface(p.image, NULL, ecran, &coll);
	SDL_BlitSurface(p.image, NULL, ecran, &col);
	SDL_BlitSurface(p2.image, NULL, ecran, &coll2);
	SDL_BlitSurface(p2.image, NULL, ecran, &col2);
	//SDL_BlitSurface(joueur1, NULL, ecran, &coll1);
	
	SDL_Flip(ecran);
	SDL_EnableKeyRepeat(10,10);
	while (!in.key[SDLK_ESCAPE])
{
	UpdateEvents(&in);

    
	sprintf(temps,"TIME : %d",SDL_GetTicks());
	time = TTF_RenderText_Blended(police,temps,noire);
	if(SDL_GetTicks() - TA>60000)
{
	TA=SDL_GetTicks();
	vie(&p);
}	
	sprintf(temps2,"TIME : %d",SDL_GetTicks());
	time2 = TTF_RenderText_Blended(police,temps,noire);
	if(SDL_GetTicks() - TA2>60000)
{
	TA2=SDL_GetTicks();
	vie(&p2);
}
       
arduinoReadData(&reception);
	    
 if(in.key[SDLK_RETURN])
sousmenu(ecran);

	 if(in.key[SDLK_UP] || reception == 1) 
	{
		
		if(collisionmap(1,col,collisionMap,ecran))
{
		
}
		else if(collisionmapscrolling(1,col,collisionMap,ecran))
{		if(map==1)
{
	map=2;
		if(col.x<1000)
		{
			col.x=1528;
			col.y=591;
			coll.x=328;
			coll.y=351;
			camera.x = 1200;
        		camera.y = 240;
			
			collisionMap =SDL_LoadBMP("i3.bmp");
			background = SDL_LoadBMP("i4.bmp");
		}
		else
		{
			col.x=536;
			col.y=1024;
			coll.x=336;
			coll.y=324;
			camera.x = 200;
        		camera.y = 700;
			collisionMap =SDL_LoadBMP("i3.bmp");
			background = SDL_LoadBMP("i4.bmp");
		}
		}
		else
{
	map=1;
		if(col.x<1000)
		{
			col.x=1564;
			col.y=780;
			coll.x=364;
			coll.y=330;
			camera.x = 1200;
        		camera.y = 450;
			
			collisionMap =SDL_LoadBMP("i1.bmp");
			background = SDL_LoadBMP("i2.bmp");
		}
		else
		{
			col.x=568;
			col.y=964;
			coll.x=368;
			coll.y=314;
			camera.x = 200;
        		camera.y = 650;
			collisionMap =SDL_LoadBMP("i1.bmp");
			background = SDL_LoadBMP("i2.bmp");
		}
}
memset(&in,0,sizeof(in));
}
	
	    else if(collisionenigme(1,col,collisionMap,ecran))
{

	if(enigmeh(ecran))
	{
		if(col.x>1375)
		{
			col.x=1300;
			col.y=750;
			coll.x=300;
			coll.y=350;
			camera.x = 1000;
        		camera.y = 400;
		}
		else
		{
			col.x=1425;
			col.y=750;
			coll.x=300;
			coll.y=350;
			camera.x = 1125;
        		camera.y = 400;
		}
memset(&in,0,sizeof(in));
	}
	else
	vie(&p);
}
		else
{
	coll.x+=0;
	coll.y+= -10;
	col.x+=0;
	col.y+= -10;
if(collision(&coll,&coll1))
	{coll.x+=0;
	coll.y+= 10;
	col.x+=0;
	col.y+= 10;
	vie(&p);}
	else
{
		scroll(&camera,1,&coll,positionBack,positionBack2,background);
		animate_up(&p);
}
}


	}
	if(in.key[SDLK_DOWN] || reception == 2) 
		{
		
		if(collisionmap(2,col,collisionMap,ecran))
{
		
}
		else
{
	coll.x+=0;
	coll.y+= 10;
	col.x+=0;
	col.y+= 10;
if(collision(&coll,&coll1))
	{coll.x+=0;
	coll.y+= -10;
	col.x+=0;
	col.y+= -10;
	vie(&p);}
	else
{
	scroll(&camera,2,&coll,positionBack,positionBack2,background);
	animate_down(&p);
}	
}
	}
	if(in.key[SDLK_LEFT] || reception == 3) 
	{
		
		if(collisionmap(3,col,collisionMap,ecran))
{
		
}
		else
{
	coll.x+= -10;
	coll.y+= 0;
	col.x+= -10;
	col.y+= 0;
if(collision(&coll,&coll1))
	{coll.x+= 10;
	coll.y+= 0;
	col.x+= 10;
	col.y+= 0;
	vie(&p);}
	else
{
	scroll(&camera,3,&coll,positionBack,positionBack2,background);
	animate_left(&p);
}
}		
	}
	if(in.key[SDLK_RIGHT] || reception == 4) 
	{
		
		
		if(collisionmap(4,col,collisionMap,ecran))
{
		
}
		else
{
	coll.x+= 10;
	coll.y+= 0;
	col.x+= 10;
	col.y+= 0;
	if(collision(&coll,&coll1))
	{coll.x+= -10;
	coll.y+= 0;
	col.x+= -10;
	col.y+= 0;
	vie(&p);}
	else
{
	scroll(&camera,4,&coll,positionBack,positionBack2,background);
	animate_right(&p);
}
}	
}

 if(in.key[SDLK_KP8]) 
	{
		
		if(collisionmap(1,col2,collisionMap2,ecran))
{
		
}
		else if(collisionmapscrolling(1,col2,collisionMap2,ecran))
{		if(map==1)
{
	map=2;
		if(col2.x<1000)
		{
			col2.x=1528;
			col2.y=591;
			coll2.x=928;
			coll2.y=351;
			camera2.x = 1200;
        		camera2.y = 240;
			
			collisionMap2 =SDL_LoadBMP("i3.bmp");
			background2 = SDL_LoadBMP("i4.bmp");
		}
		else
		{
			col2.x=536;
			col2.y=1024;
			coll2.x=936;
			coll2.y=324;
			camera2.x = 200;
        		camera2.y = 700;
			collisionMap2 =SDL_LoadBMP("i3.bmp");
			background2 = SDL_LoadBMP("i4.bmp");
		}
		}
		else
{
	map=1;
		if(col2.x<1000)
		{
			col2.x=1564;
			col2.y=780;
			coll2.x=964;
			coll2.y=330;
			camera2.x = 1200;
        		camera2.y = 450;
			
			collisionMap2 =SDL_LoadBMP("i1.bmp");
			background2 = SDL_LoadBMP("i2.bmp");
		}
		else
		{
			col2.x=568;
			col2.y=964;
			coll2.x=968;
			coll2.y=314;
			camera2.x = 200;
        		camera2.y = 650;
			collisionMap2 =SDL_LoadBMP("i1.bmp");
			background2 = SDL_LoadBMP("i2.bmp");
		}
}
memset(&in,0,sizeof(in));
}
	
	    else if(collisionenigme(1,col2,collisionMap2,ecran))
{
	if(enigmeh(ecran))
	{
		if(col2.x>1375)
		{
			col2.x=1300;
			col2.y=750;
			coll2.x=900;
			coll2.y=350;
			camera2.x = 1000;
        		camera2.y = 400;
		}
		else
		{
			col2.x=1425;
			col2.y=750;
			coll2.x=900;
			coll2.y=350;
			camera2.x = 1125;
        		camera2.y = 400;
		}
memset(&in,0,sizeof(in));
	}
	else
	vie(&p2);
}
		else
{
	coll2.x+=0;
	coll2.y+= -10;
	col2.x+=0;
	col2.y+= -10;
if(collision(&coll2,&coll1))
	{coll2.x+=0;
	coll2.y+= 10;
	col2.x+=0;
	col2.y+= 10;
	vie(&p2);}
	else
{
		scroll(&camera2,1,&coll2,positionBack2,positionBack,background2);
		animate_up(&p2);
}
}


	}
	 if(in.key[SDLK_KP2]) 
		{
		
		if(collisionmap(2,col2,collisionMap2,ecran))
{
		
}
		else
{
	coll2.x+=0;
	coll2.y+= 10;
	col2.x+=0;
	col2.y+= 10;
if(collision(&coll2,&coll1))
	{coll2.x+=0;
	coll2.y+= -10;
	col2.x+=0;
	col2.y+= -10;
	vie(&p2);}
	else
{
	scroll(&camera2,2,&coll2,positionBack2,positionBack,background2);
	animate_down(&p2);
}	
}
	}
	 if(in.key[SDLK_KP4]) 
	{
		
		if(collisionmap(3,col2,collisionMap2,ecran))
{
		
}
		else
{
	coll2.x+= -10;
	coll2.y+= 0;
	col2.x+= -10;
	col2.y+= 0;
if(collision(&coll2,&coll1))
	{coll2.x+= 10;
	coll2.y+= 0;
	col2.x+= 10;
	col2.y+= 0;
	vie(&p2);}
	else
{
	scroll(&camera2,3,&coll2,positionBack2,positionBack,background2);
	animate_left(&p2);
}
}		
	}
	 if(in.key[SDLK_KP6]) 
	{
		
		
		if(collisionmap(4,col2,collisionMap2,ecran))
{
		
}
		else
{
	coll2.x+= 10;
	coll2.y+= 0;
	col2.x+= 10;
	col2.y+= 0;
	if(collision(&coll2,&coll1))
	{coll2.x+= -10;
	coll2.y+= 0;
	col2.x+= -10;
	col2.y+= 0;
	vie(&p2);}
	else
{
	scroll(&camera2,4,&coll2,positionBack2,positionBack,background2);
	animate_right(&p2);
}
}	
}

	
	
	display_scroll(ecran,background,camera);
	display_scroll2(ecran,background2,camera2);
	SDL_BlitSurface(vies[p.vi], NULL, ecran, &positionBack);
	SDL_BlitSurface(vies[p2.vi], NULL, ecran, &positionBack2);
	Display_perso (p,coll,ecran);
	Display_perso (p2,coll2,ecran);
	//SDL_BlitSurface(joueur1, &camera, ecran, &coll1);
	SDL_BlitSurface(time, NULL, ecran, &coll1);
	SDL_BlitSurface(time2, NULL, ecran, &coll12);
	SDL_Flip(ecran);
    }
	
 
    SDL_FreeSurface(background);
    SDL_FreeSurface(collisionMap);
SDL_FreeSurface(p.image);
SDL_FreeSurface(time);


    TTF_Quit();
    SDL_Quit();

 
    return EXIT_SUCCESS;

}



void UpdateEvents(Input* in)

{

    SDL_Event event;

    while(SDL_PollEvent(&event))

    {

        switch (event.type)

        {

        case SDL_KEYDOWN:

            in->key[event.key.keysym.sym]=1;

            break;

        case SDL_KEYUP:

            in->key[event.key.keysym.sym]=0;

            break;

        default:

            break;

        }

    }

}


