#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> );
int re(int, std::vector<int> );

int main(){
  vector<int> v;

  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  //v.push_back(3);
  //v.push_back(4);

  cout << solution(v) << endl;
}

int solution(vector<int> numbers) {
    int answer = 0;

    answer = re(0, numbers);


    return answer;
}

int re(int sum, vector<int> numbers){
  int total = 0;
  int pos = 0;
  int neg = 0;

  if(numbers.empty()){
    if(sum == 0){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    pos = numbers.back();
    neg = -numbers.back();
    numbers.pop_back();

    total += re(sum + pos, numbers);
    total += re(sum + neg, numbers);
  }

  return total;
}
