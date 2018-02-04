#include<iostream>
#include<string.h>
#define max_length 1000000
using namespace std;  
int main()
{ //대문자 와 소문자간 아스키코드 간격은 32
    bool duple = false; // 최댓값이 중복인지 판별해주는 boolean값
    int max_index = 0; //dictionray에서 몇 번째 인덱스가 가장 큰지 알려주기 위한 변수 추후 이 값을 알파벳으로 변경할 것이다.
    char input[max_length]= {'\0',};
	cin >> input;
    int i = 0; // 조건문에서 사용할 i 변수
	int dictionary[26] ={0,};
    int max = 0; //최댓값을 저장하는변수
    //대문자 A를 0, Z를 25이라하자.
	//dictinary[index]에서  index 0번쨰를 a, index 25번째를 z라고 할 것이다. 
	while(input[i]!='\0') // 입력한 문자열 첫 인덱스 부터 마지막까지 검색
	{
		if(int(input[i]) > 96)// i번째 인덱스가 소문자라면 - 97 한  인덱스에 +1;
            dictionary[int(input[i])-97]++;
		else
			dictionary[int(input[i])-65]++;
        i++;
	} // 검색이 다 끝났으면, 이제 dictionary 배열을 탐색하면서 가장 큰 수가 뭔지 검색
	for(int j= 0; j<26/*sizeof(dictionary)/sizeof(int)*/; j++)
	{
		 
		if( j==0) //  인덱스 0 에서는
        {
			max = dictionary[j]; // dictionary[0]을 최댓값이라고 가정.
			max_index =0; 
        }
        else// 인덱스 1 부터
		{
			if(max < dictionary[j]) //  이전 값보다 j번째 값이 더 크다면
            {
                max = dictionary[j]; //최댓값은 dictionary[j]가 된다.
				duple = false; //새로운 최댓값이 나타났으므로 중복된 값이 아니다. 
				max_index = j; 
            }
            else if( max == dictionary[j]) // 현재 최댓값과 같은 값이 나타났으면
            {
				duple =true; // 중복된 수가 나타났다고 플래그를 올려준다. 
				max = dictionary[j]; // 그리고 max는 현재 탐색한 그 변수의 숫자를 담는다. 최댓값은 바뀌지 않는다. 
				max_index = j;
            }
            else
                continue;
		}		 
	}
    //cout <<endl<<max_index <<endl;
	if(duple==true)//중복된 값이 최댓값이었다면
		cout << "?";
	else
		cout << char(max_index+65); // 알파벳으로 캐스팅해서 출력.

}
