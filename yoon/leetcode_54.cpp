using namespace std;

enum class Direction{
      RIGHT,
      DOWN,
      LEFT,
      UP
    };
class Solution {
public:
    Direction direc;
    vector<int> answer;
    int left = 0, right = 0; 
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      Direction direc = Direction::RIGHT;
      if(matrix.empty()) return {};
        vector<vector<int>> flag(matrix.size(),vector<int>(matrix[0].size(),0));
            
            while(1){
              flag[left][right] =1;
              answer.push_back(matrix[left][right]);
              switch(direc){
              case Direction::RIGHT:        
               if(right+1<matrix[0].size() && flag[left][right+1] == 0){
                   ++right;
                   continue;
               }
               else if(left+1<matrix.size() && flag[left+1][right] == 0 ){
                   ++left;
                   direc = Direction::DOWN;
                   continue; 
               }
               else break;
             case Direction::DOWN:
              if(left+1<matrix.size() && flag[left+1][right] == 0 ){
                   ++left;
                   continue;
                }
              else if(right-1>=0 && flag[left][right-1]==0){
                   --right;
                   direc = Direction::LEFT;
                   continue;
               }
               else break;
              case Direction::LEFT: 
               if(right-1>=0 && flag[left][right-1]==0){
                   --right;
                   continue;
               }
               else if(left-1>=0  && flag[left-1][right]==0){
                   --left;
                   direc = Direction::UP;
                   continue;
              }
               else break; 
              case Direction::UP:
               if(left-1>=0  && flag[left-1][right]==0){
                   --left;
                   continue;
              }
               else if(right+1<matrix[0].size() && flag[left][right+1] == 0){
                   ++right;
                   direc = Direction::RIGHT;
                   continue;
               }
               else break;
            }
            break;
          } // switch-case
        return answer; 
    }
};
