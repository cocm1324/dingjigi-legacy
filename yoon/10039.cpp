#include<iostream>
using namespace std; 

int main() 
{
	int i = 0 , sum = 0, input = 0;  
	for ( i = 0; i < 5; i++)
	{
		cin >> input; 
		if(input < 40)
			sum+=40;
		else
			sum+=input;
	}
	cout << sum/5;

}

// 단순한 평균 구하는 프로그램 
