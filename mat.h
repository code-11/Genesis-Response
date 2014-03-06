#include "boost/multi_array.hpp"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "tile.h"
#include <ctime>

typedef boost::multi_array<tile,2> matrix;
typedef matrix::index index;
typedef std::string string;

class terrainGenerator{
protected:
	int sizeX;
	int sizeY;
	matrix map;
	long tiempo=std::time(0);
	boost::random::mt19937 gen;

public:
	terrainGenerator (int newSizeX, int newSizeY){
		gen.seed(static_cast<unsigned int>(tiempo));
		sizeX=newSizeX;
		sizeY=newSizeY;
		map.resize(boost::extents[newSizeX][newSizeY]); 
	}
	int makeRand(int a,int b){
		boost::random::uniform_int_distribution<> dist(a,b);
		return dist(gen);
	}
	void testGen(){
		for (index y=0; y<sizeY; ++y){
			for (index x=0; x<sizeX; ++x){
				if ((x==5) && (y==5))
					map[x][y]=tile(0,0,0,1,1,0);
				else if ((x==5) && (y==6))
					map[x][y]=tile(100,0,0,0,0,-100);
				else if ((x==6) && (y==5))
					map[x][y]=tile(50,100,0,0,0,-100);
				else if ((x==6) && (y==6))
					map[x][y]=tile(0,50,100,0,0,-100);
				else if ((x==4) && (y==5))
					map[x][y]=tile(0,0,50,100,0,50);
				else if ((x==5) && (y==4))
					map[x][y]=tile(0,0,0,50,100,-50);
				else
					map[x][y]=tile(-100,80,50,1,1,-50);
			}
		}
	}
	tile randomTile(){
		int tempHeight=makeRand(-100,100);
		int tempWater =makeRand( 0  ,100);
		int tempHeat  =makeRand( 0  ,100);
		int tempVeg   =makeRand( 0  ,100);
		int tempFauna =makeRand( 0  ,100);
		int tempAlign =makeRand(-100,100);
		return tile(tempHeight,tempWater,tempHeat,tempVeg,tempFauna,tempAlign);
	}
	bool boundsCheck(int desX,int desY){
		if ((desX<0) || (desX>sizeX-1)){
			return false;
		}else if ((desY<0) || (desY>sizeY-1)){
			return false;
		}else{
			return map[desX][desY].getHeight()!=-101;
		}
	}
	tile averageTile(index x,index y){
		tile average=tile(0,0,0,0,0,0);
		int many=0;
		if (boundsCheck(x-1,y)==true){
			average.add(map[x-1][y]);
			many+=1;
			// std::cout<<"including left\n";
		}
		if (boundsCheck(x+1,y)==true){
			average.add(map[x+1][y]);
			many+=1;
			// std::cout<<"including right\n";
		}
		if (boundsCheck(x,y-1)==true){
			average.add(map[x][y-1]);
			many+=1;
			// std::cout<<"including up\n";
		}
		if (boundsCheck(x,y+1)==true){
			average.add(map[x][y+1]);
			many+=1;
			// std::cout<<"including down\n";
		}
		average.divide(many);
		// std::cout<<"averaging "<<many<<" at"<<x<<","<<y<<"\n" ;
		return average;


		// tile right=map[x+1][y];
	}
    void topLeftCornerGen(){
    	int heightDrift=10;
    	int waterDrift=5;
    	int heatDrift=5;
    	int vegDrift=5;
    	int faunaDrift=5;
    	int alignDrift=5;
		for (index y=0; y<sizeY; ++y){
			for (index x=0; x<sizeX; ++x){
				map[x][y]=tile(-101,0,0,0,0,0);
			}
		}
		// index y=0;
		for (index x=0; x<sizeX; x+=1){
			for (index y=0; y<sizeY; y+=1){
				if ((x==0) && (y==0)){
					map[x][y]=randomTile();
				}else{
					map[x][y]=averageTile(x,y);
				}
			}
		}

	}
	void exportMap(const std::string filePath){
		std::ofstream outFile (filePath, std::ios::out);
		outFile<<"XDimension,"<<sizeX<<",YDimension,"<<sizeY<<"\n";
		outFile<<"x,y,height,water,heat,vegetation,fauna,alignment\n";
		for (index y=0; y<sizeY;++y){
			for (index x=0; x<sizeY; ++x){
				tile temp= map[x][y];
				outFile<<x<<","<<y<<","<<temp.getHeight()<<","<<temp.getWater()<<","<<temp.getHeat()<<","<<temp.getVeg()<<","<<temp.getFauna()<<","<<temp.getAlign()<<"\n";
			}
		}
		outFile.close();

	}
};

