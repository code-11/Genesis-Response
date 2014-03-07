class rect{
private:
	int x1;
	int x2;
	int y1;
	int y2;
	int bigX;
	int smallX;
	int bigY;
	int smallY;
public:	
	int getX1(){
		return x1;
	}
	int getY1(){
		return y1;
	}
	int getY2(){
		return y2;
	}
	int getX2(){
		return x2;
	}
	int getBigX(){
		return bigX;
	}
	int getSmallX(){
		return smallX;
	}
	int getBigY(){
		return bigY;
	}
	int getSmallY(){
		return smallY;
	}
	rect(){
		int x1=0;
		int x2=0;
		int y1=0;
		int y2=0;
		int bigX=0;
		int smallX=0;
		int bigY=0;
		int smallY=0;
	}
	rect(int X1,int Y1,int X2,int Y2){
		if (X1>X2){
			bigX=X1;
			smallX=X2;
		}else{
			smallX=X1;
			bigX=X2;
		}
		if (Y1>Y2){
			bigY=Y1;
			smallY=Y2;
		}else{
			smallY=Y1;
			bigY=Y2;
		}
		x1=X1;
		y1=Y1;
		x2=X2;
		y2=Y2;
	}
	bool contains(int x, int y){
		return (((x<=bigX) && (x>=smallX)) && ((y<=bigY) && (y>=smallY)));
	}

	//Figures out if any part of the rectangle is outside any part of another
	bool outOfBounds(rect bounds){
		return (bounds.contains(x1,y1) && bounds.contains(x2,y2));
	}
};