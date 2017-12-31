//
//  1152.cpp
//  icpc
//
//  Created by jaewon on 2017. 12. 31..
//  Copyright © 2017년 jaewon. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#define max_length 1000000
using namespace std;
void cal_sentence();
char sentence[max_length] = {'\0',};
unsigned int i = 0;
int main()
{
    cal_sentence();
}

void cal_sentence()
{
    unsigned int count =0;
    
    cin.getline(sentence,max_length);
    for(i=0; i <max_length; i++)
    {
        if(sentence[i]!='\0')//i번째가 문자열의 끝을 가리키지 않을때
        {
            if(sentence[i]!=' ')// i 번째가 빈칸이 아닐때, 임의의 문자가 왔을때
            {if(sentence[i+1]==' ')// 그리고 문자 다음에 빈칸이 있을때
                count++;
             else if(sentence[i+1] =='\0')// 혹시 빈칸으로 안끝나고 배열의 마지막인 null로 끝났을때
                count++;
            }
            // i번째가 문자 빈칸을 가르킬 경우에는 count를 하지 않고 바로 다음 순번으로 넘어간다.
        }
        else if(sentence[i]=='\0')
            break;
        
        
    }
    
    
    cout << count<<endl;
    
}
