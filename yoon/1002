#include<iostream>
#include<math.h>
using namespace std;

void get_distance();

int main() 
{
	int i = 0; 
	cin >> i; 
	for(int x = 0; x < i; x++)
	{
		get_distance();
	}

}

void get_distance(){
	double a = 0, b =0, c= 0, d=0, e= 0,f = 0;
	cin >> a >>b >> c >> d >> e >> f;
	double result1 =sqrt(pow(double(a-d),2)+pow(double(b-e),2));//원의 중심 사이의 거리
	
	double result2 = sqrt(pow(double(c+f),2));//반지름 사이의 거리 
	   
	if(result1 < result2)//원의 중심의 거리 < 반지름의 합 
		{if(c<f) // c가 f 보다 작을 경우 
			{
				if(result1+double(c)==double(f))
					cout << "1"<<endl; // 원 안에서 내접할때 
				else if((result1 + double(c)) < double(f))
					cout <<"0"<<endl; // 원 하나가 다른 하나를 포함하고 있을 때 
				else if(result1 < result2)
					cout <<"2"<<endl; // 삼각형을 만들때 
			}
		 else if(c>f) //c 가 f 보다 작을 경우 
		 	{
		 		if(result1+double(f) == double(c))
		 			cout <<"1"<<endl; //원 안에서 내접할때 
		 		else if((result1 + double(f)) < double(c))
		 			cout <<"0"<<endl; //원 하나가 다른 하나를 포함하고 있을 때 
		 		else if(result1 < (double(c) + double(f)))
		 			cout <<"2"<<endl; // 삼각형을 만들 때 
		 	}
		 else if(c == f)
		 {
		 		if(a == d && b ==e)
		 			cout <<"-1"<<endl; //두 원이 완전히 겹칠 때 
		 		
		 		else
		 			cout <<"2"<<endl; // 두 원이 삼각형을 그릴 것이다. 
		 }
		}
	else if( result1 > result2) // 원의 중심의 거리 > 반지름의 합 
				{
				cout << "0"<<endl;
				}
	else // 원의 중심의 거리 = 반지름의 합 
			cout << "1"<<endl;
}


