#include<stdio.h>
int main(){
int input1=0;
int input2=0;
int minus_left = 30;
int output1 = 0;
int output2 = 0; 
scanf("%d %d", &input1, &input2);
if(input2 <30){
minus_left= 30 - input2; 
output2 = 60 - minus_left;
	if(input1==0){
	output1 = 23;
	}
	else output1= input1-1;
}
else{
output2= input2-30;
output1 =input1;

}
printf("%d %d\n", output1, output2); 
return 0; 
}
/* */ 
