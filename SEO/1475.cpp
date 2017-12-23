#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Cardpack {
private:
	int numOfPack = 1;
	int pack[10] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 0 };
	int current[10] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 0 };

public:
	void cardCheck(string str) {
	
		for (int i = 0; i < str.length(); i++) {

			for (int j = 0; j < 10; j++) {

				int value = str[i] - '0';
		

				if (current[value] >= 1){
					current[value]--;
					
					break;
				}
				else {
					current[value]--;
					numOfPack++;
					newpack();
					break;
				}

			}
		}
	}

	int getNumofPack() {
		return numOfPack;
	}

	void newpack() {
		for (int i = 0; i < 10; i++) {
			current[i] += pack[i];
		}
	}
};

int main() {

	int cardpack;
	
	int input;
	
	cin >> input;

	stringstream ss;
	ss << input;
	string str = ss.str();

	Cardpack C1;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '9') {
			str[i] = '6';
		}
	}

	C1.cardCheck(str);
	cardpack = C1.getNumofPack();
	
	cout << cardpack << endl;
}




