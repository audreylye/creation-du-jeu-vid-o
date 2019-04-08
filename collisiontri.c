
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <math.h>


int collision_trigo(SDL_Surface *personnage  ,SDL_Surface *objet,SDL_Rect positionperso,SDL_Rect positionobjet )
{
int ra,rb,xb,xa,ya,yb,distance;

ra=sqrt(((personnage->w/2)*(personnage->w/2))+(personnage->h/2)*(personnage->h/2));
if((personnage->w/2)<=(personnage->h/2))
{
ra=(personnage->w/2);

}
else {
ra=(personnage->h/2);
}
xa=(positionperso.x+(personnage->w/2));
ya=(positionperso.y+(personnage->h/2));
rb=sqrt(((objet->w/2)*(objet->w/2))+(objet->h/2)*(objet->h/2));
if((objet->w/2)<=(objet->h/2))
{
rb=(objet->w/2);

}
else {
rb=(objet->h/2); 
}
xb=(positionobjet.x+(objet->w/2));
yb=(positionobjet.y+(objet->h/2));
distance=sqrt((xa-xb)*(xa-xb)+( ya-yb)*( ya-yb));
if(distance<=ra+rb)
{
return 1 ;
}
else
{
return 0;
}
}



int main (int argc , char **argv)
{

int i=21,k,j=1,l=24,m=54;
char perso[44];
SDL_Surface *perso_anime[67];


SDL_Surface *ecran = NULL ;
SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(554,698,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
SDL_WM_SetCaption("deplacement perso", NULL);

SDL_Surface *personnage=NULL, *objet=NULL;
SDL_Rect positionperso, positionobjet ;
positionperso.x=0;
positionperso.y=300;
positionobjet.x=300;
positionobjet.y=350;
 

SDL_Surface *bg=NULL;
SDL_Rect positionbg;
positionbg.x=0;
positionbg.y=0;
bg=IMG_Load("background.bmp");
 
objet = IMG_Load("objet.png");
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
SDL_BlitSurface(objet, NULL, ecran, &positionobjet);

if((k!=1)&&(k!=2)&&(k!=3)&&(k!=4)){SDL_BlitSurface(perso_anime[67],NULL,ecran,&positionperso);}
if(k==1) SDL_BlitSurface(perso_anime[i],NULL,ecran,&positionperso);
if(k==2) SDL_BlitSurface(perso_anime[j],NULL,ecran,&positionperso);
if(k==3) SDL_BlitSurface(perso_anime[l],NULL,ecran,&positionperso);
if(k==4) SDL_BlitSurface(perso_anime[m],NULL,ecran,&positionperso);

SDL_Flip(ecran);

}




SDL_FreeSurface (personnage);
SDL_FreeSurface (bg);
SDL_FreeSurface (objet);
SDL_Quit();

return EXIT_SUCCESS;
}

