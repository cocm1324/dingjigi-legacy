#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 300
//written by jaewon yoon 20180531 
int full_count = 0;
char buf[MAX]; 
typedef struct array{
	char name[MAX]; 
	int count;
}array;
array a[2048] ={{"\0",0},};
int alphabetical[50] ={0,};
void find_word(array a[MAX], char * input){
	int i = 0; 
	while(strcmp(a[i].name,"\0")){// if there word remain in array, keep searching.
		if(!strcasecmp(a[i].name,input)){ // if there has some match,
			a[i].count++;
		i++;
		return ;
			}
		i++;
		} //there is no words, or input is the first 'input word' joining array, 
	strcpy(a[i].name, input);
	a[i].name[sizeof(input)]='\0';
	a[i].count = 1;
	full_count++;
	return ;//full_count;
}
void dictionary(char *s){
	FILE *fd;
	int i = 0;
	char temp[MAX]= {'\0'}; 
	char store[MAX] = {'\0'};
	fd = fopen(s, "rb");
	while(1){
	fgets(buf, sizeof(buf), fd);
	if(feof(fd)) break; // return 1 if fd at the end of file 
	while(buf[i] == ' ' || buf[i]=='\t') i++; //check if document starts with white space 
	while(buf[i] != '\n'){ // when temp[i] meets  first letter, not  white space  /
		int j=0;
		store[j]='\0';
		if(buf[i]!= ' ' && buf[i]!= '\t'){
		while(buf[i] != ' ' && buf[i] != '\t'&&buf[i]!='\n'){// 
			store[j] = buf[i]; 
			i++, j++;
		} 
		if(store[j-1]<65 || (store[j-1]>90 && store[j-1]<97) || store[j-1] >122){
			store[j-1] = '\0';
		} 
		else store[j]= '\0';
	 	find_word(a,store);
	 	store[0] = '\0';
	 }
	 else i++;
	}
	i = 0, buf[0]='\0'; 
 }
}
void swap(array a[], int i , int j)
{
	array temp[1] ={{"\0",0}}; 
	temp[0] =a[i];
	a[i] = a[j];
	a[j] = temp[0];
}
int partition(array a[],int from, int to){
	int p = a[from].count; // pivot _value
	int i = from;
	int j = from+1;
	while( j<=to){
		if(a[j].count>=p){
			i++; 
			swap(a,i, j);
		}
		j++;
	}
	swap(a,from,i);
	return i; 
}
void quicksort(array a[], int from, int to){
	if(from >=to) return;
	int m = partition(a, from, to);
	quicksort(a, from, m-1);
	quicksort(a, m+1,to);
}
int main(){
	char *s;
	printf("input file name:");scanf("%s",s);
	getchar();
	dictionary(s);
	quicksort(a, 0, full_count-1);
	int flag_count = 1; 
	for(int i = 0; i<sizeof(a);++i){
		if(!strcmp(a[i].name , "\0"))break;
		if(flag_count>5) break;
		printf("%s: %d\n",a[i].name, a[i].count);
		flag_count++;
	}
}
