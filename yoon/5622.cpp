#include<iostream>
using namespace std; 
#define length 15

int dial(char);
int main() 
{   int sum = 0; 
	int i = 0;
	char phonenumber[length] = {"\0"};

	cin >> phonenumber; 

	while(phonenumber[i] != '\0')
	{
		sum += dial(phonenumber[i]);

		i++; 
	}
	cout <<sum; 
}


int dial(char input){
	int seconds =2;
	if(input == 'A' || input =='B' || input =='C')
		return ++seconds;
	else if(input == 'D' || input == 'E' || input == 'F')
	{
		return (seconds+2);
	}
	else if(input == 'G' || input == 'H' || input == 'I')
		return (seconds+3);
	else if(input == 'J' || input == 'K'|| input == 'L')
		return (seconds+4);
	else if(input == 'M' || input == 'N' || input == 'O')
		return (seconds+5);
	else if(input == 'P' || input == 'Q' || input == 'R' || input == 'S')
		return (seconds+6); 
	else if(input =='T'|| input == 'U'|| input =='V')
		return (seconds+7);
	else 
		return (seconds+8); 


}
