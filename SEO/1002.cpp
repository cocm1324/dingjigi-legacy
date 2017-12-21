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

float getDistance(Circle &c1, Circle &c2) {
	float distance;

	distance = sqrt(pow(abs(c1.getxPos() - c2.getxPos()), 2) + pow(abs(c1.getyPos() - c2.getyPos()), 2));

	return distance;
}

float CircleCheckVar(Circle &c1, Circle &c2) {

	float radsum = (c1.getRadius() + c2.getRadius());
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

		if (CircleCheckVar(C1, C2) > 0)
		{
			cout << 0 << endl;
		}
		else if (CircleCheckVar(C1, C2) == 0) {
			cout << 1 << endl;
		}
		else if(CircleCheckVar(C1, C2) < 0){

			if (getDistance(C1, C2) == abs(C1.getRadius() - C2.getRadius())) {

				if (abs(C1.getRadius() - C2.getRadius()) == 0)
					cout << -1 << endl;
				else
					cout << 1 << endl;
			}
			else if(getDistance(C1,C2) < abs(C1.getRadius()-C2.getRadius())){
				cout << 0 << endl;
			}
			else {
				cout << 2 << endl;
			}
		}
		

	}

}