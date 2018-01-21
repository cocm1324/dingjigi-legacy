#include <stdio.h>
#include <iostream>

#define MAX_USER 100

using namespace std;


int main(){
  int iter = 0;
  int piece = 0;
  int user = 0;
  int grid[MAX_USER][MAX_USER + 2];

  scanf("%d", &iter);
  for(int i = 0; i < iter; i++){
    scanf("%d %d", &piece, &user);
    for(int j = 0; j < user; j++){
      scanf("%d %d %d", &grid[j][0], &grid[j][1], &grid[j][2]);
      for(int k = 0; k < grid[j][2]; k++){
        scanf("%d", &grid[j][3+k]);
      }
    }
    for(int j = 0; j < user; j++){
      for(int k = 0; k < grid[j][2] + 3; k++){
        printf("%d ", grid[j][k]);
      }
      printf("\n");
    }
  }


  return 0;
}
