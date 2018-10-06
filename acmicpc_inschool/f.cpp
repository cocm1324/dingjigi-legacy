#include <iostream>
#include <vector>

using namespace std;

int main(){
    int w, n;
    int input_int;
    vector<int> input;
    vector<int> a, b, c, d;
    int flag = 0;
    int size = 0;

    cin >> w >> n;

    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= w - i; j++){
            if(i >= j)continue;
            for(int k = 1; k <= w - i - j; k++){
                if(j >= k)continue;
                if(w - i - j - k == i || w - i - j - k == j || w - i - j - k <= k || w - i - j - k <= 0)continue;
                a.push_back(i);
                b.push_back(j);
                c.push_back(k);
                d.push_back(w - i - j - k);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cin >> input_int;
        input.push_back(input_int);
    }

    size = (int)a.size();

    for(int i = 0; i < size; i++){
        for(int j = 0; j < n; j++){
            if(input[j] == a[i]){
                flag++;
            }
            if(input[j] == b[i]){
                flag++;
            }
            if(input[j] == c[i]){
                flag++;
            }
            if(input[j] == d[i]){
                flag++;
            }
        }
        if(flag == 4){
            break;
        }
        else{
            flag = 0;
        }
    }

    if(flag ==4){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}