//g++ creatorMain.cpp -o creator -std=c++11
#include "mat.h"


int main(int argc, char** argv){
	if (argc<4){
		std::cout<<"Usage error. Requires input in the form of: SizeX SizeY GeneratorType filename\n";
		return 1;
	}else{
		std::string strSizeX = argv[1];
		int sizeX = atoi(strSizeX.c_str());

		std::string strSizeY = argv[2];
		int sizeY = atoi(strSizeY.c_str());

		std::string strGen = argv[3];
		int gen = atoi(strGen.c_str());

		std::string filePath =argv[4];

		terrainGenerator* testGenerator= new terrainGenerator(sizeX,sizeY);
		
		if (gen==0){
			testGenerator->testGen();
		}else if (gen==1){
			testGenerator->boringGen();
		}else if (gen==2){
			testGenerator->randomGen();
		}else if (gen==3){
			testGenerator->topLeftCornerGen();
		}else if (gen==4){
			testGenerator->pointGen(sizeX/2,sizeY/2);
		}else{
			std::cout<<"Error, GeneratorType was unexpected number: "<<gen<<". GeneratorType must be a number 0-4.\n";
			return 1;
		}

		testGenerator->exportMap(filePath);
		delete testGenerator;
		return 0;
	}



}