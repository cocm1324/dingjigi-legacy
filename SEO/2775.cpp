#include "stdafx.h"
#include <iostream>

using namespace std;

int test_case;
int k, n;
int apt[15][15];
int result;


int main() {

	for (int i = 0; i < 15; i++) {
		for (int j = 1; j < 15; j++) {

			int sum = 0;

			if (i == 0) {
				apt[i][j] = j;
			}
			else {
				for (int k = 1; k <= j; j++) {
					sum += apt[i - 1][k];
				}

				apt[i][j] = sum;
			}

		}
	}

	
	cin >> test_case;

	

	for (int i = 0; i < test_case; i++) {
		cin >> k >> n;

		result = apt[k][n];

		std::cout << result << std::endl;
		


	}


}

