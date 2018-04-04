#include<stdio.h>
#include<time.h>



long long recursive(long long m ,long long n){
 	
	if( n>1 && m>1){
		return recursive(n,m-1) + recursive(n-1,m) + recursive(n-1,m-1);
	}
	else return 1;
	
}

long long dynamic(long long int m, long long n){
	long long s[m+1][n+1]; 
	long long x=0 , y = 0;
	for(x = 1; x <m+1; x++){
		s[x][1] = 1;
	}
	for(x = 1; x<n+1; x++){
		s[1][x] = 1;
	}

	for(x = 2; x<m+1;x++){
		for(y =2; y<n+1; y++){
			s[x][y] = s[x][y-1] + s[x-1][y-1] + s[x-1][y];
		}
	}
	return s[m][n];
} 

int main()
{	
	int input1, input2; 
	printf("%s","m,n 입력(뛰어쓰기로 구분) : ");
	scanf("%d %d", &input1, &input2 );
	int i;
	float gap1, gap2;
	time_t startTime1=0, endTime1=0;
	time_t startTime2=0, endTime2 =0;
	startTime1 = clock();
	printf("recursive 답: %lli ", recursive(input1,input2));
	endTime1=clock();
	gap1 = (float)(endTime1-startTime1)/(CLOCKS_PER_SEC);
	printf("recursive 측정 시간 : %f 초\n", gap1);
	startTime2 = clock();
	printf("dynamic 답: %lli ", dynamic(input1,input2));
	endTime2 = clock();
	gap2 = (float)(endTime2-startTime2)/(CLOCKS_PER_SEC);
	printf("dynamic 측정 시간 : %f 초\n", gap2);
	printf("---종료---\n");

}
