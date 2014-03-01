#include "boost/multi_array.hpp"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "tile.h"

typedef boost::multi_array<tile,2> matrix;
typedef matrix::index index;
typedef std::string string;

class terrainGenerator{
protected:
	int sizeX;
	int sizeY;
	matrix map;
	boost::random::mt19937 gen;
public:
	terrainGenerator (int newSizeX, int newSizeY){
		
		sizeX=newSizeX;
		sizeY=newSizeY;
		map.resize(boost::extents[newSizeX][newSizeY]); 
	}
	// int makeRand(int a,int b){
	// 	boost::random::uniform_int_distribution<> dist(a,b);
	// 	return dist(gen);
	// }
    void cornerGen(){
		for (index y=0; y<sizeY; ++y){
			for (index x=0; x<sizeX; ++x){
				map[x][y]=tile(1,50,1,1,1,1);
			}
		}
		//std::cout<<map[5][5].getHeight();

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

