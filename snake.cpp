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
TTF_Font * f = NULL; 
#include"box.h"
#include"ball.h"
#include"constball.h"
#include"font2.h"
using namespace std;
const int SCREEN_WIDTH=600;
const int SCREEN_HEIGHT=700;
Text t;
Text rb;
Text bb;
Text score;
bool init(){
	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		cout<<( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
			cout<<( "Warning: Linear texture filtering not enabled!" );
		}
		w = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( w == NULL ){
			cout<<( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else{
			r = SDL_CreateRenderer( w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( r == NULL ){
				cout<<( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else{
				SDL_SetRenderDrawColor( r, 0xFF, 0xFF, 0xFF, 0xFF );
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) ){
					cout<<( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( TTF_Init() == -1 ){
					cout<<( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}
bool loadMedia(){
	bool success = true;
	f = TTF_OpenFont( "ARIALI.TTF", 20 );
	if( f == NULL ){
		cout<<( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}

	return success;
}

void close(){
	TTF_CloseFont( f );
	f = NULL;
    SDL_DestroyWindow(w);
    SDL_DestroyRenderer( r );
    w=NULL;
    r=NULL;
    TTF_Quit();
	IMG_Quit();
    SDL_Quit();
}

int main(){
	srand(time(0));
	int random=0;
	int moving=0;
    int firstsetball=0;
    if(!init()){
        cout<<"failed to initialize!";
    }
    else{
    	if(!loadMedia()){
    		cout<<( "Failed to load media!\n" );
    	}
    	else{
    		Box boxes[12][14];
    		constantball redball;
    		Ball ball[10];
    		int x[10];
    		for(int i=0;i<10;i++){
    			x[i]=300;
    		}
    		int count=0;
            int counter=0;
    		int num[14][12];
            int num1[14][12];
            int number=4;
            int s=0;
    		SDL_Event e;
    		bool quit = false;
			/*ball[0].set_pos(0,300);
    		for(int i=1;i<10;i++){
 					ball[i].set_pos(i,300);
 				}*/
    		while(!quit){
    			SDL_SetRenderDrawColor(r,0,0,0,255);
 				SDL_RenderClear(r);
 				for(int j=13;j>0;j--){		
 					for(int i=0;i<12;i++){
						if(boxes[i][j-1].show==true){
 							boxes[i][j].show=true;
 							boxes[i][j-1].show=false;
 							for(float a=0;a<=50;a+=0.01){
 								boxes[i][j].set_position(i,j,a);
 								boxes[i][j].block();
 								boxes[i][j-1].set_position(i,j-1,a);
 								boxes[i][j-1].hide();
 							}//for a
 							num[i][j]=num[i][j-1];								
 							if(x[0]-10>boxes[i][j].x_pos && x[0]+10<boxes[i][j].x_pos+48 && 500>boxes[i][j].y_pos+50 && boxes[i][j].y_pos+50>480){
 								ball[0].touch_block();
 								num[i][j]--;
                                number--;
 							}
                            if(50<num[i][j]){
                                num[i][j]=rand()%50+1;
                            }
                            if(num[i][j]<1){
                                boxes[i][j].show=false;
                            }
 							t.render(boxes[i][j].x_pos+20,boxes[i][j].y_pos+10,num,i,j);
 						}
 						if(boxes[i][j-1].isball==true){
                            num1[i][j]=num1[i][j-1];
 							boxes[i][j].isball=true;
 							boxes[i][j-1].isball=false;
 							redball.show_ball(i,j);
                            if(x[0]-10>i*50+25-20 && x[0]+10<i*50+25+20 && 500>j*50+25 && j*50+25>470){
                                boxes[i][j].isball=false;
                                number+=num1[i][j];
                            }
                            if(num1[i][j]<1 or 50<num1[i][j]){
                                num1[i][j]=rand()%5+1;
                            }
                            rb.render(boxes[i][j].x_pos+20,boxes[i][j].y_pos,num1,i,j);
 						}
 					}//for i
 				}// for j
 					if(count==6){
 						for(int i=0;i<12;i++){
 							random=rand()%5;
 							if(random==1 || random==0){
 								boxes[i][0].show=random;
 								num[i][0]=rand()%50+1;
 							}
 							else if(random==2){
 								boxes[i][0].isball=true;
                                num1[i][0]=rand()%5+1;
 							}
 							else{
 								boxes[i][0].show=random%2;
 							}
 						}
 						count = -1;
 					}
 					if(count == 3){
 						for(int i=0;i<12;i++){
 							random=rand()%7;
 							if(random==0 || random==1){
 								boxes[i][0].isball=random;
 							}
 						}
 					}
 					count++;
 				for(int i=0;i<number+1;i++){
            	    ball[i].set_ball(x,i);
            	}
                bb.render1(x[0]-10,470,number);
                if(number<0){
                	
                }
 				while(SDL_PollEvent(&e) !=0){
                	if(e.type == SDL_QUIT ){
                	    quit = true;
                	}
                	else if(e.type == SDL_KEYDOWN){
                		switch(e.key.keysym.sym){
                			case SDLK_RIGHT:
                				for(int i=0;i<number+1,i<10;i++){
                                    if(counter==(3*i)){
                                        ball[i].move_right(x,i);
                		  		      ball[i].set_ball(x,i);
                				    } 			
                				}
                				break;
               				case SDLK_LEFT:
                                for(int i=0;i<number+1,i<10;i++){
                                    if(counter==(3*i)){
                                        ball[i].move_left(x,i);
                                        ball[i].set_ball(x,i);
                                        
                                    }                        
                                }
               					break;
               			}//switch
            		}
                    if(counter==27){
                        counter=-1;
                    } 
                    counter++;
            	}//while sdl pollevent
            	s++;
                    score.render1(560,10, s);
     	      		SDL_Delay(50);
            		SDL_RenderPresent(r);
 				}//while(!quit)
 			}
    	}//else
    close();
	return 0;
}//end main