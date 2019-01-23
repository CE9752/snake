#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL2_gfxPrimitives.h>
using namespace std;
class Ball{
	public:
		int x_pos;
		int y_pos;
		int number=5;
		void set_pos(int i,int x1_pos){
			y_pos=500+i*20;
			x_pos=x1_pos;
		}
		int set_num(){
			return number;
		}
		void move_right(float x[10],int i){
				x[i]=x[i]+(float)(3)/(2*(float)(i+1));
		}
		void move_left(float x[10],int i){
				x[i]=x[i]-(float)(3)/(2*(float)(i+1));
		}
		void set_ball(float x[10],int i){
			filledCircleRGBA(r,x[i],500+i*20,10,0,0,100,255);
            circleRGBA(r,x[i],500+i*20,10,0,0,100,255);
		}
		void hide_ball(){

		}
		void touch_block(){
			number--;
			
		}
		void touch_ball(){
			number++;
		}
};