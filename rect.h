class rect{
private:
	int bigX;
	int smallX;
	int bigY;
	int smallY;
public:	
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
	}
	bool equals(rect other){
		bool a=(smallX==other.getSmallX());
		bool b=(smallY==other.getSmallY());
		bool c=(bigX==other.getBigX());
		bool d=(bigY==other.getBigY());
		return ((a && b) && (c && d));
	}

	bool contains(int x, int y){
		return (((x<=bigX) && (x>=smallX)) && ((y<=bigY) && (y>=smallY)));
	}

	//Figures out if any part of the rectangle is outside any part of another
	bool inBounds(rect bounds){
		return (bounds.contains(smallX,smallY) && bounds.contains(bigX,bigY));
	}
	void confine(rect bounds){
		if (bigX>bounds.getBigX()){
			bigX=bounds.getBigX();
		} 
		if (bigY>bounds.getBigY()){
			bigY=bounds.getBigY();
		} 
		if (smallX<bounds.getSmallX()){
			smallX=bounds.getSmallX();		
		} 
		if (smallY<bounds.getSmallY()){
			smallY=bounds.getSmallY();
		}
	}
	void print(){
		std::cout<<"SmallX "<<smallX<<", SmallY"<<smallY<<", BigX"<<bigX<<", BigY"<<bigY;
	}
};