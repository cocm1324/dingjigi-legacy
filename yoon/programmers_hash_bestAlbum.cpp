//written by jaewonYoon
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool compare(pair<string,int > &m1, pair<string,int > &m2){
       return m1.second < m2.second ;
    }
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int>answer;
    int count = 0;
    map<string,int> m; 
    int fst_value =0; 
    int sec_value = 0; 
    int fst = 0; //첫번째로 큰 수를 담은 인덱스 
    int sec = 0; //두번쨰로 큰 수를 담은 인덱스 
    for(int i = 0; i < genres.size(); ++i){
        if(m.find(genres[i])==m.end()){
            m.insert(make_pair(genres[i],plays[i])); // 처음 발견한 글자들은 맵에 집어넣고 
        }
        else m[genres[i]]= m[genres[i]]+plays[i]; //처음이 아니면 value값을 올려준다. 
    }
    int music_num = m.size();
    map<string,int>::iterator it; 
    vector<pair<string,int > > sorted_music;
    copy(m.begin(),m.end(),back_inserter<vector <pair <string, int > > >(sorted_music));
         //////
    sort(sorted_music.rbegin(),sorted_music.rend(),compare);
    cout << "sorting ..." <<endl; 
    cout << "sorting size: " << sorted_music.size() <<endl;
    for(int i= 0 ; i<sorted_music.size(); ++i){

        cout<< sorted_music[i].first << ": "; 
        cout<< sorted_music[i].second <<endl; 
    } 
    cout << "//////////" <<endl;
    for(int i = 0; i <sorted_music.size();++i ){
        for(int j = 0; j <genres.size(); ++j){
            if(genres[j]==sorted_music[i].first)
            {
                ++count;
                if(fst_value<plays[j]){

                    sec_value = fst_value;
                    fst_value = plays[j];
                    cout << "fst_value: "<< fst_value <<endl; 
                    cout << "sec_value: "<< sec_value <<endl; 
                    
                    sec = fst;
                    fst = j;
                    cout << "fst: " <<fst <<endl; 
                    cout << "sec: " <<sec <<endl; 

                }
                else if (sec < plays[j]) {
                    sec = j;
                    sec_value = plays[j]; 
                }
            }
        }
        cout << "<- " << i <<"번째" <<endl;
        if(count>=2){
        answer.push_back(fst);
        answer.push_back(sec);
        } else answer.push_back(fst);
        fst_value = 0, sec_value = 0, count = 0; 

    }
    for(int i =0; i <answer.size(); ++i){
        cout << answer[i] << ", ";
    }
    return answer;
}

int main(){
    string arr[] ={"classic","pop","classic","pop","classic","classic","classic"};//{"classic", "rock", "classic", "pop", "classic", "ccm", "ccm"};
    int arr1[] = {400,600,150,2500,500,500,600} ;
    vector<string> genres(arr, arr+sizeof(arr) / sizeof(arr[0]));
    vector<int> plays(arr1, arr1+sizeof(arr1)/ sizeof(arr1[0]));
    vector<int> answer; 
    answer = solution(genres,plays);
    cout << "answer은? :" ;
    for(int i =0; i <answer.size(); ++i){
        cout << answer[i] << ", ";
    }
}
