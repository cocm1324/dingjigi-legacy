// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{

	int input;
	int cur = 0;
	scanf("%d", &input);


	stack<int> S;
	vector<char> V;

	
	for (int i = 0; i < input; i++) {
		int temp;
		scanf("%d", &temp);

		if (S.empty()) {
			for (int i = cur; i < temp; i++) {
				cur++;
				S.push(cur);
				V.push_back('+');
			}
			S.pop();
			V.push_back('-');
		}
		else if (temp == S.top()) {
			S.pop();
			V.push_back('-');
		}
		else if (temp > S.top()) {

			if (temp < cur) {
				printf("NO");
				return 0;
			}

			while (cur < temp) {
				cur++;
				S.push(cur);
				V.push_back('+');
			}

			S.pop();
			V.push_back('-');
		}
		else {
			while (temp < S.top()) {
				S.pop();
				V.push_back('-');
			}
		}


	}


	for (int i = 0; i < V.size(); i++) {
		printf("%c\n", V[i]);
	}

	return 0;
}

