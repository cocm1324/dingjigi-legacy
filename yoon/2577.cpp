//
//  2577.cpp
//  icpc
//
//  Created by jaewon on 2018. 1. 1..
//  Copyright © 2018년 jaewon. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;
void cal_multiple();
int main()
{
    cal_multiple();
}
void cal_multiple()
{
    
    unsigned int i = 0;// 0 부터 9 까지 나타내기 위한 변수;
    unsigned int j = 0; // 배열 c_int의 인덱스를 나타내기 위한 변수
    unsigned int count = 0; // 0부터 9까지 각각 몇 번 카운트 되었는지 담는 변수
    const char * c_int= "";// const* type 을  string에 담기 위한 변수
    const char *cmpr = "";// const* type 을  string에 담기 위한 변수
    stringstream ss;
    unsigned int a= 0, b=0, c= 0; //입력을 받기 위한 변수
    cin >>a;
    cin >>b;
    cin >>c;
    unsigned int d = a*b*c;
    //cout <<d<<endl;
    ss << d;
    string stream1= "";
    string stream2= "";
    stream1 = ss.str();
    c_int = stream1.c_str();
    
    for(i =0; i<10; i++)
    {
        count = 0;
       /////// str에 공백을 넣어주고 clear를 해야 깨끗해진다.
        ss.str("");
        ss.clear();
        
        ss << i;
        stream2 =  ss.str();
        cmpr = stream2.c_str(); // 0 부터 9까지 cmpr에 담기 위함 .
        for(j = 0; j<sizeof(c_int)+1; j++)
        {
            if(c_int[j] == cmpr[0])
                count++;
        }
        cout <<count <<endl;
    }
}
