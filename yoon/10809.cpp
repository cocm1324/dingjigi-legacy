#include<iostream>
using namespace std;
#define length 100
void classifier();
int main()
{
    classifier();
    
}
//소문자 아스키코드는 97 번 부터 122번까지 
void classifier() 
{
	int i =0, j = 0, k = 0;  // i 는 input배열의 인덱스를 나타내기 위한 것, j는 아스키코드 
    int array[26]={-1,};
    fill_n(array,26,-1);
	char input[length] = {'\0', };
	cin >> input;
	for(i = 0; i < sizeof(input); i++)
	{	for( j = 97,k=0; (j<123) && (k<26); j++,k++)//소문자 a 부터 z까지 순차적으로 비교,
		{
			if(input[i] == j)// i번쨰 인덱스에 있는 값이 아스키 값 j에 해당한다면,
            {
                if(array[k]!=-1)//배열 array에 들어가 있는 k 번째 인덱스 값이 -1이 아닐경우 다음 for문으로 넘어간다.
                    continue;
                else// i번째 인덱스에 있는 값 j가 처음 나온 값이라면,
                    array[k]=i;// k번째 알파벳에 들어갈 숫자는 인덱스 i이다.
                //i번째 인덱스의 값이 j와 같다면, array[k]올린다.
            }
		}
	}
	for(i = 0; i< 26; i++)
	{
        cout << array[i]<<" ";
        
    }
//97 ->0, 122 -> 26



}
