#include "stdafx.h"
#include <iostream>

using namespace std;


int calDay(int M, int N, int x, int y) {

	int lcm = M*N;
	int M_count = x;
	int N_count = y;


	while (M_count <=M*N  && N_count <= N*M) {

		if (M_count > N_count)
			N_count += N;
		else if (M_count < N_count)
			M_count += M;
		else {
			cout << M_count << endl;
			return 0;
		}
	}

	cout << "-1" << endl;
	return 0;
}


int main()
{
	int testcase;

	cin >> testcase;

	int M, N, x, y;

	for (int i = 0; i < testcase; i++) {
		cin >> M >> N >> x >> y;
		calDay(M, N, x, y);
	}


}