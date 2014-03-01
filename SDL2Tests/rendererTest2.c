#include <SDL2/SDL.h>
#include <iostream>
void drawLine(SDL_Renderer* renderer,int x1, int y1, int x2, int y2, int r, int g, int b,int thick){
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawLine(renderer,x1,y1,x2,y2);
        int diffX =x2-x1;
        int diffY =y2-y1;
        if (diffX==0){diffX=1;}
        int slope = diffY/diffX;
        std::cout<<slope;

        if (slope>1){ 
                if (thick>1)
                    SDL_RenderDrawLine(renderer,x1+1,y1,x2+1,y2);
                if (thick>2)
                    SDL_RenderDrawLine(renderer,x1-1,y1,x2-1,y2);
                if (thick>3) 
                    SDL_RenderDrawLine(renderer,x1+2,y1,x2+2,y2);
                if (thick>4)
                    SDL_RenderDrawLine(renderer,x1-2,y1,x2-2,y2); 
        } else {
                if (thick>1)
                    SDL_RenderDrawLine(renderer,x1,y1+1,x2,y2+1);
                if (thick>2)
                    SDL_RenderDrawLine(renderer,x1,y1-1,x2,y2-1);
                if (thick>3) 
                    SDL_RenderDrawLine(renderer,x1,y1+2,x2,y2+2);
                if (thick>4)
                    SDL_RenderDrawLine(renderer,x1,y1-2,x2,y2-2);   
        }
}

int main(int argc, char* argv[])
{
        SDL_Window* window;
        SDL_Renderer* renderer;

        // Initialize SDL.
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
                return 1;

        // Create the window where we will draw.
        window = SDL_CreateWindow("SDL_RenderClear",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        512, 512,
                        0);

        // We must call SDL_CreateRenderer in order for draw calls to affect this window.
        renderer = SDL_CreateRenderer(window, -1, 0);

        // Select the color for drawing. It is set to red here.
        drawLine(renderer,10,10,10,50,255,0,0,4);
        drawLine(renderer,50,50,70,50,255,0,0,4);
        drawLine(renderer,50,70,25,35,255,0,0,4);
        drawLine(renderer,40,10,80,15,255,0,0,4);

        drawLine(renderer,10,80,10,120,0,255,0,3);
        drawLine(renderer,50,120,70,120,0,255,0,3);
        drawLine(renderer,50,140,25,105,0,255,0,3);
        drawLine(renderer,40,80,80,85,0,255,0,3);

        drawLine(renderer,10,150,10,190,0,0,255,2);
        drawLine(renderer,50,190,70,190,0,0,255,2);
        drawLine(renderer,50,210,25,175,0,0,255,2);
        drawLine(renderer,40,150,80,155,0,0,255,2);

        drawLine(renderer,10,220,10,260,135,135,135,1);
        drawLine(renderer,50,260,70,260,135,135,135,1);
        drawLine(renderer,50,280,25,245,135,135,135,1);
        drawLine(renderer,40,220,80,225,135,135,135,1);
        // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        // SDL_RenderDrawLine(renderer,10,10,50,50);
        // Clear the entire screen to our selected color.
        //SDL_RenderClear(renderer);


        // Up until now everything was drawn behind the scenes.
        // This will show the new, red contents of the window.
        SDL_RenderPresent(renderer);

        // Give us time to see the window.
        SDL_Delay(4000);

        // Always be sure to clean up
        SDL_Quit();
        return 0;
}