//g++ creatorMain.cpp -o creator -std=c++11
#include "mat.h"


int main(){
	static const int size=2;

	terrainGenerator* testGenerator= new terrainGenerator(2,3);
	testGenerator->topLeftCornerGen();
	testGenerator->exportMap("testFileIO.txt");
	delete testGenerator;
	return 1;

}