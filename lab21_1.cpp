#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1,Rect R2){
	double sumw=0,sumh=0;
	// R2 x in R1 x
	if (((R2.x) >= (R1.x)) && ((R2.x+R2.w) <= (R1.x+R1.w))){
		sumw = R2.w;
	}
	// R2 y in R1 y
	if((R2.y <= R1.y) && ((R2.y-R2.h) >= (R1.y-R1.h))){
		sumh = R2.h;
	}
	// R1 x < R2 x
	if(R1.x <= R2.x){
		if(R1.x+R1.w >= R2.x ){
			if (sumw == 0) sumw = (R1.w)-(R2.x-R1.x);
			// R1 y < R2 y
			if(R1.y < R2.y ){
				if(R1.y-R1.h <= R2.y){
					if (sumh == 0) sumh = (R1.h)-(R2.y-R1.y);
				}
			}
			// R1 y > R2 y
			if(R1.y > R2.y){
				if(R2.y-R2.h <= R1.y){
					if (sumh == 0) sumh = (R2.h)-(R1.y-R2.y);
				}
			}
		}
	}
	// R1 x in R2 x
	if (((R1.x) >= (R2.x)) && ((R1.x+R1.w) <= (R2.x+R2.w))){
		sumw = R1.w;
	}
	// R1 y in R2 y
	if((R1.y <= R2.y) && ((R1.y-R1.h) >= (R2.y-R2.h))){
		sumh = R1.h;
	}
	if(R1.x >= R2.x){
		if(R2.x+R2.w >= R1.x ){
			if (sumw == 0) sumw = (R2.w)-(R1.x-R2.x);
			// R1 y < R2 y
			if(R1.y < R2.y ){
				if(R1.y-R1.h < R2.y){
					if (sumh == 0) sumh = (R1.h)-(R2.y-R1.y);
				}
			}
			// R1 y > R2 y
			if(R1.y >= R2.y){
				if(R2.y-R2.h < R1.y){
					if (sumh == 0) sumh = (R2.h)-(R1.y-R2.y);
				}
			}
		}
	}
	return sumh*sumw;
}