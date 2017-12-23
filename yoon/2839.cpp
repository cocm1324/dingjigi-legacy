#include<iostream>
using namespace std;

//2839 번에 대한 문제입니다. 
void count_paper_bag();
int main()
{
	

count_paper_bag(); 



}

void count_paper_bag(){
	unsigned int N= 0;
	cin >>N;
	if( N ==4)
		cout << "-1"<<endl; 
	else if(N/5 != 0 || N%5 !=0){ //5kg 로 설탕을 다 담지 못할 때 
		int N3 = N/5;// 5kg 봉지 갯수를 N3라고 한다.
		int N2 = N%5;// 5kg에 담고 남은  kg  
		if(N2 %3 !=0)//3kg 단위로 담고도 다 못 담았을 때 
			cout <<"-1"<<endl; //3,5kg 봉지로 담을 수 없으므로 -1 출력한다. 
		else//남은게 3kg 단위일때 
		{
			cout << N3 + (N2/3) <<endl;
    	}
    }
    else // 설탕이 5의 배수만큼 있을때 
    {	
    	cout << N/5 <<endl; 
    }
}	
