/// Dㅏ.... him 들다. 
#include<iostream>
#include<sstream>
using namespace std;


void classify();
int main() 
{
	
classify(); 


}

void classify()
{
    const char *cmp = "";
    string cmpr;
    stringstream ss; //int 형 i와 j를 char 형으로 바꾸기 위해
	int i =0;
	int j =2; //ascending이었을 때, string의 두번째 요소를 가르킴  
	int k = 7;//ㅇescending이었을 때, string의 두번쨰 요소를 가르킴
    int l = 0;
    char str[16] ={"",}; // 문자 비교가 들어가야 하므로, char형 배열로 입력 받는다.
    cin.getline(str,16,'\n'); // 최대 char배열 크기 만큼, 개행 문자가 입력되면 입력을 종료한다.
    /*
    for(l = 0; l< sizeof(str); l++)
        cout <<str[l];
     */
	if(str[0]=='1') //첫글자가 1 이면
	{	for(i = 2, j = 2; i <15; i+=2,j++) // 오름차순이라고 가정하고 시작
			{
			
			 ss<< j;
             cmpr = ss.str();
             cmp = cmpr.c_str();
             
                if(str[i]!=cmpr[0])// 중간에 한번이라도 오름차순으로 가지 않으면,
                    //str 의 인덱스가 홀수라면 스페이스를 가르키므로, 작수 일 때 비교한다.
                {
                    /*cout << endl <<"j: " <<j<<endl;
                    cout << "i: "<< i << endl;
                    cout << "str[i]: "<<str[i] <<endl;
                    */
                    cout << "mixed" <<endl;
                    
                    break; // mixed 이면 중간에 for 문을 탈출한다.
                }
                ss.str("");
                
            }
        //for문을 나온 다음에 i 가 14 이면 ascending문이라고 판단하고 출력하낟.
		if( i >=14)
		{
			cout <<"ascending" <<endl;
		}
	}
	else if(str[0]=='8')
	{
		for(i = 2, k = 7; i <15; i+=2, k--)//내림차순이라 가정
		{
            ss<< k;
            cmpr = ss.str();
            cmp = cmpr.c_str();
            if(str[i]!=cmp[0]){
                cout << "mixed";
				break; // mixed이면 중간에 for문을 탈출한다.  
            }
            ss.str("");
        }
        
		if(i >=14)
		{
            
			cout <<"descending" <<endl; 
		}
	}
	else // str의 첫 요소가 1이나 8이 아닐때,
		cout <<"mixed "<<endl; 	

}
