/*g++ mapViewer.cpp  -lSDL2*/
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <string>
#include "tile.h"
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
		int col=0; 
		int tileWidth=55;
		int tileHeight=55;
		for (matrix::index y=0; y<map.shape()[1];y++){
			for (matrix::index x=0;x<map.shape()[0];x++){
				col=map[x][y].getHeat();
				int height=map[x][y].getHeight();
				int weightedHeight=(height*(tileHeight/3))/100;

				int align=map[x][y].getAlign();

				rgbColor wCol=rgbColor();
				wCol.setViaStr(col);

				rgbColor lineCol=rgbColor();
				lineCol.setAll(0,0,0);

				rgbColor faunaCol=rgbColor();
				faunaCol.setAll(0,0,0);
				faunaCol.setA((map[x][y].getFauna()*255)/100);

				rgbColor plantCol=rgbColor();
				plantCol.setAll(0,0,0);
				plantCol.setA((map[x][y].getVeg()*255)/100);

				rgbColor waterCol=rgbColor();
				waterCol.setAll(0,0,255);
				waterCol.setA((map[x][y].getWater()*255)/100);

				rgbColor alignCol=rgbColor();
				int rgbVal=((align+100)*255)/200;
				alignCol.setAll(rgbVal,rgbVal,rgbVal);
				alignCol.setA((std::abs(align)*255)/100);

				int curW=x*tileWidth;
				int curH=y*tileHeight;

				drawRect(renderer,curW,curH,tileWidth-1,tileHeight-1,wCol);
				drawChev(renderer,curW+2,(curW)+tileWidth-4,(curH)+(tileHeight/2),weightedHeight,lineCol,3);
				if (align<0){
					drawSkull(renderer,curW+(tileWidth/2)-4,curH+(tileHeight/2),.5,alignCol);				
				}else{
					drawHalo(renderer,curW+(tileWidth/2)-4,curH+(tileHeight/2),.5,alignCol);				
				}
				drawRect(renderer,curW+(tileWidth/8)+5,curH+(tileHeight/2)+2,(3*tileWidth/4)-10,tileHeight/16,waterCol);
				drawPlant(renderer,curW+(tileWidth/5),curH+((tileHeight*15)/16),.5,plantCol);
				drawAntler(renderer,curW+((tileWidth*5)/6)-1,curH+((tileHeight*15)/16)+1,.5,faunaCol);
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