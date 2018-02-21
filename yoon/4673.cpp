#include<iostream>

using namespace std; 
int self_number(int n);
int main() 
{	int n = 0;
	int array[10000] = {0,};
	for(int i = 1; i<10000; i++)
		array[i] = self_number(i);
	for(int i = 1; i <10000; i++)
	{
		for(int j = 0; j<10000;j++)
		{
			if(i==array[j])
				break;
			else if(j==9999)
				cout << i<<endl; 
		}
	}

}

int self_number(int n){
	int answer = n+ n/1000 + (n%1000)/100 + (n%100)/10 + (n%10);  // 셀프넘버는 이 계산식으로 만들어 질 수 없다. 
	return answer; 
}
