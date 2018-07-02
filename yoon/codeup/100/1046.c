#include<stdio.h>
#include<math.h>
int main(){
	int a, b, c;
	scanf("%d %d %d", &a,&b,&c);
	printf("%lld\n",a+b+c);
	double d = round(((double)(a+b+c)/3)*10)/10;
	printf("%.1lf",d);
}


/*
반올림 round 를 호출하기 위해서는 math.h가 필요하다. 
round 함수는 소수점 아래 1의 자리에서 반올림을 하는 함수이다. 
0.125 에서 0.13과 같이 소수점 아래 2의 자리까지 반올림을 하기 위해서는 
100을 곱해 12.5를 반올림 시킨 후 다시 100으로 나뉘어 주면 0.13얻을 수 있다. 
이를 정리하면 
1.정수 a를 소수점 아래 n까지 반올림을 하시오: round(a * 10^n) /10^n
2.정수 a를 소수점 아래 n에서 반올림을 하시오: round(a * 10^n-1) /10^n-1

*/
