#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/usr/include/SDL/SDL.h"
#include "/usr/include/SDL/SDL_image.h"
#include "/usr/include/SDL/SDL_mixer.h"
#include "/usr/include/SDL/SDL_ttf.h"
int main()
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL;
    SDL_Rect positionFond,pos;
    SDL_Surface *walk[5], *back[5];
   int i=0,j=0;

walk[0]=IMG_Load("pic1.png");
walk[1]=IMG_Load("pic2.png");
walk[2]=IMG_Load("pic3.png");
walk[3]=IMG_Load("pic4.png");
walk[4]=IMG_Load("pic5.png");

back[0]=IMG_Load("pic6.png");
back[1]=IMG_Load("pic7.png");
back[2]=IMG_Load("pic8.png");
back[3]=IMG_Load("pic9.png");
back[4]=IMG_Load("pic10.png");



   

   int done=1,k=0;
    positionFond.x = 0;
    positionFond.y =0;
    pos.x=0;
    pos.y=100;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(1000, 600, 24, SDL_HWSURFACE);
    SDL_WM_SetCaption("WELCOM TO LEVEL 1", NULL);


    imageDeFond = SDL_LoadBMP("background.bmp");

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    SDL_Flip(ecran);
   while(done)
   {

j=4;
SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
SDL_BlitSurface(walk[i], NULL, ecran, &pos);


    SDL_Flip(ecran);
    SDL_Delay(100);
    pos.x+=10;

i++;
if(i>=4)
{

i=0;

}

if(pos.x>=400)
{

while(j>=0)
{
SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
SDL_BlitSurface(back[j], NULL, ecran, &pos);
    SDL_Flip(ecran);
    SDL_Delay(100);
    pos.x-=10;

j--;

if(j<=0)
{

   

    j=4;
}


if(pos.x==0)
{

    break;
}
}

}
k++;


   } 
   




    SDL_FreeSurface(imageDeFond); 
    SDL_Quit();

    return EXIT_SUCCESS;
}
