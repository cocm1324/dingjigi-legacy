#include <iostream>

#define ROW 21
#define COL 210

using namespace std;

void gridCalc(int, int**);
int polyCalc(int, int, int**);

int main(){
      int testCase, k, n;
      int ret = 0;
      int** grid = new int*[ROW];
      for(int i = 0; i < ROW; i++){
            grid[i] = new int[COL];
            for(int j = 0; j < COL; j++){
                  grid[i][j] = 0;
            }
      }

      cin >> testCase;

      for(int i = 0; i < testCase; i++){
            cin >> k >> n;
            ret = polyCalc(k, n, grid);
            //cout << grid[1][0] << endl;
            cout << ret << endl;
      }

      return 0;
}

void gridCalc(int k, int** grid){
      int temp = 0;
      int record[210];
      for(int i = 0; i < 210; i++){
            record[i] = 0;
      }

      if(k == 1){
            //cout << "mark 1"<< endl;
            grid[k][0] = 1;
            grid[k][1] = 1;
      }
      else if(grid[k][0] == 0){
            //cout << "mark 2"<< endl;
            gridCalc(k-1, grid);

            temp = ((k-1) * k) / 2;
            for(int i = 0; i < temp; i++){
                  record[i] = grid[k-1][i];
            }
            for(int i = 0; i < k + 1; i++){
                  for(int j = 0; j < temp; j++){
                        //cout << j << i << endl;
                        grid[k][i+j] += record[j];
                  }
            }
      }
}

int polyCalc(int k, int n, int** grid){
      gridCalc(k, grid);

      return grid[k][n];
}
