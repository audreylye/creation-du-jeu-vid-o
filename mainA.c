#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "scroll.h"
#include "travailA.c"

//int main ()
int main (int argc, char *argv[])
{

perso p;
int point;

  int v;
  v = vie(&p);
  
  int s;
  s = score(p, point);


//{
    SDL_Surface *ecran = NULL, *joueur = NULL;
    SDL_Rect positionjoueur;
    SDL_Event event;
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Gestion du temps en SDL", NULL);

    joueur = SDL_LoadBMP("joueur.png");
    SDL_SetColorKey(joueur, SDL_SRCCOLORKEY, SDL_MapRGB(joueur->format, 0, 0, 255));

    positionjoueur.x = ecran->w / 2 - joueur->w / 2;
    positionjoueur.y = ecran->h / 2 - joueur->h / 2;

    SDL_EnableKeyRepeat(10, 10);

    while (continuer)
    {
        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > 30) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
        {
            positionjoueur.x++; /* On bouge Zozor */
            tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(joueur, NULL, ecran, &positionjoueur);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(joueur);
    SDL_Quit();

    return EXIT_SUCCESS;
}

//return 0;
//}
  
