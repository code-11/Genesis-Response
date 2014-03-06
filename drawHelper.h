#include "colorHelper.h"
#include "tile.h"
/* Window resolution */
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

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
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, col.getR(), col.getG(), col.getB(), col.getA());
    SDL_Rect tempRect;
    tempRect.x = x;
    tempRect.y = y;
    tempRect.w = w;
    tempRect.h = h;
    SDL_RenderFillRect(renderer,&tempRect);
}

void drawHollowRect(SDL_Renderer* renderer,int x,int y, int w, int h,rgbColor col){
    SDL_SetRenderDrawColor(renderer, col.getR(), col.getG(), col.getB(), col.getA());
    SDL_Rect tempRect;
    tempRect.x = x;
    tempRect.y = y;
    tempRect.w = w;
    tempRect.h = h;
    SDL_RenderDrawRect(renderer,&tempRect);
}

void drawLine(SDL_Renderer* renderer,int x1, int y1, int x2, int y2, rgbColor c,int thick){
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
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
void drawSkull(SDL_Renderer* renderer,int x1,int y1, float size,rgbColor col){
    
    //Bottom of Jaw
    drawLine(renderer,x1,y1,x1+int(10*size),y1,col,1);
    
    //Right Cheek
    drawLine(renderer,x1+int(10*size),y1,x1+int(12*size),y1-int(3*size),col,1);
    drawLine(renderer,x1+int(12*size),y1-int(3*size),x1+int(12*size),y1-int(8*size),col,1);
    drawLine(renderer,x1+int(12*size),y1-int(8*size),x1+int(13*size),y1-int(8*size),col,1);
    drawLine(renderer,x1+int(13*size),y1-int(8*size),x1+int(16*size),y1-int(15*size),col,1);
    drawLine(renderer,x1+int(16*size),y1-int(15*size),x1+int(16*size),y1-int(22*size),col,1);
    drawLine(renderer,x1+int(16*size),y1-int(22*size),x1+int(14*size),y1-int(27*size),col,1);
    
    //Top of the Head
    drawLine(renderer,x1+int(14*size),y1-int(27*size),x1+int(10*size),y1-int(29*size),col,1);
    drawLine(renderer,x1+int(10*size),y1-int(29*size),x1,y1-int(29*size),col,1);
    drawLine(renderer,x1,y1-int(29*size),x1-int(4*size),y1-int(27*size),col,1);

    //Left Cheek
    drawLine(renderer,x1,y1,x1-int(2*size),y1-int(3*size),col,1);
    drawLine(renderer,x1-int(2*size),y1-int(3*size),x1-int(2*size),y1-int(8*size),col,1);
    drawLine(renderer,x1-int(2*size),y1-int(8*size),x1-int(3*size),y1-int(8*size),col,1);
    drawLine(renderer,x1-int(3*size),y1-int(8*size),x1-int(6*size),y1-int(15*size),col,1);
    drawLine(renderer,x1-int(6*size),y1-int(15*size),x1-int(6*size),y1-int(22*size),col,1);
    drawLine(renderer,x1-int(6*size),y1-int(22*size),x1-int(4*size),y1-int(27*size),col,1);

    //Eyes
    drawHollowRect(renderer,x1-int(1*size),y1-int(22*size),int(5*size),int(5*size),col);
    drawHollowRect(renderer,x1+int(8*size),y1-int(22*size),int(5*size),int(5*size),col);

    //Mouth
    drawLine(renderer,x1+int(1*size),y1-int(6*size),x1+int(1*size),y1-int(2*size),col,1);
    drawLine(renderer,x1+int(4*size),y1-int(6*size),x1+int(4*size),y1-int(2*size),col,1);
    drawLine(renderer,x1+int(6*size),y1-int(6*size),x1+int(6*size),y1-int(2*size),col,1);
    drawLine(renderer,x1+int(9*size),y1-int(6*size),x1+int(9*size),y1-int(2*size),col,1);

    //Nose
    drawLine(renderer,x1+int(3*size),y1-int(10*size),x1+int(7*size),y1-int(10*size),col,1);
    drawLine(renderer,x1+int(3*size),y1-int(10*size),x1+int(5*size),y1-int(13*size),col,1);
    drawLine(renderer,x1+int(7*size),y1-int(10*size),x1+int(5*size),y1-int(13*size),col,1);

    //Crosses
    drawLine(renderer,x1-int(11*size),y1,x1+int(17*size),y1+int(14*size),col,int(size*2));
    drawLine(renderer,x1+int(21*size),y1,x1-int(7*size),y1+int(14*size),col,int(size*2));
}
void drawHalo(SDL_Renderer* renderer,int x1,int y1, float size,rgbColor col){
    //Bottom of Jaw
    drawLine(renderer,x1,y1,x1+int(10*size),y1,col,1);
    
    //Right Cheek
    drawLine(renderer,x1+int(10*size),y1,x1+int(12*size),y1-int(3*size),col,1);
    drawLine(renderer,x1+int(12*size),y1-int(3*size),x1+int(12*size),y1-int(8*size),col,1);
    drawLine(renderer,x1+int(12*size),y1-int(8*size),x1+int(13*size),y1-int(8*size),col,1);
    drawLine(renderer,x1+int(13*size),y1-int(8*size),x1+int(16*size),y1-int(15*size),col,1);
    drawLine(renderer,x1+int(16*size),y1-int(15*size),x1+int(16*size),y1-int(22*size),col,1);
    drawLine(renderer,x1+int(16*size),y1-int(22*size),x1+int(14*size),y1-int(27*size),col,1);
    
    //Top of the Head
    drawLine(renderer,x1+int(14*size),y1-int(27*size),x1+int(10*size),y1-int(29*size),col,1);
    drawLine(renderer,x1+int(10*size),y1-int(29*size),x1,y1-int(29*size),col,1);
    drawLine(renderer,x1,y1-int(29*size),x1-int(4*size),y1-int(27*size),col,1);

    //Left Cheek
    drawLine(renderer,x1,y1,x1-int(2*size),y1-int(3*size),col,1);
    drawLine(renderer,x1-int(2*size),y1-int(3*size),x1-int(2*size),y1-int(8*size),col,1);
    drawLine(renderer,x1-int(2*size),y1-int(8*size),x1-int(3*size),y1-int(8*size),col,1);
    drawLine(renderer,x1-int(3*size),y1-int(8*size),x1-int(6*size),y1-int(15*size),col,1);
    drawLine(renderer,x1-int(6*size),y1-int(15*size),x1-int(6*size),y1-int(22*size),col,1);
    drawLine(renderer,x1-int(6*size),y1-int(22*size),x1-int(4*size),y1-int(27*size),col,1);

    //Eyes
    drawHollowRect(renderer,x1-int(1*size),y1-int(22*size),int(5*size),int(5*size),col);
    drawHollowRect(renderer,x1+int(8*size),y1-int(22*size),int(5*size),int(5*size),col);

    //Halo
    drawHollowRect(renderer,x1-int(7*size),y1-int(38*size),int(24*size),int(5*size),col);
}

void drawPetalL(SDL_Renderer* renderer,int x, int y,float size, rgbColor col){
    drawLine(renderer,x,y,x+int(5*size),y,col,1);
    drawLine(renderer,x+int(5*size),y,x+int(10*size),y-int(3*size),col,1);
    drawLine(renderer,x+int(10*size),y-int(3*size),x+int(12*size),y-int(9*size),col,1);

    drawLine(renderer,x,y,x+int(2*size),y-int(6*size),col,1);
    drawLine(renderer,x+int(2*size),y-int(6*size),x+int(7*size),y-int(9*size),col,1);
    drawLine(renderer,x+int(7*size),y-int(9*size),x+int(12*size),y-int(9*size),col,1);
}
void drawPetalR(SDL_Renderer* renderer,int x, int y,float size, rgbColor col){
    drawLine(renderer,x,y,x-int(5*size),y,col,1);
    drawLine(renderer,x-int(5*size),y,x-int(10*size),y-int(3*size),col,1);
    drawLine(renderer,x-int(10*size),y-int(3*size),x-int(12*size),y-int(9*size),col,1);

    drawLine(renderer,x,y,x-int(2*size),y-int(6*size),col,1);
    drawLine(renderer,x-int(2*size),y-int(6*size),x-int(7*size),y-int(9*size),col,1);
    drawLine(renderer,x-int(7*size),y-int(9*size),x-int(12*size),y-int(9*size),col,1);
}
void drawPetalU(SDL_Renderer* renderer,int x, int y,float size, rgbColor col){
    drawLine(renderer,x,y,x+int(4*size),y-int(5*size),col,1);
    drawLine(renderer,x+int(4*size),y-int(5*size),x,y-int(10*size),col,1);
    drawLine(renderer,x,y,x-int(4*size),y-int(5*size),col,1);
    drawLine(renderer,x-int(4*size),y-int(5*size),x,y-int(10*size),col,1);
}
void drawWheat(SDL_Renderer* renderer, int x, int y,float size,rgbColor col){
    drawPetalL(renderer,x,y,size,col);
    drawPetalL(renderer,x,y-7,size,col);
    //drawPetalL(renderer,x,y-14,size,col);

    drawPetalR(renderer,x-2,y,size,col);
    drawPetalR(renderer,x-2,y-7,size,col);
    //drawPetalR(renderer,x-2,y-14,size,col);
    drawLine(renderer,x-1,y,x-1,y-15,col,2);
}
void drawPlant(SDL_Renderer* renderer, int x, int y,float size,rgbColor col){
    drawPetalL(renderer,x,y,size,col);
    drawPetalR(renderer,x-2,y,size,col);
    drawPetalU(renderer,x-1,y,size,col);
}
void drawAntler(SDL_Renderer* renderer,int x, int y, float size, rgbColor col){
    //Chin
    drawLine(renderer,x,y,x+int(5*size),y,col,1);
    
    //Right Face
    drawLine(renderer,x+int(5*size),y,x+int(9*size),y-int(9*size),col,1);
    drawLine(renderer,x+int(9*size),y-int(9*size),x+int(9*size),y-int(14*size),col,1);
    drawLine(renderer,x+int(9*size),y-int(14*size),x+int(7*size),y-int(16*size),col,1);

    //Left Face
    drawLine(renderer,x,y,x-int(4*size),y-int(9*size),col,1);
    drawLine(renderer,x-int(4*size),y-int(9*size),x-int(4*size),y-int(14*size),col,1);
    drawLine(renderer,x-int(4*size),y-int(14*size),x-int(2*size),y-int(16*size),col,1);

    //Top of Face
    drawLine(renderer,x-int(2*size),y-int(16*size),x+int(7*size),y-int(16*size),col,1);

    //Left Antler
    drawLine(renderer,x-int(3*size),y-int(15*size),x-int(12*size),y-int(17*size),col,1);
    drawLine(renderer,x-int(12*size),y-int(17*size),x-int(13*size),y-int(27*size),col,1);
    drawLine(renderer,x-int(7*size),y-int(17*size),x-int(4*size),y-int(25*size),col,1);

    //Right Antler
    drawLine(renderer,x+int(8*size),y-int(15*size),x+int(17*size),y-int(17*size),col,1);
    drawLine(renderer,x+int(17*size),y-int(17*size),x+int(17*size),y-int(27*size),col,1);
    drawLine(renderer,x+int(12*size),y-int(17*size),x+int(9*size),y-int(25*size),col,1);
}
void drawTile(SDL_Renderer* renderer,int x, int y,tile curTile,int tileWidth,int tileHeight)
{
    int col=curTile.getHeat();
    int height=curTile.getHeight();
    int weightedHeight=(height*(tileHeight/3))/100;

    int align=curTile.getAlign();

    rgbColor wCol=rgbColor();
    wCol.setViaStr(col);

    rgbColor lineCol=rgbColor();
    lineCol.setAll(0,0,0);
    //lineCol.setA((std::abs(height)*255)/100);

    rgbColor faunaCol=rgbColor();
    faunaCol.setAll(0,0,0);
    faunaCol.setA((curTile.getFauna()*255)/100);

    rgbColor plantCol=rgbColor();
    plantCol.setAll(0,0,0);
    plantCol.setA((curTile.getVeg()*255)/100);

    rgbColor waterCol=rgbColor();
    waterCol.setAll(0,0,255);
    waterCol.setA((curTile.getWater()*255)/100);

    rgbColor alignCol=rgbColor();
    alignCol.setAll(0,0,0);
    alignCol.setA((std::abs(align)*255)/100);

    drawRect(renderer,x,y,tileWidth-1,tileHeight-1,wCol);
    drawChev(renderer,x+2,(x)+tileWidth-4,(y)+(tileHeight/2),weightedHeight,lineCol,3);
    drawRect(renderer,x+(tileWidth/8)+5,y+(tileHeight/2)+2,(3*tileWidth/4)-10,tileHeight/16,waterCol);

    if (align<0){
        drawSkull(renderer,x+(tileWidth/2)-4,y+(tileHeight/2),.5,alignCol);               
    }else{
        drawHalo(renderer,x+(tileWidth/2)-4,y+(tileHeight/2),.5,alignCol);                
    }
    drawPlant(renderer,x+(tileWidth/5),y+((tileHeight*15)/16),.5,plantCol);
    drawAntler(renderer,x+((tileWidth*5)/6)-1,y+((tileHeight*15)/16)+1,.5,faunaCol);
}