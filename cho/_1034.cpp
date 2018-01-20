#include<stdio.h>
#include<iostream>

#define MAX_NUM 50

using namespace std;

int main(){
	int n, m, k;
	int grid[MAX_NUM][MAX_NUM];
	char temp[64] = "";
	
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++){
		fgets(temp, 64, stdin);
		for(int j = 0; j < m; j++){
			grid[i][j] = temp[j] - '0';
		}
	}
	scanf("%d",&k);
	
	printf("%d %d %d\n",n,m,k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	} 
	
	
	
	return 0;
}
