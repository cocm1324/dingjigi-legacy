#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main(){
  int num_testcase = 0;
  int x1, y1, r1, x2, y2, r2;
  float dist = 0;
  int temp = 0;

  cin  >> num_testcase;

  for(int i = 0; i < num_testcase; i++){
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if(r1 < r2){
      temp = r1;
      r1 = r2;
      r2 = temp;
    }

    if(x2 == x1) {
      dist = abs(y2 - y1);
    }
    else if (y2 == y1 && x2 != x1) {
      dist = abs(x2 - x1);
    }
    else if (y2 == y1 && x2 == x1) {
      dist = 0;
    }
    else{
      dist = sqrt(abs((pow(y2,2) - pow(y1,2)) / (pow(x2,2) - pow(x1,2))));
    }

    if(dist > r1 + r2){
      temp = 0;
    }
    else if(dist == r1 + r2){
      temp = 1;
    }
    else if(dist + r2 > r1 && dist < r2 + r1){
      temp = 2;
    }
    else if(dist + r2 == r1){
      temp = 1;
    }
    else if(dist + r2 < r1){
      temp = 0;
    }
    else if(dist == 0 && r1 == r2){
      temp = -1;
    }
    else{
      temp = -2;
    }

    cout << temp << endl;
  }
  return 0;
}
