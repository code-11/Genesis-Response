class tile{
protected:
	int height; 	//The height of the biome from 0 to 100

	int water; 		//The water level of the biomes from 0 to 100
	int heat; 		//The heat level of the biome from -100 to 100

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