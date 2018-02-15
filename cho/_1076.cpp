#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

unsigned int resistCalc(string, string, string);

int main(){
  string input1, input2, input3;
  unsigned int ret = 0;

  cin >> input1;
  cin >> input2;
  cin >> input3;

  cout << input1 << input2 << input3 << endl;

  ret = resistCalc(input1, input2, input3);

  printf("%d\n", ret);

  return 0;
}

unsigned int resistCalc(string input1, string input2, string input3){
  unsigned int ret = 0;

  if(input1.compare("black") == 0){
    ret += 0;
    printf("mark11\n");
  }
  else if(input1.compare("brown") == 0){
    ret += 10;
    printf("mark11\n");
  }
  else if(input1.compare("red") == 0){
    ret += 20;
    printf("mark12\n");
  }
  else if(input1.compare("orange") == 0){
    ret += 30;
    printf("mark13\n");
  }
  else if(input1.compare("yellow") == 0){
    ret += 40;
    printf("mark14\n");
  }
  else if(input1.compare("green") == 0){
    ret += 50;
    printf("mark15\n");
  }
  else if(input1.compare("blue") == 0){
    ret += 60;
    printf("mark16\n");
  }
  else if(input1.compare("violet") == 0){
    ret += 70;
    printf("mark17\n");
  }
  else if(input1.compare("grey") == 0){
    ret += 80;
    printf("mark18\n");
  }
  else if(input1.compare("white") == 0){
    ret += 90;
    printf("mark19\n");
  }
  else{
    printf("mark110\n");
  }

  if(input2.compare("black") == 0){
    ret += 0;
  }
  else if(input2.compare("brown") == 0){
    ret += 1;
  }
  else if(input2.compare("red") == 0){
    ret += 2;
  }
  else if(input2.compare("orange") == 0){
    ret += 3;
  }
  else if(input2.compare("yellow") == 0){
    ret += 4;
  }
  else if(input2.compare("green") == 0){
    ret += 5;
  }
  else if(input2.compare("blue") == 0){
    ret += 6;
  }
  else if(input2.compare("violet") == 0){
    ret += 7;
  }
  else if(input2.compare("grey") == 0){
    ret += 8;
  }
  else if(input2.compare("white") == 0){
    ret += 9;
  }
  else{}

  if(input3.compare("black") == 0){
    ret *= 1;
  }
  else if(input3.compare("brown") == 0){
    ret *= 10;
  }
  else if(input3.compare("red") == 0){
    ret *= 100;
  }
  else if(input3.compare("orange") == 0){
    ret *= 1000;
  }
  else if(input3.compare("yellow") == 0){
    ret *= 10000;
  }
  else if(input3.compare("green") == 0){
    ret *= 100000;
  }
  else if(input3.compare("blue") == 0){
    ret *= 1000000;
  }
  else if(input3.compare("violet") == 0){
    ret *= 10000000;
  }
  else if(input3.compare("grey") == 0){
    ret *= 100000000;
  }
  else if(input3.compare("white") == 0){
    ret *= 1000000000;
  }
  else{}

  return ret;
}
