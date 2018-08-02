#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    vector<int>::size_type j = answer.size();
    for(vector<int>::size_type i =0; i<arr.size(); i++){
        j = answer.size();
        vector<int>::size_type j = answer.size();
         if(answer.size()==0) { // if answer is empty, push_back()
            answer.push_back(arr.at(0));
         }
         else if(answer.at(j-1)==arr.at(i)){
                continue; // if j is
         }
         else answer.push_back(arr.at(i));
    }
  
    return answer;
}
