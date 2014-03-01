/*g++ mapViewer.cpp  -lSDL2*/
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <string>
#include "tile.h"
#include "boost/multi_array.hpp"
#include <boost/algorithm/string.hpp>
#include "colorHelper.h"

/* Window resolution */
#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240

/* Window title */
#define WINDOW_TITLE "SDL2 Test"

/* The window */
typedef boost::multi_array<tile,2> matrix;

class mapViewer{
private:
	matrix map;
	int sizeX;
	int sizeY;
public:

	void setX(int newX){
		sizeX=newX;
	}
	void setY(int newY){
		sizeY=newY;
	}
	void fillRect(SDL_Surface* dst,int x, int y, int w ,int h, Uint32 color){
		SDL_Rect tempRect;
		tempRect.x = x;
		tempRect.y = y;
		tempRect.w = w;
		tempRect.h = h;
		SDL_FillRect(dst,&tempRect,color);
	}

	SDL_Window* makeWindow(){
		return SDL_CreateWindow(
			   WINDOW_TITLE,
			   SDL_WINDOWPOS_CENTERED,
			   SDL_WINDOWPOS_CENTERED,
			   WINDOW_WIDTH,
			   WINDOW_HEIGHT,
			   SDL_WINDOW_SHOWN);
	}

	void displayTiles(SDL_Surface* screen){
		//std::cout<<"xdim:"<<map.shape()[0]<<" ydim:"<<map.shape()[1];
		int col=0;
		for (matrix::index y=0; y<map.shape()[1];y++){
			for (matrix::index x=0;x<map.shape()[0];x++){
				col=map[x][y].getWater();
				rgbColor wCol=rgbColor();
				wCol.setViaStr(col);
				// std::cout<<"r:"<<wCol.getR()<<" g:"<<wCol.getG()<<" b:"<<wCol.getB()<<"\n";
				fillRect(screen,x*15,y*15,14,14,SDL_MapRGB(screen->format, wCol.getR(), wCol.getG(), wCol.getB()));	
			}
		}
	}

	void runDisplay(){
		SDL_Window* window = NULL;
		SDL_Surface* screen = NULL;    /* The window surface */
		SDL_Event event;   /* The event structure */
		_Bool running = true;  /* The game loop flag */
		SDL_Surface* image = NULL; /* to put the loaded image */
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
			printf( "SDL2 could not initialize! SDL2_Error: %s\n", SDL_GetError() );
		}else{

			window = makeWindow();
			screen = SDL_GetWindowSurface( window );
			displayTiles(screen);
			while( running )
			{
			  while( SDL_PollEvent( &event ) != 0 )
			  {
			     if( event.type == SDL_QUIT )
			     {
			        running = false;
			     }
			  }
			  SDL_UpdateWindowSurface( window );
			}
		}
		 SDL_DestroyWindow( window );
		 SDL_Quit();
	}
	void makeMapTiles(std::vector<std::string> strs){
		int x;
		int y;
		int height;
		int water;
		int heat;
		int veg;
		int fauna;
		int align;
		std::istringstream(strs[0])>>x;
		std::istringstream(strs[1])>>y;
		std::istringstream(strs[2])>>height;
		std::istringstream(strs[3])>>water;
		std::istringstream(strs[4])>>heat;
		std::istringstream(strs[5])>>veg;
		std::istringstream(strs[6])>>fauna;
		std::istringstream(strs[7])>>align;
		map[x][y]=tile(height,water,heat,veg,fauna,align);
	}

	void extractHeader(std::string tempStr){
		std::vector<std::string> header;
		boost::split(header, tempStr, boost::is_any_of(","));
		int extX;
		int extY;
		std::istringstream(header[1])>>extX;
		std::istringstream(header[3])>>extY;
		sizeX=extX;
		sizeY=extY;
		map.resize(boost::extents[sizeX][sizeY]); 
	}

	void importMap(const std::string filePath){
		std::ifstream inFile;
		const char* filePath2=filePath.c_str();
		inFile.open(filePath2,std::ios::in);
		std::string tempStr;
		if (inFile.is_open()){
			getline(inFile,tempStr);
			extractHeader(tempStr);
			int lineNum=1;
			while (getline (inFile,tempStr)){
				if ((lineNum!=0)&&(lineNum!=1)){
					std::vector<std::string> strs;
					boost::split(strs, tempStr, boost::is_any_of(","));
					makeMapTiles(strs);
				}
				lineNum+=1;
			}
			inFile.close();
		}else{
			std::cout<< "Unable to open file";
		}

	}

};