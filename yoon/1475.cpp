#include<iostream> 
#include<math.h>  
using namespace std;
void classifier();

float Rounding( float x, int digit) //digit 자리까지 반올림 하는 함수 
{
	return(floor((x) * pow(float(10),digit) + 0.5f) / pow(float(10), digit));
}
int main()
{	
 
classifier(); 
}


void classifier() 
{	char c[6] = "";
	float count = 0;
	cin >>c;
	for(int i = 0; i!=sizeof(c); i++)
	{
		if(c[i] == '\0')//배열의 끝이면 for문을 벗어난다.
		{
			
			break;
		}
		else if(i>0)// 두번째 부터 입력할때 
		{   
			
			if((c[i]=='6') || (c[i] == '9')){
				
				count += 0.5;
			}
			else //6,9가 아닐떄
			{   
				for(int j = 0; j < i ; j++)
				{
					if(c[i]==c[j])//이전 배열들의 숫자와 비교해서 같으면 count++  
						count += 1;	
				}
			}
		}	
		else // i = 0 일때 는 무조건 count up 하고 시작한다.  
			{	
				count +=0.5; 
			}
		
	}
	cout <<Rounding(count, 0)<<endl; //최종 계산된 값에서 반올림을 한 후에 결과값을 출력해준다.

}
