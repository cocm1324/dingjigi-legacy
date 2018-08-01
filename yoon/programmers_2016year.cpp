#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    vector<int> v(12);
    int sum = 0;
    for(int i =1; i <=12; i++ ){
        if((i == 1)||(i == 3)||(i == 5)||(i == 7)||(i == 8)||(i == 10)||(i == 12)){
            v.at(i-1)= 31;

        }
        else if(i ==2) v.at(i-1)=29;
        else v.at(i-1)= 30;
    }
    for(int i=1; i<a ;i++){
        sum += v.at(i-1);
    }
    sum += b;
    int day = sum%7;
    string answer = "";
    if(day==1) answer="FRI";
    else if(day ==2) answer="SAT";
    else if(day ==3) answer="SUN";
    else if(day ==4) answer="MON";
    else if(day ==5) answer="TUE";
    else if(day ==6)answer="WED";
    else answer="THU";
    return answer;
}
