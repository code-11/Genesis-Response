#include "colorHelper.h"

/* Window resolution */
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

/* Window title */
#define WINDOW_TITLE "SDL2 Test"

typedef std::vector<int> NUM_VEC;
typedef std::vector<bool> BOOL_VEC;

SDL_Window* makeWindow(){
        return SDL_CreateWindow(
               WINDOW_TITLE,
               SDL_WINDOWPOS_CENTERED,
               SDL_WINDOWPOS_CENTERED,
               WINDOW_WIDTH,
               WINDOW_HEIGHT,
               SDL_WINDOW_SHOWN);
    }

void fillRect(SDL_Surface* dst,int x, int y, int w ,int h, Uint32 color){
        SDL_Rect tempRect;
        tempRect.x = x;
        tempRect.y = y;
        tempRect.w = w;
        tempRect.h = h;
        SDL_FillRect(dst,&tempRect,color);
}
void drawRect(SDL_Renderer* renderer,int x,int y, int w, int h,rgbColor col){
    SDL_SetRenderDrawColor(renderer, col.getR(), col.getG(), col.getB(), col.getA());
    SDL_Rect tempRect;
    tempRect.x = x;
    tempRect.y = y;
    tempRect.w = w;
    tempRect.h = h;
    SDL_RenderFillRect(renderer,&tempRect);
}

void drawLine(SDL_Renderer* renderer,int x1, int y1, int x2, int y2, rgbColor c,int thick){
        SDL_SetRenderDrawColor(renderer, c.getR(), c.getG(), c.getB(), c.getA());
        SDL_RenderDrawLine(renderer,x1,y1,x2,y2);
        int diffX =x2-x1;
        int diffY =y2-y1;
        if (diffX==0){diffX=1;}
        int slope = diffY/diffX;
        //std::cout<<slope;

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
void drawPoly(SDL_Renderer* renderer,NUM_VEC xs,NUM_VEC ys,rgbColor col,int thick){
    if (xs.size()==ys.size()){
        NUM_VEC::iterator fstX=xs.begin();
        NUM_VEC::iterator sndX=xs.begin();
        NUM_VEC::iterator fstY=ys.begin();
        NUM_VEC::iterator sndY=ys.begin();
        sndX+=1;
        sndY+=1;
        while (sndX!=xs.end()){
            drawLine(renderer,*fstX,*fstY,*sndX,*sndY,col,thick);
            fstX+=1;
            fstY+=1;
            sndX+=1;
            sndY+=1;
        }
        sndY-=1;
        sndX-=1;
        std::cout<<*sndX<<" "<<*sndY;
        drawLine(renderer,*sndX,*sndY,*xs.begin(),*ys.begin(),col,thick);
    }
}

void drawPolyExcl(SDL_Renderer* renderer,NUM_VEC xs,NUM_VEC ys,NUM_VEC excl,rgbColor col,int thick){
    if ((xs.size()==ys.size())&&(excl.size()==xs.size()))
    {
        NUM_VEC::iterator fstX=xs.begin();
        NUM_VEC::iterator sndX=xs.begin();
        NUM_VEC::iterator fstY=ys.begin();
        NUM_VEC::iterator sndY=ys.begin();
        NUM_VEC::iterator ex=excl.begin();
        sndX+=1;
        sndY+=1;
        while (sndX!=xs.end()){
            if (*ex==1){
                drawLine(renderer,*fstX,*fstY,*sndX,*sndY,col,thick);
            }
            fstX+=1;
            fstY+=1;
            sndX+=1;
            sndY+=1;
            ex+=1;
        }
        sndY-=1;
        sndX-=1;
        ex-=1;
        if (*ex==1)
            drawLine(renderer,*sndX,*sndY,*xs.begin(),*ys.begin(),col,thick);
    }else{
        std::cout<<"Vector size mismatch\n";
        std::cout<<xs.size()<<" "<<ys.size()<<" "<<excl.size(); 
    }
}

void drawChev(SDL_Renderer* renderer, int x1,int x2,int y, int height,rgbColor col, int thick){
    int halfX=(x1+x2)/2;

    drawLine(renderer,x1,y,halfX,y-height,col,thick);
    drawLine(renderer,halfX,y-height,x2,y,col,thick);

}