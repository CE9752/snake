#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL2_gfxPrimitives.h>
using namespace std;
class Box{
	public:
		int tol= 50;
		float arz = 50;
		int x_pos;
		float y_pos;	
		int jon;
		bool show = false;
		bool isball = false;
		void set_position(int i_x, int j_y,float a){
			x_pos = tol*i_x;
			y_pos = (arz*(j_y-1))+a;
		}
		void block(){
		 	boxRGBA(r,x_pos,y_pos,x_pos+48,y_pos+50,0,250,0,255);
		}
		void block1(){
		 	boxRGBA(r,x_pos,y_pos,x_pos+48,y_pos+50,179,255,179,255);
		}
		void block2(){
		 	boxRGBA(r,x_pos,y_pos,x_pos+48,y_pos+50,0,128,0,255);
		}
		void hide(){
			boxRGBA(r,x_pos,y_pos,x_pos+48,y_pos+50,0,0,0,255);
		}
};