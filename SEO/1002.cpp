# include "stdafx.h"
# include <iostream>
# include <math.h>

using namespace std;

class Circle {
private:
	float xpos;
	float ypos;
	float radius;
public:
	void InitCircle(int x, int y, int r) {
		xpos = x;
		ypos = y;
		radius = r;
	}

	float getxPos(){
		return xpos;
	}

	float getyPos() {
		return ypos;
	}

	float getRadius() {
		return radius;
	}
	
};


// 두 원의 중점 사이의 거리
float getDistance(Circle &c1, Circle &c2) { 
	float distance;

	distance = sqrt(pow(abs(c1.getxPos() - c2.getxPos()), 2) + pow(abs(c1.getyPos() - c2.getyPos()), 2));

	return distance;
}


//두 원의 중점 사이의 거리(d) - 두 워늬 반지름의 합(r1+r2)  -> d - (r1+r2)  
float CircleCheckVar(Circle &c1, Circle &c2) {

	float radsum = (c1.getRadius() + c2.getRadius()); //두 원의 반지름의 합
	float distance = getDistance(c1, c2);

	float CircleCheckVar = distance - radsum;

	return CircleCheckVar;
}




int main() {

	Circle C1;
	Circle C2;
	
	int testcase;

	cin >> testcase;

	float c1x;
	float c1y;
	float c1r;

	float c2x;
	float c2y;
	float c2r;

	for (int i = 0; i < testcase; i++)
	{
		cin >> c1x >> c1y >> c1r >> c2x >> c2y >> c2r;

		C1.InitCircle(c1x, c1y, c1r);
		C2.InitCircle(c2x, c2y, c2r);

		if (CircleCheckVar(C1, C2) > 0) //1. 원이 바깥에서 서로 만나지 않을 경우
		{
			cout << 0 << endl;
		}
		else if (CircleCheckVar(C1, C2) == 0) { //2. 원이 외접할 경우
			cout << 1 << endl;
		}
		else if(CircleCheckVar(C1, C2) < 0){

			if (getDistance(C1, C2) == abs(C1.getRadius() - C2.getRadius())) {

				if (abs(C1.getRadius() - C2.getRadius()) == 0) //3. 두 원이 일치할 경우
					cout << -1 << endl;
				else
					cout << 1 << endl; //4. 두 원이 내접하는 경우
			}
			else if(getDistance(C1,C2) < abs(C1.getRadius()-C2.getRadius())){ // 5. 한 원이 한 원을 포함하는 경우
				cout << 0 << endl;
			}
			else {
				cout << 2 << endl; //6. 나머지 경우  => 두 원의 교점의 개수 = 2
			}
		}
		

	}

}