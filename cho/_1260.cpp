#include <cstdio>
#include <queue>
using namespace std;

void addEdge(int**, int, int);
void gridDFS(int**, int*, int, int);
void gridBFS(int**, int*, int, int);

int main(){
  int n, m, init;
  int u, v;
  int** grid;
  int* record;

  scanf("%d %d %d",&n,&m,&init);
  grid = new int*[m];
  for(int i = 0; i < m; i++){
    grid[i] = new int[m];
    for(int j = 0; j < m; j++){
      grid[i][j] = 0;
    }
  }
  record = new int[m];
  for(int i = 0; i < m; i++){
    record[i] = 0;
  }


  for(int i = 0; i < m; i++){
    scanf("%d %d", &u, &v);
    addEdge(grid, u, v);
  }

  //
  gridDFS(grid, record, init, m);
  for(int i = 0; i < m; i++){
    printf("%d ", record[i]);
  }
  printf("\n");

  //
  gridBFS(grid, record, init, m);
  for(int i = 0; i < m; i++){
    printf("%d ", record[i]);
  }
  printf("\n");

  for(int i = 0; i < m; i++){
    delete[] grid[i];
    grid[i] = NULL;
  }
  delete[] grid;
  grid = NULL;
  delete[] record;
  record = NULL;

  return 0;
}

void addEdge(int** grid, int u, int v){
  grid[u - 1][v - 1] = 1;
  grid[v - 1][u - 1] = 1;
}

void gridDFS(int** grid, int* record, int init, int m){

}

void gridBFS(int** grid, int* record, int init, int m){
  int* color = new int[m];
  int* distance = new int[m];
  int* predecesor = new int[m];
  queue<int> q;
  int temp = 0;

  for(int i = 0; i < m; i++){
    color[i] = 0 //0 is white
    distance[i] = -1 //-1 is infinity
    predecesor[i] = -1 //-1 is none
  }
  color[init - 1] = 1; //1 is grey
  distance[init - 1] = 0;
  predecesor[init -1] = -1;
  q.push_back(init - 1);

  while(!q.empty()){
    temp = q.pop_front();
    for(int i = 0; i < m; i++){
      if(grid[temp][i] == 1 && color[i] == 0){
        color[i] = 1;
        distance[i] = distance[temp] + 1;
        predecesor[i] = temp;
        q.push_back(i);
      }
    }
    color[temp] = 2;
  }

  delete[] color;
  delete[] distance;
  delete[] predecesor;
  color = NULL;
  distance = NULL;
  predecesor = NULL;
}
