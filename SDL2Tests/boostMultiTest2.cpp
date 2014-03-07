#include "boost/multi_array.hpp"

typedef boost::multi_array<int,2> matrix;
typedef matrix::index index;

class myClass{
private:
	matrix myMatrix;
public: 
	myClass(int x,int y){
		myMatrix=myMatrix.resize(boost::extents[x][y]); 
	}
};

int main(){
	myClass foo=myClass(4,5); 
}