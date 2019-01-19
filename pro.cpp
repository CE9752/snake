#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL2_gfxPrimitives.h>
#include <cmath>
#include<ctime>
using namespace std;
const int SCREEN_WIDTH=600;
const int SCREEN_HEIGHT=700;
SDL_Window* w=NULL;
SDL_Surface* s=NULL;
SDL_Renderer* r = NULL;
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
	 int x_pos=300;
    if(!init()){
        cout<<"failed to initialize!";
    }
    else{
    	SDL_Event e;
    	bool quit = false;
        while(!quit){

        	SDL_SetRenderDrawColor(r,0,0,0,255);
        	SDL_RenderClear(r);
        	while(SDL_PollEvent(&e) != 0){
        		if(e.type == SDL_QUIT){
        			quit = true;
        		}
        	   else if (e.type == SDL_KEYDOWN){
                
             		switch(e.key.keysym.sym){
						case SDLK_d:
						if(x_pos<580)
							x_pos+=5;
							break;
						case SDLK_a:
						if(x_pos>20)
							x_pos-=20;
							break;
					}
			filledCircleRGBA(r,x_pos,500,10,0,0,100,255);
        	circleRGBA(r,x_pos,500,10,0,0,200,255);
			SDL_RenderPresent(r);
        		}


			}
    	}
    close();
    return 0;
	}
}