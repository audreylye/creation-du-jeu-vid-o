#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>



/*void initialiser_joueur(perso *p)
{
	
	p->vi = 5;
	
	
}*/

int vie(perso *p)
{
	p->vi--;
  // vieImage(0.png,1.png,2.png,3.png,4.png,5.png, 480, 410);

return p->vi;
}
 
int score(perso p , int point)
{
int pomme,fleur,aimant;
 if(p.score = pomme)
 {
   point = 20;
 }

 else 
   if(p.score  = fleur)
    {
      point = -15;
    }
  else
     if(p.score  = aimant)
      {
       point = 50;
      }
return point;
}     



/*int main(int argc, char *argv[])
{
perso p;
    
    p.vi = 5;
    p.score = 0;
    int point = 0 ;
    
        switch(a)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            case SDL_vie:
                 initialiser_joueur(&p);
            case SDL_score:
                 score(p , point);
        }
	    
    return EXIT_SUCCESS;
}*/
