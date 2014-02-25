/*g++ mapViewer.cpp  -lSDL2*/
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <string>

/* Window resolution */
#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240

/* Window title */
#define WINDOW_TITLE "SDL2 Test"

/* The window */
SDL_Window* window = NULL;
	
/* The window surface */
SDL_Surface* screen = NULL;

/* The event structure */
SDL_Event event;

/* The game loop flag */
_Bool running = true;

/* to put the loaded image */
SDL_Surface* image = NULL;

void fillRect(SDL_Surface* dst,int x, int y, int w ,int h, Uint32 color){
	SDL_Rect tempRect;
	tempRect.x = x;
	tempRect.y = y;
	tempRect.w = w;
	tempRect.h = h;
	SDL_FillRect(dst,&tempRect,color);
}
void runDisplay(){
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL2 could not initialize! SDL2_Error: %s\n", SDL_GetError() );
	}else{
		window = SDL_CreateWindow(
		   WINDOW_TITLE,
		   SDL_WINDOWPOS_CENTERED,
		   SDL_WINDOWPOS_CENTERED,
		   WINDOW_WIDTH,
		   WINDOW_HEIGHT,
		   SDL_WINDOW_SHOWN);

		screen = SDL_GetWindowSurface( window );
		fillRect(screen, 10,10,50,50, SDL_MapRGB(screen->format, 0, 255, 0));
		fillRect(screen, 80,80,20,20, SDL_MapRGB(screen->format, 0, 0, 255));

		//image = SDL_LoadBMP( "sdl_logo.bmp" );
		while( running )
		{
		  while( SDL_PollEvent( &event ) != 0 )
		  {
		     if( event.type == SDL_QUIT )
		     {
		        running = false;
		     }
		  }
		  //SDL_BlitSurface( image, NULL, screen, NULL );
		  SDL_UpdateWindowSurface( window );
		}
	}
	// SDL_FreeSurface( image );
	 SDL_DestroyWindow( window );
	 SDL_Quit();
}
void importMap(const std::string filePath){
	std::ifstream inFile;
	const char* filePath2=filePath.c_str();
	inFile.open(filePath2,std::ios::in);
	//std::ifstream inFile (filePath, std::ios::in);
	std::string tempStr;
	if (inFile.is_open()){
		while (getline (inFile,tempStr)){
			std::cout<<tempStr<<'\n';
		}
		inFile.close();
	}else{
		std::cout<< "Unable to open file";
	}

}
int main( int argc, char* args[] )
{
	importMap("testFileIO.txt");
	runDisplay();
	return 0;
}