Genesis-Response
================

A 2d tile based terrain generator (actually several) that utilizes an averaged multidimensional random walk to make realistic transitions between tiles.

The executables can be made using the following commands:

g++ creatorMain.cpp -o creator -std=c++11
g++ viewerMain.cpp -o viewer -lSDL2

Note that SDL2 needs to be installed to compile.

An executable is included to allow you to test if SDL is correctly installed. If it works, it should pop up a small window with the sdl logo and "hello world" as the window title.

If for some reason you need to compile the test, use:

	g++ rendererTest.c -o testSDL2 -lSDL2

Once they are compiled, the executables take the following options:

	./viewer filePath
	./creator SizeX SizeY GeneratorType filePath
	
	Where SizeX and Size Y are the requested dimensions of the world.
	      GeneratorType is a number that tells what type of generator algorithm you would like.
	      A more in depth explanation of the algorithms and how they work is located in the comments of mat.h
	      However, if you don't care and just want something now, just try 4.
	      
	       
