#include <vector>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

string solution(string, vector<vector<int> >);

int main(){
  string s = "abcde";
  string a = "";
  std::vector<std::vector<int> > v;
  vector<int> k;
  std::vector<int> g;
  std::vector<int> b;

  k.push_back(4);
  k.push_back(5);

  g.push_back(1);
  g.push_back(2);

  b.push_back(3);
  b.push_back(3);

  v.push_back(k);
  v.push_back(g);
  v.push_back(b);

  a = solution(s, v);
  cout << a << endl;

}

string solution(string S, vector<vector<int> > interval)
{
    int start = 0;
    int end = 0;
    stack<char> record;
    string newS = S;
    string base ="";

    for(int i = 0; i < interval.size(); i++){
        start = interval.at(i).at(0) - 1;
        end = interval.at(i).at(1) - 1;

        //cout << i << "iteration ---" << endl;

        for(int j = start; j < end + 1; j++){
            record.push(newS.at(j));
          //  cout << j << ": " << newS.at(j) << endl;
        }

        for(int j = 0; j < newS.length(); j++){
            if(j >= start && j <= end){
                base += record.top();
                record.pop();
            }
            else{
              base += newS.at(j);
            }
        }

        //cout << i << ": "<< base << endl;
        newS = base;
        base ="";
    }

	string answer = newS;
	return answer;
}
