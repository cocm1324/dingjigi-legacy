/*

this file is comparison between dynamic-topdown approach and recursion - topdown algorithm

as I post  my codes below, there are exactly tremendous difference in time consuming between two algorithms

here is my codes ..... */ 

///////////////////////////////////
#include<stdio.h>
#include<time.h>
#define MAXSIZE 1000
int list[MAXSIZE] ={0,};
int list1[MAXSIZE] = {0,}; 
int Fib(int n){
	int fib, f1, f2;
	if( n<2)
		fib = n;
	else{
		if(list[n-1] ==0) f1 = Fib(n-1); // lis n이 비어있으면  f1에 대해 Fib(n-1)을 재귀 함수로 처리 
		else f1 =list[n-1]; //f1 에 list[n-1]을 대입  
		if(list[n-2] ==0) f2 = Fib(n-2); // 위와 같이 똑같은 방법으로 구현 
		else f2 = list[n-2];
		fib = f1 + f2; //fib 값에 f1, f2 값을 넣는다.
	}
	list[n] = fib;
	return list[n];
}// Fib 한번 실행할 때 마다 list[n]에 있는 값 구해짐. 

//recursion top down
int Fib1(int n){
	int fib, f1, f2; 
	
	if( n <0) fprintf(stderr,"%s","minimum input n is 1\n");  
	else if ( n >2)
	{
		fib = Fib1(n-2) + Fib1(n-1);
	}
	else fib = 1;
	return fib;
}	
int main(){
	int answer = 0;
	time_t startTime1 = 0, endTime1 = 0;
	time_t startTime2 = 0, endTime2 = 0;
	startTime1 = clock();
	printf(" Fibonacci dynamic top down: %d, ", Fib(1000));
	endTime1 = clock();
	printf("elapsed time: %f\n", (float)(endTime1- startTime1)/(CLOCKS_PER_SEC));
	startTime2 = clock(); 
	printf(" Fibonacci recursion top down: %d,", Fib1(50));
	endTime2 = clock(); 
	printf("elapsed time: %f\n", (float)(endTime2 - startTime2)/(CLOCKS_PER_SEC)); 

}
