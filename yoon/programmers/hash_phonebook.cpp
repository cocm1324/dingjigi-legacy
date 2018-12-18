#include <string>
#include <vector>
#include<string.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    vector<string>::iterator iter;
    vector<string>::iterator iter2;
    for(iter=phone_book.begin();iter!=phone_book.end();)
    {
        for(iter2 = iter+1; iter2!=phone_book.end(); ++iter2)
        {
            if(iter->find(*iter2)==0) {
                answer = false;
                return answer;
            }
            else if(iter2->find(*iter)==0) {
                answer = false;
                return answer;
            }
        }
    ++iter; 
    }

    return answer;
}
