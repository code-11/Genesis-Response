
/*
	r   g   b
*	0	0 	255
*	0	42	255
*	0 	85	255
*	0	128	255
*	0 	170 255
	0 	213 255
	0	255 255
	0	255 213
	0	255 170
	0 	255 128
	0	255 85
	0	255 42
	0	255 0
	43	255 0
	85	255 0
	128 255 0
	170 255 0
	212 255 0
	255 255 0
	255 213 0
	255 170 0
	255 128 0
	255 85  0
	255 42  0
	255 0   0
*/

class rgbColor{
private:
	int r;
	int g;
	int b;
	int a;
public:
	rgbColor(){
		r=0;
		g=0;
		b=0;
		a=255;
	}
	// rgbColor(int newR,int newG,int newB){
	// 	r=newR;
	// 	g=newG;
	// 	b=newB;
	// }
	int getR(){
		return r;
	}
	int getG(){
		return g;
	}
	int getB(){
		return b;
	}
	int getA(){
		return a;
	}
	void setR(int newR){
		r=newR;
	}
	void setG(int newG){
		g=newG;
	}
	void setB(int newB){
		b=newB;
	}
	void setA(int newA){
		a=newA;
	}
	void setAll (int newR,int newG,int newB){
		r=newR;
		g=newG;
		b=newB;
	}
	void setViaStr(int str)
	{
		if ((str>=0) && (str<5))
			setAll(0,213,255);
		else if ((str>=5) && (str<10))
			setAll(0,255,255);
		else if ((str>=10) && (str<15))
			setAll(0,255,213);
		else if ((str>=15) && (str<20))
			setAll(0,255,170);
		else if ((str>=20) && (str<25))
			setAll(0,255,128);
		else if ((str>=25) && (str<30))
			setAll(0,255,85);
		else if ((str>=30) && (str<35))
			setAll(0,255, 4);
		else if ((str>=35) && (str<40))
			setAll(0,255,0);
		else if ((str>=40) && (str<45))
			setAll(43,255,0);
		else if ((str>=45) && (str<50))
			setAll(85,255,0);
		else if ((str>=50) && (str<55))
			setAll(128,255,0);
		else if ((str>=55) && (str<60))
			setAll(170,255,0);
		else if ((str>=60) && (str<65))
			setAll(212,255,0);
		else if ((str>=65) && (str<70))
			setAll(255,255,0);
		else if ((str>=70) && (str<75))
			setAll(255,213,0);
		else if ((str>=75) && (str<80))
			setAll(255,170,0);
		else if ((str>=80) && (str<85))
			setAll(255,128,0);
		else if ((str>=85) && (str<90))
			setAll(255,85,0);
		else if ((str>=90) && (str<95))
			setAll(255,42,0);
		else if ((str>=95) && (str<=100))
			setAll(255,0,0);
	}
};

