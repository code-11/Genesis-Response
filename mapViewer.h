/*g++ mapViewer.cpp -o viewer  -lSDL2*/
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <string>
#include "boost/multi_array.hpp"
#include <boost/algorithm/string.hpp>
#include <cmath>
#include "drawHelper.h"

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

	void renderLines(SDL_Renderer* renderer){
		 
		int tileWidth=55;
		int tileHeight=55;
		for (matrix::index y=0; y<map.shape()[1];y++){
			for (matrix::index x=0;x<map.shape()[0];x++){
			    int curX=x*tileWidth;
				int curY=y*tileHeight;
				drawTile(renderer,curX,curY,map[x][y],tileWidth,tileHeight);
			}
		}		
		

	}

	void runDisplay(){
		SDL_Window* window = NULL;
		SDL_Surface* screen = NULL;    /* The window surface */
		SDL_Event event;   /* The event structure */
		_Bool running = true;  /* The game loop flag */
		SDL_Surface* image = NULL; /* to put the loaded image */
		SDL_Renderer* renderer;
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
			printf( "SDL2 could not initialize! SDL2_Error: %s\n", SDL_GetError() );
		}else{

			window = makeWindow();
			// screen = SDL_GetWindowSurface( window );
			renderer = SDL_CreateRenderer(window, -1, 0);
			//displayTiles(screen);
			renderLines(renderer);
			SDL_RenderPresent(renderer);
			while( running )
			{
			  while( SDL_PollEvent( &event ) != 0 )
			  {
			     if( event.type == SDL_QUIT )
			     {
			        running = false;
			     }
			  }
			  // SDL_UpdateWindowSurface( window );
			}
			// SDL_Delay(4000);
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