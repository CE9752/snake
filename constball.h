#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL2_gfxPrimitives.h>
using namespace std;
class constantball{
	public:
		void show_ball(int i,int j){
			filledCircleRGBA(r,i*50+25,j*50+25,10,255,0,0,255);
            circleRGBA(r,i*50+25,j*50+25,10,255,0,0,255);
		}
};