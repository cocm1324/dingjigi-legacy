#include <iostream>

using namespace std;

int main(){
    long int input=0;
    int count=0;
    int answer=0;

    cin>>input;

    while(input>0){
        input = input/2;
        count++;
    }

   if(answer%2==0){
       answer = count-3;
   }else{
       answer = count-2;
   }

    cout<<answer;
    return 0;
}
