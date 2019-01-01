#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        vector<int> table;
        int flag = 0; 
        int a =0;
        for(int i= 0 ; i <nums.size(); ++i){
            if(find(table.begin(),table.end(),nums[i])!=table.end()) continue;
            a = nums[i];
                for(int j = i+1; j <nums.size(); ++j){
                    if((a+nums[j]) == target){ 
                        answer.push_back(i);
                        answer.push_back(j);
                        flag = 1;
                        break;
                    }
                }
            if(flag ==1) break;
            else table.push_back(nums[i]);
        }
        return answer; 
    }
};
