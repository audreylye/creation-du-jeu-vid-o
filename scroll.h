#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
	
	int vi;
	int score;
	
} perso;

bool collisionmapscrolling (int direction,SDL_Rect col,SDL_Surface *collisionMap,SDL_Surface *ecran);
void scroll (SDL_Rect *camera,int direction,SDL_Rect *coll,SDL_Rect positionBack1,SDL_Rect positionBack2,SDL_Surface *collisionMap) ;
void display_scroll(SDL_Surface *screen,SDL_Surface *map,SDL_Rect camera);
void display_scroll2(SDL_Surface *screen,SDL_Surface *map,SDL_Rect camera);
void initialiser_joueur(perso *p);
int vie(perso *p);
int score(perso p , int point);

