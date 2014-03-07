#include "boost/multi_array.hpp"

class meh{
protected:
	int foo;
public:
	meh(){
		foo=1;
	}
};

typedef boost::multi_array<meh,2> matrix;
typedef matrix::index index;



int main(){
	matrix map;
	map.resize(boost::extents[12][12]);

	for (index x=0;x<12;x+=1){
		for (index y=0;y<12;y+=1){
			map[x][y]=meh();
		}
	}


	matrix map2;
	map2.resize(boost::extents[11][12]);

	for (index x=0;x<11;x+=1){
		for (index y=0;y<12;y+=1){
			map2[x][y]=meh();
		}
	}

	matrix map3;
	map3.resize(boost::extents[12][11]);

	for (index x=0;x<12;x+=1){
		for (index y=0;y<11;y+=1){
			map3[x][y]=meh();
		}
	}

	return 0;
}