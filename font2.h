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
using namespace std;
class Text
{
	public:
		Text(){
		mText = NULL;
		mWidth = 48;
		mHeight = 50;
		}
		SDL_Texture* mText;
		int mWidth;
		int mHeight;
		//int num;
		SDL_Color color={255,0,0};
		char numstring[3];
		SDL_Surface* numsurface;
		SDL_Rect NumRect;

		void render(int x1, int y1,int num[14][12],int i,int j){
			sprintf(numstring,"%d",num[i][j]);
			numsurface=TTF_RenderText_Solid(f,numstring,color);
			mText=SDL_CreateTextureFromSurface(r,numsurface);
			SDL_QueryTexture(mText,NULL,NULL,&mWidth,&mHeight);
			NumRect.x=x1; NumRect.y=y1; NumRect.w=mWidth; NumRect.h=mHeight;
			SDL_RenderCopy(r,mText,NULL,&NumRect);
			SDL_DestroyTexture(mText);
			SDL_FreeSurface(numsurface);
		}
		void render1(int x1,int y1,int num){
			sprintf(numstring,"%d",num);
			numsurface=TTF_RenderText_Solid(f,numstring,color);
			mText=SDL_CreateTextureFromSurface(r,numsurface);
			SDL_QueryTexture(mText,NULL,NULL,&mWidth,&mHeight);
			NumRect.x=x1; NumRect.y=y1; NumRect.w=20; NumRect.h=20;
			SDL_RenderCopy(r,mText,NULL,&NumRect);
			SDL_DestroyTexture(mText);
			SDL_FreeSurface(numsurface);
		}
};