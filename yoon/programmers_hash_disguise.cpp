#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int size = clothes.size();
    vector<int> num_clothes;
    for(int i = 0 ; i < size; ++i){
         num_clothes.push_back(clothes[i].size());
    }
    for(int i = 0;  i< num_clothes.size(); ++i){
        if( i ==0) answer = num_clothes[i]+1;
        else{
            answer*= num_clothes[i]+1;
        }
    }
    answer -=1; 
    return answer;
}
