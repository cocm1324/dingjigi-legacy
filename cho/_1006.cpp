#include<stdio.h>
#include<iostream>

using namespace std;

int calc(int n, int w, int* inner, int* outer);


int main(){
	int testCase = 0;
	int n = 0;
	int w = 0;
	int num = 0;
	
	int* inner = NULL;
	int* outer = NULL;
	
	scanf("%d", &testCase);
	for(int i = 0; i < testCase; i++){
		scanf("%d %d", &n, &w);
		
		inner = new int[n];
		outer = new int[n];
		
		
		for(int j = 0; j < n; j++){
			scanf("%d", &inner[j]);
		}

		for(int j = 0; j < n; j++){
			scanf("%d", &outer[j]);
		}

		num = calc(n, w, inner, outer);				
		
		printf("%d\n", num);
		
		delete[] inner;
		delete[] outer;
		inner = NULL;
		outer = NULL;
	}
	
	return 0;
}

int calc(int n, int w, int* inner, int* outer){
	int temp = 0;
	int count = 0;
	
	for(int i = 0; i < n; i++){
		if(inner[i] == 0){
			continue;
		}
		//printf("inner[%d] = %d\n",i,inner[i]);
		count++;
		temp = w - inner[i];
		inner[i] = 0;
		
		if(inner[(n + i - 1) % n] != 0 && inner[(n + i - 1) % n] <= temp){
			inner[(n + i - 1) % n] = 0;
			continue;
		}
		
		if(inner[(n + i + 1) % n] != 0 && inner[(n + i + 1) % n] <= temp){
			inner[(n + i + 1) % n] = 0;
			continue;
		}
		
		if(outer[i] != 0 && outer[i] <= temp){
			outer[i] = 0;
		}	
	}
	
	for(int i = 0; i < n; i++){
		if(outer[i] == 0){
			continue;
		}
		//printf("outer[%d] = %d\n",i,outer[i]);
		count++;
		temp = w - outer[i];
		outer[i] = 0;
		
			
		if(outer[(n + i - 1) % n] != 0 && outer[(n + i - 1) % n] <= temp){
			outer[(n + i - 1) % n] = 0;
			//printf("mark\n");
			continue;
		}
		
		if(outer[(n + i + 1) % n] != 0 && outer[(n + i + 1) % n] <= temp){
			outer[(n + i + 1) % n] = 0;
			continue;
		}
	}
	
	return count;
}
