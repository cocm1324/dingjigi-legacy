#include<iostream>
#include<map>
#include<vector>
#include<stdlib.h>
using namespace std;

int main()
{
	int max_value =0;
	int max_index;
	char N[7]={'\0',};
	cin >> N;
	/*//////////////////////////////
	for(int j = 0; j<sizeof(N);j++){
		cout <<"j: "<< N[j]<<endl;
	}
	*////////////////////////////////
	int *a = (int *)malloc((sizeof(int))*(sizeof(N)-1));
	for(int j = 0; j<sizeof(N)-1; j++){
		*(a+j) = N[j]-'0';
	}
	/*//////////////////////////////
	for(int i = 0 ; i<sizeof(a);i++)
	{
		cout << a[i] <<endl;
	}
	/*//////////////////////////////
	map<int,int> m;
	map<int,int>::iterator i;
	for(int j = 0;j<10; j++){
		m.insert(pair<int,int>(j,0));
	}
	for(int j = 0;j<sizeof(N)-1; j++){
		int index = *(a+j);
		/*//////////////////////////////
		cout <<"index: " <<index <<endl; 
		*////////////////////////////////
		m[index]+=1;
	}
	/*//////////////////////////////
	for(int j = 0; j <10; j++){
		cout << "m["<<j<<"]: " << m[j]<<endl;
	}
	/*//////////////////////////////
	for(int j=0; j<10;j++){
	 if( j!=6 && j!=9){
		if(max_value < m[j]){
			max_value = m[j];
			max_index = j;
		}
		else continue;
	 }
	 else continue;
	}
	/*//////////////////////////////
	cout << "max_value: " << max_value<<endl;
	cout << "max_index: " << max_index<<endl;
	/*//////////////////////////////
	int value_6=m[6];
	int value_9=m[9];
	if(max_value>=value_9 && max_value>=value_6)
		cout << max_value<<endl;
	else if(max_value< value_6 || max_value < value_9){
		if((value_6 + value_9)% 2 ==1)
		{
			cout << ((value_6 + value_9)/2) +1 <<endl;
		}
		else
		{
			cout << ((value_6 + value_9)/2) <<endl;
		}
	}

}
