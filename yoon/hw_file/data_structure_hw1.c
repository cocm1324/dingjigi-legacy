#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// written by jaewon Yoon 21300492
// march 12. 4pm is deadline
char * rep_line(char *src);

int main(){

while(1){
char *src =  (char *)malloc(sizeof(src));
scanf(" %[^\n]",src); 
getchar();
char * result = rep_line(src); 
printf("%s",result);
free(result); 
free(src); 
printf("\n");
}

}



char * rep_line(char *src)
{
  	char *trg; 
	trg = (char*) malloc(strlen(src)+1);
    int i = 0;
	////// using ascii code to replace small alphabetical word to big letter
	while(*(src+i) != '\0'){
		if(*(src+i) <91 && *(src+i) > 65)
		{
			*(trg+i) = (*(src+i)) +32;
		} 
		else if( *(src+i) >96 && *(src+i) < 123){
			*(trg+i) = (*(src+i)) -32;
		}
		else 
			*(trg+i) = *(src+i); 
		i++; 
	}
	return trg; 
}
