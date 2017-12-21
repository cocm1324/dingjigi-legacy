#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main(){
  int num_testcase = 0;
  int x1, y1, r1, x2, y2, r2;
  float dist = 0;

  cin  >> num_testcase;

  for(int i = 0; i < num_testcase; i++){
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

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

    cout << "dist = " << dist << endl;

    if(x1==x2 && y1==y2 && r1 == r2){
      cout << -1 << endl;
    }
    else if(dist > r1 + r2 || r1 > dist +r2 || r2 > dist + r1){
      cout << 0 << endl;
    }
    else if(dist == r1 + r2 || dist + r1 == r2 || dist + r2 == r1){
      cout << 1 << endl;
    }
    else{
      cout << 2 << endl;
    }
  }
  return 0;
}
