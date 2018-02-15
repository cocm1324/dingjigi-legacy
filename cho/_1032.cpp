#include <iostream>
#include <stdio.h>

#define MAX_SIZE 50

using namespace std;

int main(){
  int n, m;
  char grid[MAX_SIZE][MAX_SIZE];

  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){
      grid[i][j] = '0';
    }
  }

  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    fgets(grid[i], MAX_SIZE, stdin);
  }

  m = 0;
  while(grid[0][m] != '0'){
    
    m++;
  }
  printf("%d\n",m);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      printf("%c", grid[i][j]);
      //if(grid[0][j] != grid[i][j]){
      //  grid[0][j] = '?';
      //}
    }
    printf("\n");
  }

  //for(int i = 0; i < m; i++){
  //  printf("%c", grid[0][i]);
  //}
  //printf("\n");

}
