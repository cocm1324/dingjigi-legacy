#include <stdio.h>
#include <iostream>

#define MAX_SIZE 50

using namespace std;

float shadeCalc(int x, int y, int n, int m, char grid[][MAX_SIZE]);
void shadify(int x, int y, int xpos, int ypos, char grid[][MAX_SIZE], int shadeGrid[][MAX_SIZE]);

int main(){
  int n, m;
  int x, y;
  float shade = 0;
  char grid[MAX_SIZE][MAX_SIZE];

  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){
      scanf("%c", &grid[i][j]);
    }
  }

  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%c", &grid[i][j]);
      if(grid[i][j] == '*'){
        x = i; y = j;
      }
    }
  }

  shade = shadeCalc(x, y, n, m, grid);

  printf("%d\n", shade);

  return 0;
}

float shadeCalc(int x, int y, int n, int m, char grid[][MAX_SIZE]){
  float shadeGrid[MAX_SIZE][MAX_SIZE];

  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){
      shadeGrid[i][j] = -1;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      shadeGrid[i][j] = 1;
    }
  }


  shadify(x, y, x, y, grid, shadeGrid);


}

void shadify(int x, int y, int xpos, int ypos, char grid[][MAX_SIZE], int shadeGrid[][MAX_SIZE]){
  
}
