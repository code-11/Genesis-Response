//g++ viewerMain.cpp -o bin/viewer -lSDL2 <-For deposit into bin file
//g++ viewerMain.cpp -o viewer <------------If not

#include "mapViewer.h"

int main( int argc, char* args[] )
{
	mapViewer* viewer=new mapViewer();

	viewer->importMap("testFileIO.txt");
	viewer->runDisplay();
	return 0;
}