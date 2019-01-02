#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string,int> closet; 
    map<string,int>::iterator iter;
    int answer = 1;
    int size_clothes = clothes.size();
    for( int i = 0 ; i <size_clothes; ++i){
        if(closet.find(clothes[i][1])==closet.end()){
            closet.insert(make_pair(clothes[i][1],1));
        }
        else closet.find(clothes[i][1])->second++;
    }
    for( iter=closet.begin(); iter!=closet.end(); iter++){
        answer *= (iter->second)+1;
    }
    answer -= 1;
    return answer;
}
