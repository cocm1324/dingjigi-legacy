#include<stdio.h>
// written by JaewonYoon 06.26
#define MAX 500
int n =MAX; 
int visited[MAX][MAX]; 
int x=0, y= 0; 
int moveright(int array[n][n]);
int movedown(int array[n][n]);
int moveup(int array[n][n]);
int moveleft(int array[n][n]);
void initial(int array[n][n]){
	for(int v = 0; v <n; ++v){
		for(int u= 0; u<n; ++u){
			visited[v][u] = 0; 
		}
	}
}
void point(){
	printf("point\n");
}
void print(int array[n][n]){
	visited[0][0] =1;
	printf("%d ", array[0][0]);
	moveright(array);
}
int main(){
	int array[4][4] = {{1, 2, 3,4},

{12,13, 14, 5},

{11,16,15 ,6},
{10,9,8,7}};

n = sizeof(array[0])/4;
initial(array);
print(array);
}

int moveup(int array[n][n]){
	--x;
	if(x<0) {
		++x; moveright(array); return 0; 
	} 
	else{
		if(visited[x][y]==1){
			if(visited[x+1][y+1]==1) return 0;
			else{
				++x; 
				moveright(array);
			}
		}
		else {
			printf("%d ",array[x][y]);
			visited[x][y]=1;    
			moveup(array); 
		}
		return 0;
	}
}
int movedown(int array[n][n]){
	++x;
	if(x>n-1){
		--x; moveleft(array); return 0; 
	} 
	else{
		if(visited[x][y] ==1){
			if(visited[x-1][y-1]==1) return 0;
			else {
				--x;
				moveleft(array);
			}
		}
		else{
			printf("%d ",array[x][y]);
			visited[x][y]=1; 
			movedown(array);
		}
		return 0;
	}
}
int moveright(int array[n][n]){
	++y;
	if(y>n-1){
		--y;
		movedown(array); return 0; 
	} 
	else{
		if(visited[x][y]==1){
			if(visited[x+1][y-1]==1) return 0;
			else{
				--y;
				movedown(array);
			}
		}
		else{
			printf("%d ",array[x][y]);
			visited[x][y]=1;
			moveright(array);
		}
		return 0;
	}
}
int moveleft(int array[n][n]){
	--y;
	if(y<0) {
		++y;
		moveup(array); return 0; 
	}
	else{
		if(visited[x][y]==1){
			if(visited[x-1][y+1]==1) return 0;
			else{
				++y;
				moveup(array); 
			}
		}
		else{
			printf("%d ",array[x][y]);
			visited[x][y]=1;
			moveleft(array);
		}
		return 0; 
	}
}
