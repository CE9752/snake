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
		void move_right(int x[10],int i){
			if(i==0)
				x[i]=x[i]+20;
			else
				x[i]=x[i-1];
		}
		void move_left(int x[10],int i){
			if(i==0)
				x[i]=x[i]-20;
			else 
				x[i]=x[i-1];
		}
		void set_ball(int x[10],int i){
			filledCircleRGBA(r,x[i],500+i*20,10,255,rand()%255,0,255);
            circleRGBA(r,x[i],500+i*20,10,237,rand()%222,39,255);
		}
};