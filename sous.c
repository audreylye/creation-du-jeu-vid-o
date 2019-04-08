#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void Rectangle_noir(SDL_Surface *Surface,SDL_Surface *Ecran,SDL_Rect pos){
	Surface= SDL_CreateRGBSurface(SDL_HWSURFACE, 400, 550	, 32, 0, 0, 0, 0);
    SDL_FillRect(Surface, NULL, SDL_MapRGB(Ecran->format,0,0,0));
    SDL_SetAlpha(Surface,SDL_SRCALPHA,100);  
    SDL_BlitSurface(Surface, NULL, Ecran, &pos);
    void Rectangle_menu(SDL_Surface *Ecran);
}



void Boutton_menu(SDL_Surface *Surface[],SDL_Rect Bottton[],SDL_Surface *Ecran,int R,int G,int B,int c,int d,int *continuer){
	int i;
	SDL_Surface *Con=NULL,*Sav=NULL,*Set=NULL,*F=NULL,*Com=NULL,*Main=NULL;
	TTF_Font *Continuer=NULL,*Save=NULL,*Settings=NULL,*Commandes=NULL,*Fin=NULL,*Menu=NULL;
	SDL_Rect Position;
	Position.x=130;
	Position.y=50;
	SDL_Color couleur={255,255,255};
	
	Menu=TTF_OpenFont("de.ttf",40);
	Continuer=TTF_OpenFont("de.ttf",40);
	Save=TTF_OpenFont("de.ttf",40);
	Settings=TTF_OpenFont("de.ttf",40);
	Commandes=TTF_OpenFont("de.ttf",40);
	Fin=TTF_OpenFont("de.ttf",40);
	Main=TTF_RenderText_Blended(Continuer,"Menu",couleur);
	Con=TTF_RenderText_Blended(Continuer,"Continue game",couleur);
	Sav=TTF_RenderText_Blended(Save,"Save game",couleur);
	Set=TTF_RenderText_Blended(Settings,"Settings",couleur);
	Com=TTF_RenderText_Blended(Commandes,"Controls",couleur);
	F=TTF_RenderText_Blended(Fin,"Quit game",couleur);
	for(i=0;i<5;i++){
	Surface[i]= SDL_CreateRGBSurface(SDL_HWSURFACE, 380, 75	, 32, 0, 0, 0, 0);
    	SDL_SetAlpha(Surface[i],SDL_SRCALPHA,150);  
        SDL_BlitSurface(Surface[i], NULL, Ecran, &Bottton[i]);
	R=0;
  	G=0;
  	B=0;
  	SDL_FillRect(Surface[i], NULL, SDL_MapRGB(Ecran->format,R,G,B));
    	Bottton[i].x+=20;
    	Bottton[i].y+=20;
    SDL_BlitSurface(Main,NULL,Ecran,&Position);
    if(i==0) SDL_BlitSurface(Con,NULL,Ecran,&Bottton[i]);
    else if(i==1) SDL_BlitSurface(Sav,NULL,Ecran,&Bottton[i]);
    else if(i==2) SDL_BlitSurface(Set,NULL,Ecran,&Bottton[i]);
    else if(i==3) SDL_BlitSurface(Com,NULL,Ecran,&Bottton[i]);
    else if(i==4) SDL_BlitSurface(F,NULL,Ecran,&Bottton[i]);
    Bottton[i].x-=20;
    Bottton[i].y-=20;
    Bottton[i+1].y=Bottton[i].y+90;
	}

	    if(c!=-1)
{		
  		R=0;
  		G=204;
  		B=255;
  		SDL_FillRect(Surface[c], NULL, SDL_MapRGB(Ecran->format,R,G,B));
	SDL_BlitSurface(Surface[c], NULL, Ecran, &Bottton[c]);
}

	if(d==0)
	(*continuer)=0;
 SDL_Flip(Ecran);
}



int choix(SDL_Rect position){
int choix;
if((position.x > 10)&&(position.x<390)){
	if((position.y>100)&&(position.y<175)){
		choix=0;
	}
	else if((position.y>190)&&(position.y<265)){
		choix=1;
	}
	else if((position.y>280)&&(position.y<355)){
		choix=2;
	}
	else if((position.y>370)&&(position.y<445)){
		choix=3;
	}
	else if((position.y>460)&&(position.y<535)){
		choix=4;
	}
	else choix=-1;
}
else choix=-1;
return choix;
}


int sousmenu(SDL_Surface *Ecran){
	SDL_Surface *Rectangle=NULL,*Bref=NULL,*SM[5];
	int continuer1=1,i,c=-1,d=-1,R=0,G=0,B=0;
	SDL_Rect Position,Pos,Boutton[5],posi_choix,posi_clic;
	SDL_Event Event;
	Position.x=5;
	Position.y=5;
	Pos.x=-3000;
	Pos.y=-3000;
	Boutton[0].x=10;
	Boutton[0].y=100;
	for(i=1;i<5;i++){
		Boutton[i].x=10;
		Boutton[i].y=Boutton[i-1].y;
	}

 	Rectangle_noir(Rectangle,Ecran,Position);
	while(continuer1){
		 while(SDL_PollEvent(&Event))  
 		switch(Event.type){
 		case SDL_QUIT:
 		continuer1=0;
 		break;
 		case SDL_MOUSEMOTION:
 			posi_choix.x=Event.motion.x;
 			posi_choix.y=Event.motion.y;
 			c=choix(posi_choix);
			Boutton_menu(SM,Boutton,Ecran,R,G,B,c,d,&continuer1);
 			printf("Choix: %d\n",c);
 		break;
		case SDL_MOUSEBUTTONDOWN:
 			posi_clic.x=Event.button.x;
 			posi_clic.y=Event.button.y;
 			d=choix(posi_clic);
			Boutton_menu(SM,Boutton,Ecran,R,G,B,c,d,&continuer1);
 			printf("Choix: %d\n",c);
 		break;
	}
}
	SDL_FreeSurface(Rectangle);
	for(i=0;i<5;i++)
	SDL_FreeSurface(SM[i]);
}
