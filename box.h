#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL2_gfxPrimitives.h>
using namespace std;
class Box{
	public:
		int tol= 50;
		int arz = 50;
		int x_pos;
		int y_pos;	
		int jon;
		bool show = false;
		bool isball = false;
		void set_jon(int Jon){
			jon = Jon;
		}
		void set_position(int i_x, int j_y){
			x_pos = tol*i_x;
			y_pos = arz*j_y;
		}

		void is_touched()
		{
			jon--;
		}
		void block(){
			//SDL_SetRenderDrawColor(r,100,0,0,255);
		 	boxRGBA(r,x_pos,y_pos,x_pos+48,y_pos+50,0,250,0,255);
		}
		void hide(){
			boxRGBA(r,x_pos,y_pos,x_pos+48,y_pos+50,0,0,0,255);
		}
};
