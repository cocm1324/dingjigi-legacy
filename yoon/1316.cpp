#include<iostream>
using namespace std;
#include<string.h> 
#include<string>
int group_check(string);

int main()
{
	int group_number = 0;
	int testcase = 0; 
	string input = "";  		
	cin >> testcase;
	for( int i = 0; i  < testcase; i++)
	{	cin >> input;
		group_number +=group_check(input);

	}
	cout << group_number; 

}

int group_check(string input){
	int length = input.length();
	int zero = 0; 
	int count = 1; 
	for(int i = 0; i <length; i++){
		for(int j = (length-1); j> i ; j--){
			if(input[i] == input[j])
			{
				if(input[j] != input[j-1])// 판별식을 통과하지 못했으면, 
				{	
					return zero; // count에 넣지 않기 위해 0을 리턴해준다.
				}
			}
			//i번쨰 탐색했는데, 같은 알파벳 안나오면 다음 i+1번으로 넘어간다. 
		}
		//for문을 무사하게 돌렸으면 그룹단어라고 판단, count 해준다. 

	}
	return count;


}
