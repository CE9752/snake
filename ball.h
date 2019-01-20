#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL2_gfxPrimitives.h>
using namespace std;
class Ball{
	public:
		int x_pos;
		int y_pos;
		void set_pos(int i,int x1_pos){
			y_pos=500+i*20;
			x_pos=x1_pos;
		}
		void set_num(){

		}
		void move_right(){
			x_pos=x_pos+3;
		}
		void move_left(){
			x_pos=x_pos-3;
		}
		void set_ball(){
			filledCircleRGBA(r,x_pos,y_pos,10,0,0,100,255);
            circleRGBA(r,x_pos,y_pos,10,0,0,100,255);
		}
		void hide_ball(){

		}
		void touch_block(){
			
		}
};