#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int print(char *buf){
	
	printf("%s\n",buf);
}
/*
int function(float skey){
	int count;
	int i;
	char dot='.';
	int dot_th=0;
	char paper[30]="1";
	printf("inital len: %d\n",strlen(paper));
	snprintf(paper,30,"%f",skey);
	for(i =0; i<strlen(paper);++i)
	{	
		if(paper[i]==dot){
			dot_th=i;
			printf("strlen(paper): %d, dot_th: %d\n",strlen(paper),dot_th);
			count = strlen(paper)-dot_th-1;
			break;
		}	
	}
	return count; 
}
*/

void function2(double skey){
	char buf[100];
	int i =0;
	sprintf(buf,"%f",skey); 
	printf("%d\n",strlen(buf));
	for(i; i<strlen(buf);++i){
		printf("%c",buf[i]);
	} 
	//printf("\n");
}
int main(){
	char name[20];
	int age;
	char code;
	double skey;
	
	scanf("%s\n",name);
	scanf("%d\n",&age);
	scanf("%c\n",&code);
	scanf("%lf",&skey);
	//printf("count: %d\n",function(skey));
	printf("%s\n",name);
	printf("%d\n",age);
	printf("%c\n",code);
	printf("%g",skey);
	//function2(skey);
}


/*

scanf에서는 %lf 를 써야 하며 printf 에서는 %f를 써야한다. 
%g는 필요없는 0을 출력하지 않는다. */
