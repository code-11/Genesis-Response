//g++ creatorMain.cpp -o creator -std=c++11
#include "mat.h"


int main(){
	static const int size=2;

	terrainGenerator* testGenerator= new terrainGenerator(22,13);
	// testGenerator->pointGen(5,12);
	testGenerator->topLeftCornerGen();
	testGenerator->exportMap("testFileIO.txt");
	delete testGenerator;
	return 1;

}