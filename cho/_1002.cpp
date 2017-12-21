#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int num_testcase = 0;
  int x1, y1, r1, x2, y2, r2;
  float temp = 0;
  int range;

  cin  >> num_testcase;

  for(int i = 0; i < num_testcase; i++){
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if(x1!=x2){
      temp = abs((y2-y1)/(x1-x2));
    }
    else{
      temp = abs(y2-y1);
    }

    range = r1+r2;

    if(temp == range){
      cout << 1 << endl;
    }
    else if(temp > range){
      cout << 0 << endl;
    }
    else{
      cout << 2 << endl;
    }
  }

  return 0;
}
