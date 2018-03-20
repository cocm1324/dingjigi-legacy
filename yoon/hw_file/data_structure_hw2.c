#include<stdio.h>
#include<stdlib.h>
//written by 21300492 JaeWon Yoon
float ** add_matrix(float **a, float **b, int a_height, 
	int a_width, int b_height, int b_width);
//add_matrix
float ** mul_matrix(float **a, float **b, int a_height,
	int a_width, int b_height, int b_width);
//mul_matrix
float ** transpose(float **a, int a_width, int b_width);
//transpose_matrix
void error(char *message){
	fprintf(stderr, "%s\n",message);
}
//notice error when pairs of parenthesis calculate is not allowed
int main(){

FILE *file_pointer; 
char * file1;
file1 = (char*)malloc(sizeof(file1)+1); 
char * file2;
file2 = (char*)malloc(sizeof(file2)+1);
char * file3;
file3 = (char*)malloc(sizeof(file2)+1);
char choice;

printf("What operation do you want? ('a','m','t')\n");
scanf("%c", &choice);
printf("input file names:\n");
scanf("%s",file1);
getchar();
if(choice!='t'){
scanf("%s",file2);
getchar();}
file_pointer=fopen(file1,"r");
int a_height=0, a_width=0, b_height=0, b_width=0;
float **a, **b;
float buffer = 0; 
fscanf(file_pointer, "%d", &a_height);
fscanf(file_pointer, "%d", &a_width);
//build matrix a
a =  (float**)malloc(sizeof(float*)*a_height+1);
for(int i =0; i<a_height; i++){
*(a+i) = (float*)malloc(sizeof(float)*a_width+1);
}
for(int i = 0; i<a_height; i++){
	for(int j = 0; j<a_width; j++){
		fscanf(file_pointer,"%f",&buffer);
		*(*(a+i)+j)=buffer;
		
		}
	}
//build matrix b
if(choice!='t'){
file_pointer=fopen(file2,"r");
fscanf(file_pointer, "%d", &b_height);
fscanf(file_pointer, "%d", &b_width);
b = (float**)malloc(sizeof(float*)*b_height+1);
for(int i =0; i<b_height; i++){
*(b+i) = (float*)malloc(sizeof(float)*b_width+1);
}
for(int i=0; i<b_height; i++){
	for(int j = 0; j <b_width; j++){
		fscanf(file_pointer,"%f",&buffer);
		*(*(b+i)+j)=buffer;	
		}
	}
}
switch(choice){
	case 'a':{	
				printf("the output file names?\n");
				scanf("%s",file3);
				file_pointer = fopen(file3,"a");
				int c_height = a_height;
				int c_width = a_width;
				float **c = add_matrix(a, b, a_height,a_width, b_height, b_width);
				fprintf(file_pointer,"%d %d", c_height,c_width);
				fputs("\n",file_pointer);
				for(int i=0; i<a_height; i++){
				for(int j = 0; j <a_width; j++){
				fprintf(file_pointer, "%.2f ",(*(*(c+i)+j)));	
				}
				fputs("\n",file_pointer);
			}
			free(c);
			//free pointers and close file stream
			fclose(file_pointer);
		}
			break;
	case 'm':{
				printf("the output file names?\n");
				scanf("%s",file3);
				file_pointer = fopen(file3,"a");
				int c_height = a_height;
				int c_width = b_width;
				float **c = mul_matrix(a, b, a_height,a_width, b_height, b_width);
				fprintf(file_pointer,"%d %d", c_height,c_width);
				fputs("\n",file_pointer);
				for(int i=0; i<c_height; i++){
				for(int j = 0; j <c_width; j++){
				fprintf(file_pointer, "%.2f ",(*(*(c+i)+j)));	
				}
				fputs("\n",file_pointer);
			}
			free(c);
			//free pointers and close file stream
			fclose(file_pointer);
		}
			break;
	case 't':{
				printf("the output file names?\n");
				scanf("%s",file3);
				file_pointer = fopen(file3,"a");
				int c_height = a_width;
				int c_width = a_height;
				float **c = transpose(a, a_height,a_width);
				fprintf(file_pointer,"%d %d", c_height,c_width);
				fputs("\n",file_pointer);
				for(int i=0; i<c_height; i++){
				for(int j = 0; j <c_width; j++){
				fprintf(file_pointer, "%.2f ",(*(*(c+i)+j)));	
				}
				fputs("\n",file_pointer);
		
	}
			break;
	default: return 0;
		}
	}
free(file1);
free(file2);
free(file3);
}
//define each matrix operation
float ** add_matrix(float **a, float **b, int a_height, int a_width, int b_height, int b_width){
	float **c; 
	if((a_width != b_width) && (a_height != b_height)){
		error("matrix operation can't be executed\n");
		error("reason: different size of matrix\n");
		exit(1);
	}
	else{
		//build matrix c
		
		int c_height = a_height;
		int c_width = a_width;
		c = (float**)malloc(sizeof(float*)*c_height+1);
		for(int i =0 ; i<c_height; i++){
		*(c+i) = (float*)malloc(sizeof(float)*c_width+1);
		}
		for(int i =0; i <c_height; i++){
			for(int j =0; j<c_width; j++){
				*(*(c+i)+j) = (*(*(b+i)+j)) + (*(*(a+i)+j));
			}
		}	
	}
	return c;

}

float ** mul_matrix(float **a, float **b, int a_height,
	int a_width, int b_height, int b_width){
	float **c; 
	if(a_width != b_height){
		error("matrix operation can't be executed\n");
		exit(1);
	}
	else{
		int c_height = a_height;
		int c_width = b_width;
		float sum = 0; 
		c = (float**)malloc(sizeof(float*)*c_height+1);
		for(int i =0 ; i<c_height; i++){
		*(c+i) = (float*)malloc(sizeof(float)*c_width+1);
		}
		for(int i =0; i <c_height; i++){
			for(int j =0; j<c_width; j++){
				for( int k = 0; k< a_height; k++){
					sum+=  (*(*(a+i)+k)) * (*(*(b+k)+i));
				}
				*(*(c+i)+j) = sum;
			}
		}	
	}
	return c;
}

float ** transpose(float **a, int a_height, int a_width){
	float **c; 
	int c_height = a_width;
	int c_width = a_height;
	c = (float**)malloc(sizeof(float*)*c_height+1);
	for(int i =0 ; i<c_height; i++){
		*(c+i) = (float*)malloc(sizeof(float)*c_width+1);
		}
	for(int i =0; i <c_height; i++){
		for(int j =0; j<c_width; j++){
				*(*(c+i)+j) = (*(*(a+j)+i));
			}
		}	
	return c;
}
