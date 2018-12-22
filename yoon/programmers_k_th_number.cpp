#include <string>
#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer(commands.size());    
    int count = 0; 
    int k;
    int a;
    int b;
    for(a = 0; a<commands.size(); ++a){
        vector<int> temp; 
        cout <<++count<< "번째" <<endl; 
        int i = commands[a][0];
            cout << i<<endl;;
        int j = commands[a][1];
            cout << j<<endl;
        k = commands[a][2];
            cout << k<<endl;;
        for(int t = i-1; t <j-1; ++t) temp.push_back(array[t]);
        sort(temp.begin(),temp.end());
        for(auto el: temp) cout << el <<endl;
        //answer.push_back(temp[k-1]);
    }
    cout <<"answer: "<<endl;
    for(auto elem:answer) cout << elem <<endl;
    return answer;
}

int main(){
    solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}});
}
