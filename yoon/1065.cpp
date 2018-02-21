#include<iostream>
using namespace std; 


int main()
{
	int n =0, sum = 0;
	cin >> n; 
	
	if( n<100)
	{
		sum = n; 
	}
	else 
	{
		sum = 99;
		for(int i = 100; i<=n; i++)
		{
			int digit3 = i/100;
			int digit2 = i%100/10;
			int digit1 = i%10;
			if((digit3-digit2)==(digit2-digit1))
			sum++;
		}
	}
	cout << sum;
}
