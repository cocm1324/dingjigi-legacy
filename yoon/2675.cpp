#include <iostream>
#include <string.h>    // strlen()
 
#define N 20
 
using namespace std;
 
int main()
{
    int num, cnt, len;
    char ary[N];
 
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> cnt >> ary;
        len = strlen(ary);
        for (int j = 0; j < len; j++) {   // (!)
            for (int k = 0; k < cnt; k++) {   // (!)                                                                          
                cout << ary[j];
            }
        }
        cout << endl;
    }
    return 0;
}
