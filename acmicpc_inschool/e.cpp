#include <iostream>
#include <cmath>
#include <algorithm>    // std::min_element, std::max_element

using namespace std;

int main()
{   
    int W = 0;
    int n = 0;
    int max = 0;
    
    int answer[100];
    int Weight[500000];

    cin>>W>>n;

    for(int i=0; i<n; i++){
        cin>>Weight[n];
    }


    


    return 0;
}

int e_W(int W, int sum_W){

    return pow((W-sum_W),2);
}

int s_W(int Weight[]){
    int sum = 0;

    for(int i=0; i<500000; i++){
        sum+=Weight[i];
    }

    return sum;
}

// min_element/max_element example
#include <iostream>     // std::cout
#include <algorithm>    // std::min_element, std::max_element

bool myfn(int i, int j) { return i<j; }

struct myclass {
  bool operator() (int i,int j) { return i<j; }
} myobj;

int main () {
  int myints[] = {3,7,2,5,6,4,9};

  // using default comparison:
  std::cout << "The smallest element is " << *std::min_element(myints,myints+7) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7) << '\n';

  // using function myfn as comp:
  std::cout << "The smallest element is " << *std::min_element(myints,myints+7,myfn) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7,myfn) << '\n';

  // using object myobj as comp:
  std::cout << "The smallest element is " << *std::min_element(myints,myints+7,myobj) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7,myobj) << '\n';

  return 0;
}