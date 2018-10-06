#include <iostream>

using namespace std;

int main(){
    int a, b, n, w;
    int i = 0;
    int temp = 0;
    int flag = 0;

    cin >> a >> b >> n >> w;


    for(i = 1; i < n; i++){
        //cout << i  << ":"  << a * i + b * (n - i) << endl;
        if(a * i + b * (n - i) == w){
            //cout << "mark" << endl;
            if(flag == 0){
                flag = 1;
            }
            else if(flag == 1){
                flag = 2;
            }
            temp = i;
        }
    }

    //cout << flag << endl;

    if(flag == 1){
        cout << temp << " " << n - temp << endl;
    }
    else{
        cout << -1 << endl;    
    }

    return 0;
}