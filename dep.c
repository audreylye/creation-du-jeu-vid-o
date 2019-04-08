#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>



int main (int argc , char **argv)
{

int i=21,k,j=1,l=24,m=54;

char perso[44];
SDL_Surface *perso_anime[67];


SDL_Surface *ecran = NULL ;
SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(554,698,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
SDL_WM_SetCaption("deplacement perso", NULL);

SDL_Surface *personnage=NULL;
SDL_Rect positionperso;
positionperso.x=0;
positionperso.y=300;
 

SDL_Surface *bg=NULL;
SDL_Rect positionbg;
positionbg.x=0;
positionbg.y=0;
bg=IMG_Load("background.bmp");

for (i=21; i<=23; i++)
    {
        sprintf(perso,"%d.png",i);
        perso_anime[i]=IMG_Load(perso);
        
    }

for (j=1; j<=20; j++)
    {
        sprintf(perso,"%d.png",j);
        perso_anime[j]=IMG_Load(perso);
        
    }
for (l=24; l<=53; l++)
    {
        sprintf(perso,"%d.png",l);
        perso_anime[l]=IMG_Load(perso);
        
    }

for (m=54; m<=66; m++)
    {
        sprintf(perso,"%d.png",m);
        perso_anime[m]=IMG_Load(perso);
        
    }

int continuer=1;
SDL_EnableKeyRepeat(30,30);
SDL_Event event;
while(continuer) 
{

SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT : continuer=0;break;
case SDL_KEYDOWN :
 switch(event.key.keysym.sym)
  {
     case SDLK_UP:
        
                   k=3;
                   l++;
                   if(l>53){l=24;};
                   positionperso.y-=2;
                   SDL_WaitEvent(&event);
                   
                               break;
    case SDLK_DOWN:
            
                   k=4;
                   m++;
                   if(m>66){m=54;};
                   positionperso.y+=2;
                   SDL_WaitEvent(&event);
                
                               break;
    case SDLK_RIGHT:
            
                   k=2;
                   j++;
                   if(j>20){j=1;};
                   positionperso.x+=2;
                   SDL_WaitEvent(&event);
               
                               break;
     case SDLK_LEFT:
                
                    k=1;
                    i++;
                    if(i>24){i=21;};
                    positionperso.x-=2;
                    SDL_WaitEvent(&event);
                  
                               break;
             }break;

}
SDL_BlitSurface (bg, NULL , ecran , &positionbg);
if((k!=1)&&(k!=2)&&(k!=3)&&(k!=4)){SDL_BlitSurface(perso_anime[24],NULL,ecran,&positionperso);}
if(k==1) SDL_BlitSurface(perso_anime[i],NULL,ecran,&positionperso);
if(k==2) SDL_BlitSurface(perso_anime[j],NULL,ecran,&positionperso);
if(k==3) SDL_BlitSurface(perso_anime[l],NULL,ecran,&positionperso);
if(k==4) SDL_BlitSurface(perso_anime[m],NULL,ecran,&positionperso);

SDL_Flip(ecran);

}




SDL_FreeSurface (personnage);
SDL_FreeSurface (bg);
SDL_Quit();

return EXIT_SUCCESS;
}

