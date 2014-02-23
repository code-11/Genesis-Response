#include "mat.h"


int main(){
	static const int size=10;

	terrainGenerator* testGenerator= new terrainGenerator();
	testGenerator->generate(map);
	delete testGenerator;
	delete map;
	return 1;

}