//g++ viewerMain.cpp -o bin/viewer -lSDL2 <-For deposit into bin file
//g++ viewerMain.cpp -o viewer <------------If not

#include "mapViewer.h"

int main( int argc, char* args[] )
{
	mapViewer* viewer=new mapViewer();
	if (argc<2){
		std::cout<<"Usage error. Needs 1 argument. Gave "<<argc-1<<"\n";
		return 1;
	}else{

		std::string filePath =args[1];

		viewer->importMap(filePath);

		viewer->runDisplay();
		return 0;
	}
}