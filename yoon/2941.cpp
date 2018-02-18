#include<iostream>

using namespace std; 
#define length 200
int main() 
{
	
	char input[length] = {"\0"};
	int i = 0; 
	int count = 0; 

	cin >> input; 

	while(input[i] != '\0')
	{	 
		if(input[i] == 'c')
		{
			if(input[i+1] !='\0' && input[i+1] == '=')
				{count++; 
				i = i+2;
				}
			else if(input[i+1] !='\0' && input[i+1] == '-')
				{count++; 
				i = i+2;
				}
			else
			{
				count++; 
				i = i+1; 
			}
		}
		else if(input[i] =='d')
			{
				if(input[i+1] != '\0' && input[i+1] == 'z')
				{	if(input[i+2] == '=')
					{count++;
				 	i = i+3;// 'dz='의 경우 i+2까지는 탐색할 필요가 없으므로 i+3부터 재탐색 시키기 위해  i+3을 해준다.
				
					}
					else{// dz 일 경우 d는 단일 알파벳으로 count되어야 함. 
						count++;
						i = i+1;
					}
				}
				else if(input[i+1]!= '\0' && input[i+1] == '-')
				{
					count++;
					i = i+2;
				}
				else // dd 와 같이 사전에 없는 단어가 나타날 경우 
				{
					count++;
					i = i+1; 
				}
			}
		else if(input[i] =='l'|| input[i]=='n')
		{
			if(input[i+1] == 'j')
			{
			count++;
			i = i+2;
			}
			else
			{
				count++;
				i = i+1;
			}

		}
		else if(input[i] =='s' || input[i] =='z')
		{
			if(input[i+1] == '=')
			{
			count++;
			i = i+2;
			}
			else
			{
				count++;
				i = i+1;
			}
		}
		else if(input[i] >96 && input[i]<123)
		{
			count++;
			i = i+1;
		}
		else 
			i = i+1; 
		
	}// while 문의 끝 
	cout << count; 
}


