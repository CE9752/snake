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
    		// if(count==0){
    		// 	for(int i=0;i<=rand()%12;i++){
    		// 		boxes[rand()%12][].show=true;
    		// 	}
    		// 	count++;
    		// }
    		// for(int i=0;i<12;i++){
    		// 	if(boxes[i].show==true){
    		// 		if(j<=650){
    		// 			boxes[i].set_position(i,j);
    		// 			boxes[i].block();
    		// 		}
    		// 	}
    		// }
    		for(int j=0;j<14;j++){
 				if(count==0){
 					for(int i=0;i<=rand()%12;i++){
 						boxes[rand()%12][j].show=true;
 					}
 					count++;
 				}
 				for(int i=0;i<12;i++){
 					if(boxes[i][j].show==true){
 						boxes[i][j].set_position(i,j);
 						boxes[i][j].block();
 						boxes[i][j+1].show=true;
 						//boxes[i][j].show=false;
 					}
 				}
 			}

    		while(SDL_PollEvent(&e) !=0){
                if(e.type == SDL_QUIT ){
                    quit = true;
                }
            }
            SDL_RenderPresent(r);
           // j=j+0.1;
    	}
    }
    close();
	return 0;
}