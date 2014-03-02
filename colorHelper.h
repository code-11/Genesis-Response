
/*
	r   g   b
	0	0 	255
	0	42	255
	0 	85	255
	0	128	255
	0 	170 255
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
		if ((str>=0) && (str<4))
			setAll(0,0,255);
		else if ((str>=4) && (str<8))
			setAll(0,42,255);
		else if ((str>=8) && (str<12))
			setAll(0,85,255);
		else if ((str>=12) && (str<16))
			setAll(0,128,255);
		else if ((str>=16) && (str<20))
			setAll(0,170,255);
		else if ((str>=20) && (str<24))
			setAll(0,213,255);
		else if ((str>=24) && (str<28))
			setAll(0,255,255);
		else if ((str>=28) && (str<32))
			setAll(0,255,213);
		else if ((str>=32) && (str<36))
			setAll(0,255,170);
		else if ((str>=36) && (str<40))
			setAll(0,255,128);
		else if ((str>=40) && (str<44))
			setAll(0,255,85);
		else if ((str>=44) && (str<48))
			setAll(0,255, 4);
		else if ((str>=48) && (str<52))
			setAll(0,255,0);
		else if ((str>=52) && (str<56))
			setAll(43,255,0);
		else if ((str>=56) && (str<60))
			setAll(85,255,0);
		else if ((str>=60) && (str<64))
			setAll(128,255,0);
		else if ((str>=64) && (str<68))
			setAll(170,255,0);
		else if ((str>=68) && (str<72))
			setAll(212,255,0);
		else if ((str>=72) && (str<76))
			setAll(255,255,0);
		else if ((str>=76) && (str<80))
			setAll(255,213,0);
		else if ((str>=80) && (str<84))
			setAll(255,170,0);
		else if ((str>=84) && (str<88))
			setAll(255,128,0);
		else if ((str>=88) && (str<92))
			setAll(255,85,0);
		else if ((str>=92) && (str<96))
			setAll(255,42,0);
		else if ((str>=96) && (str<=100))
			setAll(255,0,0);
	}
};

