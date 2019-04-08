#include<SDL/SDL.h>
#include<SDL/SDL_image.h>

typedef struct 
{
	SDL_Surface *img[4];
	SDL_Rect pos;
	int direction; //0 : a droite,  1: a gauche

}Perso;



void deplacer_ennemi (Perso *ennemi, int min, int max)
{
	 
	if (ennemi->pos.x >= max )
		ennemi->direction = 0;
		
	if ( ennemi->pos.x <= min )
		ennemi->direction = 1;
		
	if ( ennemi->direction == 1)
		ennemi->pos.x += 5;
	if (ennemi->direction == 0)
		ennemi->pos.x -= 5;
			
}

void afficher_ennemi (Perso *ennemi, SDL_Surface *ecran)
{
	SDL_Delay(20);
	SDL_BlitSurface (ennemi->img[0], NULL, ecran, &ennemi->pos);
}


int main(int argc, char *argv[])
{
	SDL_Surface *ecran = NULL, *back=NULL;
	Perso ennemi;
	SDL_Rect posBack;
	SDL_Event event;
	int min=0, max = 200;	
	
	SDL_Init (SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode (800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	back=IMG_Load ("back.jpg");
	ennemi.img[0] = IMG_Load("Alien.png");
	if(ennemi.img[0]==NULL)
		exit(EXIT_FAILURE);
	
	
	posBack.x=0;
	posBack.y=0;
	
	ennemi.pos.x=150;
	ennemi.pos.y=150;
	ennemi.direction = 1;
	
	while (event.type != SDL_QUIT)
	{	SDL_PollEvent(&event);
		
		//affichage
		SDL_BlitSurface (back, NULL, ecran, &posBack);
		deplacer_ennemi (&ennemi, min, max);	
		afficher_ennemi (&ennemi, ecran);
		SDL_Flip(ecran);
		
		//gestion des evenements...
		
	}	
		
SDL_FreeSurface(ennemi.img[0]);
SDL_FreeSurface(back);
SDL_FreeSurface(ecran);		
SDL_Quit();
}




