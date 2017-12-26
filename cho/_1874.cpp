#include <iostream>
#include <string>
using namespace std;

int main(){
  int temp = 0;
  int local = 0;
  int top = 0;
  int* record;
  int* stack;
  string printSt = "";
  cin >> temp;
  record = new int[temp];
  stack = new int[temp+1];

  for(int i = 0; i < temp; i++){
    cin >> record[i];
    stack[i] = i;
  }
  stack[temp] = temp;

  /*
  for(int i = 0; i < temp+1; i++){
    cout << stack[i];
  }
  cout << endl;
  */

  for(int i = 0; i < temp; i++){
    //cout << "iteration " << i << "\ttop : " << top << endl;
    //larger than top
    if(record[i] > top){
      //cout << "case : branch" << endl;
      //cout << "record - top : " << record[i] - top << endl;
      local = top;
      for(int j = 0; j < record[i] - local; j++){
        //cout << "stack[" << top + j + 1 << "] is " << stack[top + j + 1] << endl;
        if(stack[top + 1] != -1){
          printSt.append("+\n");
          //cout << "push" << endl;
        }
        top++;
      }
      //cout <<"top after iter : "<< top << endl;
      printSt.append("-\n");
      //cout << "pop" << endl;
      stack[top] = -1;
      while(stack[top] == -1){
        //cout << "backward jump" << endl;
        top--;
      }
    }
    //just equal to top
    else if(record[i] == top){
      //cout << "case : pop" << endl;
      printSt.append("-\n");
      //cout << "pop" << endl;
      stack[top] = -1;
      while(stack[top] == -1){
        top--;
      }
    }
    else{
      //cout << "case : not" << endl;
      printSt = "NO\n";
      break;
    }
  }

  cout << printSt;

  return 0;
}
