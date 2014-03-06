class tile{
protected:
	int height; 	//The height of the biome from -100 to 100

	int water; 		//The water level of the biomes from 0 to 100
	int heat; 		//The heat level of the biome from 0 to 100

	int vegetation; //0 to 100
	int fauna; 		//0 to 100


	int alignment;	//-100 to 100
public:
	tile(){
		height=1;
	}
	tile(int Height){
		height=Height;
	}
	tile(int Height,int Water,int Heat,int Veg, int Fauna, int Alignment){
		height=Height;
		water=Water;
		heat=Heat;
		vegetation=Veg;
		fauna=Fauna;
		alignment=Alignment;
	}
	void divide(int scale){
		height/=scale;
		water/=scale;
		heat/=scale;
		vegetation/=scale;
		fauna/=scale;
		alignment/=scale;
	}
	void add(tile that){
		height+=that.getHeight();
		water+=that.getWater();
		heat+=that.getHeat();
		vegetation+=that.getVeg();
		fauna+=that.getFauna();
		alignment+=that.getAlign();
	}
	void check(){
		if (height<-100){
			height=-100;
		}else if (height>100){
			height=100;
		}
		if (water<0){
			water=0;
		}else if (water>100){
			water=100;
		}
		if (heat<0){
			heat=0;
		}else if (heat>100){
			heat=100;
		}
		if (vegetation<0){
			vegetation=0;
		}else if (vegetation>100){
			vegetation=100;
		}
		if (fauna<0){
			fauna=0;
		}else if (fauna>100){
			fauna=100;
		}
		if (alignment<-100){
			alignment=-100;
		}else if (alignment>100){
			alignment=100;
		}
	}
	int getHeight(){
		return height;
	}
	void setHeight(int newHeight){
		height=newHeight;
	}
	int getWater(){
		return water;
	}
	void setWater(int newWater){
		water=newWater;
	}
	int getHeat(){
		return heat;
	}
	void setHeat(int newHeat){
		heat=newHeat;
	}
	int getVeg(){
		return vegetation;
	}
	void setVeg(int newVeg){
		vegetation=newVeg;
	}
	int getFauna(){
		return fauna;
	}
	void setFauna(int newFauna){
		fauna=newFauna;
	}
	int getAlign(){
		return alignment;
	}
	void setAlign(int newAlign){
		alignment=newAlign;
	}
};