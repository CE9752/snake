#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL2_gfxPrimitives.h>
#include<ctime>
#include<cstdlib>
SDL_Window* w=NULL;
SDL_Surface* s=NULL;
SDL_Renderer* r = NULL;
#include"box.h"
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
    SDL_Quit();
}
int main(){
	srand(time(0));
	float j=0;
	int x_pos=300;
    if(!init()){
        cout<<"failed to initialize!";
    }
    else{
    	Box boxes[12][14];
    	int count=0;
    	SDL_Event e;
    	bool quit = false;
    	while(!quit){
    		SDL_SetRenderDrawColor(r,0,0,0,255);
 			SDL_RenderClear(r);
    	// 	for(int j=0;j<14;j++){
 				// if(count==0){
 				// 	for(int i=0;i<=rand()%12;i++){
 				// 		boxes[rand()%12][0].show=true;
 				// 	}
 				// 	count++;
 				// }
 				// for(int i=0;i<12;i++){
 				// 	if(boxes[i][0].show==true){
 				// 		boxes[i][0].set_position(i,j);
 				// 		boxes[i][0].block();
 				// 		boxes[i][0].set_position(i,j-1);
 				// 		boxes[i][0].hide();

 				// 	}
 				// }
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
 				}
 			}
 			if(count==3){
 				for(int i=0;i<12;i++){
 					boxes[i][0].show=rand()%2;
 				}
 				count = -1;
 			}
 			count++;
 			while(SDL_PollEvent(&e) !=0){
                if(e.type == SDL_QUIT ){
                    quit = true;
                }
                else if(e.type == SDL_KEYDOWN){
                	switch(e.key.keysym.sym){
                		case SDLK_d:
                		if(x_pos<590)
                			x_pos+=5;
                			break;
                		case SDLK_a:
                		if(x_pos>10)
                			x_pos-=5;
                			break;
                	}
                	filledCircleRGBA(r,x_pos,500,10,0,0,100,255);
                	circleRGBA(r,x_pos,500,10,0,0,100,255);
                	SDL_RenderPresent(r);
            	    }
            	}//while
            	SDL_Delay(500);
            	SDL_RenderPresent(r);
 			}
 			
    	}
    close();
	return 0;
}