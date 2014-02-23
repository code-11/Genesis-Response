class tile{
protected:
	int height;

	int water;
	int heat;

	int vegetation;
	int fauna;


	int alignment;
public:
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