#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL2_gfxPrimitives.h>
#include<SDL2/SDL_ttf.h>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<stdio.h>
#include<string>
#include<SDL2/SDL_image.h>
SDL_Window* w=NULL;
SDL_Surface* s=NULL;
SDL_Renderer* r = NULL;
#include"box.h"
#include"ball.h"
#include"constball.h"
using namespace std;
const int SCREEN_WIDTH=600;
const int SCREEN_HEIGHT=700;


bool init(){
    bool success = true;
    w = SDL_CreateWindow("win",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if( w==NULL){
        cout<<"window could not be created! SDL_GetError()";
        success = false;
    }
    else{
    	r = SDL_CreateRenderer( w, -1, SDL_RENDERER_ACCELERATED );
        s=SDL_GetWindowSurface(w);
         SDL_FillRect(s, NULL, SDL_MapRGB( s->format, 255, 255, 255 ) ); 
         SDL_SetRenderDrawColor(r,0xFF, 0xFF, 0xFF, 200 );
    }
    return success;
}



void close(){
    SDL_DestroyWindow(w);
    SDL_DestroyRenderer( r );
    w=NULL;
    r=NULL;
    //TTF_Quit();
    SDL_Quit();
}
	/*TTF_Init();
	TTF_Font * font = TTF_OpenFont("ARIALI.TTF", 25);
	SDL_Color color = { 255, 255, 255 };
	*s = TTF_RenderText_Solid(font,"25", color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(r, s);*/

int main(){

	srand(time(0));
	int random=0;
	int moving=0;
    if(!init()){
        cout<<"failed to initialize!";
    }
    else{
    	Box boxes[12][14];
    	constantball redball;
    	Ball ball[10];
    	int count=0;
    	SDL_Event e;
    	bool quit = false;
/*
        int texW = 0;
		int texH = 0;
		SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
		SDL_Rect dstrect = { 0, 0, texW, texH };
*/		ball[0].set_pos(0,300);
    	while(!quit){
    		SDL_SetRenderDrawColor(r,0,0,0,255);
 			SDL_RenderClear(r);
 			for(int j=13;j>0;j--){
 				for(int i=0;i<12;i++){
 					if(boxes[i][j-1].show==true){
 						boxes[i][j].show=true;
 						boxes[i][j-1].show=false;
 						boxes[i][j].set_position(i,j);
 						boxes[i][j].block();
 						boxes[i][j-1].set_position(i,j-1);
 						boxes[i][j-1].hide();
 						
 					}
 					if(boxes[i][j-1].isball==true){
 						boxes[i][j].isball=true;
 						boxes[i][j-1].isball=false;
 						redball.show_ball(i,j);
 					}
 				}//for i
 			}// for j
 			if(count==3){
 				for(int i=0;i<12;i++){
 					random=rand()%5;
 					if(random==1 || random==0){
 						boxes[i][0].show=random;
 					}
 					else if(random==2){
 						boxes[i][0].isball=true;
 					}
 					else{
 						boxes[i][0].show=random%2;
 					}
 				}
 				count = -1;
 			}
 			if(count == 1){
 				for(int i=0;i<12;i++){
 					random=rand()%7;
 					if(random==0 || random==1){
 						boxes[i][0].isball=random;
 					}
 					
 				}
 			}
 			count++;
 			while(SDL_PollEvent(&e) !=0){
                if(e.type == SDL_QUIT ){
                    quit = true;
                }
                else if(e.type == SDL_KEYDOWN){
                	switch(e.key.keysym.sym){
                		case SDLK_d:
                			ball[0].move_right();                			
                			break;
                		case SDLK_a:
                			ball[0].move_left();
                			break;
                	}//switch
            	    }
            	}//while sdl pollevent
            	
 				ball[0].set_ball();
     	      	SDL_Delay(250);
            	//SDL_RenderCopy(r, texture, NULL, &dstrect);
            	SDL_RenderPresent(r);
 			}//while(!quit)
 			
    	}//else
/*	SDL_DestroyTexture(texture);
	SDL_FreeSurface(s);*/
    close();
	return 0;
}//end main