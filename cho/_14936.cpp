#include <iostream>
using namespace std;

int act1Cost(int);
int act2Cost(int);
int act3Cost(int);
int act4Cost(int);
int act41Cost(int);
int act42Cost(int);
int act43Cost(int);
int act412Cost(int);
int act413Cost(int);

int main(){
      int n, m;
      int ret = 1;

      cin >> n >> m;

      if(act1Cost(n) <= m){
            ret++;
      }

      if(act2Cost(n) <= m){
            ret++;
      }

      if(act3Cost(n) <= m){
            ret++;
      }

      if(act4Cost(n) <= m){
            ret++;
      }

      if(act41Cost(n) <= m){
            ret++;
      }

      if(act42Cost(n) <= m){
            ret++;
      }

      if(act43Cost(n) <= m){
            ret++;
      }

      if(act412Cost(n) <= m){
            ret++;
      }

      if(act413Cost(n) <= m){
            ret++;
      }

      cout << ret << endl;

      return 18;
}

int act1Cost(int n){
      return n;
}

int act2Cost(int n){
      return n / 2;
}

int act3Cost(int n){
      if(n % 2 == 0){
            return n / 2;
      }
      else{
            return n / 2 + 1;
      }
}

int act4Cost(int n){
      return (n - 1) / 3 + 1;
}

int act41Cost(int n){
      return act1Cost(n) + act4Cost(n);
}

int act42Cost(int n){
      return act2Cost(n) + act4Cost(n);
}

int act43Cost(int n){
      return act3Cost(n) + act4Cost(n);
}

int act412Cost(int n){
      return act1Cost(n) + act2Cost(n) + act4Cost(n);
}

int act413Cost(int n){
      return act1Cost(n) + act3Cost(n) + act4Cost(n);
}
