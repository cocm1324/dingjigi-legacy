#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NUMBER 80

int sum_point(char* array)
{	
	int sum = 0, status = 0; 
	if(array[0] =='O')
	{
		sum = 1;
		status = 1;
	}
	for(int i = 1; i < strlen(array); i++)
	{
		if(array[i-1]=='O' && array[i] == 'O'){
			status = status +1;
			sum = sum + status;
			}
		else if(array[i-1] =='X' &&array[i] == 'O'){ 
			status = 1;
			sum = sum +status;
		} 
		else {
			status = 0; 
			sum =sum +status; 
		}
	}
	return sum;
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	char ** array = (char **) malloc(testcase * sizeof(char*)+1);
	for(int i = 0; i<testcase; i++){
		*(array+i) = (char *) malloc(MAX_NUMBER *sizeof(char)+1);
		char * input = (char *) malloc(MAX_NUMBER *sizeof(char));
		scanf("%s",input);
		strcpy(*(array+i), input);
		free(input);
	}
	int i = 0; 
	while(*(array+i) != NULL){
		printf("%d\n", sum_point(*(array+i)));
		i++; 
	}
	for(i = 0; i<testcase; i++){
		free(*(array+i));
	}
	free(array);	
}
