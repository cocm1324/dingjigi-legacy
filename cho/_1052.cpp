#include <stdio.h>
#include <stdlib.h>

using namespace std;

int extraCalc(int n, int k);
int findLeastPow(int n);

int main(){
  int n, k;
  int extra = 0;

  scanf("%d %d", &n, &k);
  extra = extraCalc(n, k);
  printf("%d\n", extra);

  return 0;
}

int extraCalc(int n, int k){
  int ret = 0;

  if(k == 1){
      ret = findLeastPow(n) - n;
  }
  else{
    ret = extraCalc(findLeastPow(n) - n, k - 1);
  }

  return ret;
}

int findLeastPow(int n){
  int a = 1;
  while(a < n){
    a *= 2;
  }
  return a;
}
