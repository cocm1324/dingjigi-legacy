// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // 여기에 코드를 작성해주세요.
    int answer = 1;
    int new_value = 1;
    //짝수
    if( (n-1)%2 ==0 && n>1){ //nxn에서 n이 홀수일때 
            int num_generated = n-1;
            while(num_generated!=0){
                if(num_generated%2==0){
                    int plus_operand = num_generated*2; //짝수일 경우 더해지는 숫자를 짝수 *2로 한다.
                    new_value += plus_operand; //새롭게 만들어지는 숫자. 
                    answer+= new_value;// 새롭게 만들어지는 숫자를 다 더하면 답이 되겠지? 
                    cout <<answer<<endl;
                }
                else{//홀수번쨰
                    int plus_operand = (num_generated+1)*2; 
                    new_value += plus_operand; 
                    answer+= new_value;
                    cout<<answer<<endl;
                }
                num_generated--;
            }
    }
    else{ 
        int num_generated = n-1;
        while(num_generated!=0){
            if(num_generated%2!=0){
                int plus_operand = num_generated *2;
                new_value += plus_operand;
                answer+= new_value;

            }
            else{
                int plus_operand = (num_generated+1)*2;
                new_value+= plus_operand;
                answer+= new_value;
            }
            num_generated--;
        }
    }
    return answer;
}


// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int n1 = 2;
    int ret1 = solution(n1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;
    
    int n2 = 4;
    int ret2 = solution(n2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}
