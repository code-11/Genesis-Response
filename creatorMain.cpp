//g++ creatorMain.cpp -o creator -std=c++11
#include "mat.h"


int main(){
	static const int size=13;

	terrainGenerator* testGenerator= new terrainGenerator(size,size);
	testGenerator->topLeftCornerGen();
	testGenerator->exportMap("testFileIO.txt");
	delete testGenerator;
	return 1;

}