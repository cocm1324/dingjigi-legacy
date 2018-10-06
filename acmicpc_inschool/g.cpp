#include <iostream>

using namespace std;

int main(){
    int n, k;
    int record[100];
    int flag = 1;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> record[i];
    }

    for(int i = 0; i < n; i++){
        if(record[i] == i - 1){
            
        }
    }

    if(flag == 0){
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }

    return 0;
}