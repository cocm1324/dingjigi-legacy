#include <stdio.h>
#include <iostream>

using namespace std;

int edgeCalc(int, int, int, int);

int main(){
	int x, y, w, h;
	int answer = 0;
		
	scanf("%d %d %d %d", &x, &y, &w, &h);

	answer = edgeCalc(x, y, w, h);

	printf("%d\n", answer);

	return 0;
}

int edgeCalc(int x, int y, int w, int h){
	int ret;
	int bestX, bestY;	

	if(w - x < x){
		bestX = w - x;
	}
	else{
		bestX = x;
	}

	if(h - y < y){
		bestY = h - y;
	}
	else{
		bestY = y;
	}

	if(bestX > bestY){
		ret = bestY;
	}
	else{
		ret = bestX;
	}
	
	return ret;
}

