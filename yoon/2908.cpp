#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

int main()
{
    string input1 = "";
    string input2 = "";
    
    string cmpr1 = "abc";
    string cmpr2= "abc";
    
    cin >> input1 >> input2;
    
    
    for(int i =0; i<3; i++)
    {
        cmpr1[i] = input1[2-i];
        cmpr2[i] = input2[2-i];
    }
    
    
    
if(atoi(cmpr1.c_str()) < atoi(cmpr2.c_str()))
    cout << cmpr2;
else
    cout << cmpr1;
}
