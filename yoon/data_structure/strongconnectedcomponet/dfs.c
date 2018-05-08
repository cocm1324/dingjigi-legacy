//written by JaeWon Yoon 5/7. 
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50
#define FILENAME "hw4.data"
int vertex_count; 
int **basic_array; 
int **trans_array;
int *deg;
typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
}GraphNode;
typedef struct GraphType{
	int n; 
	GraphNode *adj_list[MAX_VERTICES];
}GraphType; 
//	printf("point\n");
typedef struct finish_node{
	int index_number;
	int finish_time;
}finish_node; 
int visited[MAX_VERTICES];
int discover[MAX_VERTICES];
finish_node finish[MAX_VERTICES];
int cur_Time = 0; 
typedef struct final_node{
	int discover;
	int finish_time;
	int index_number;
}final_node;
void graph_init(GraphType *g, int vertex_count){
	int v;
	deg = (int*)malloc(sizeof(int)*vertex_count);
	g->n = vertex_count;
	for(v = 0;  v< g->n; ++v){
		g->adj_list[v] =NULL; 
		deg[v] = 0; 
	}
}
int countV(FILE *fd){
	char buf[100];
	fd = fopen(FILENAME, "rb");
	fgets(buf, sizeof(buf), fd);
	char *firstLine = buf;
	int idx = 0;
	int cnt = 0;
	while(firstLine[idx]){
		if(firstLine[idx]>='A' && firstLine[idx] <='Z') ++cnt;
		idx++; 
	}
	return cnt;
}
void read_array(FILE *fd, GraphType *g){
	fd = fopen(FILENAME, "rb"); 
	char temp_buf[100]; 
	fgets(temp_buf, sizeof(temp_buf), fd);
	for(int i = 0; i<g->n; ++i){
		char tmp;
		fscanf(fd, "%c", &tmp);
		for(int j= 0; j<g->n; ++j){
			int check;
			fscanf(fd, "%d ", &check);
			basic_array[i][j] = check;
		}
	}
	for(int i =0; i <g->n; ++i){
		for(int j =0; j<g->n; ++j){
			trans_array[j][i] = basic_array[i][j];
		}
	}
	
}
void insert_edge(GraphType *g, int u, int v){
	GraphNode *node; // 삽입할 노드 
	GraphNode *point_node; // 인접리스트가  NULL을 가르킬 때까지 이동 
	GraphNode *insert_point;// point_node가 NULL을 가르킬때의 전 노드를 가르킴 
	if(u>=g->n||v>=g->n){
		fprintf(stderr,"u,v should smaller than g->n");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node ->link = NULL;
	if(g->adj_list[u]==NULL) {g->adj_list[u] = node;
	}
	else{
		point_node = g->adj_list[u];
		while(point_node!=NULL){
			insert_point = point_node;
			point_node= point_node->link;
		}
		insert_point->link = node;
	}
}

void draw_edge(GraphType *g,int **array)
{
	for(int i = 0 ; i <g->n; ++i){
		for(int j = 0; j <g->n; ++j){
			if(array[i][j]){
					insert_edge(g, i, j); 
			}
		}
	}
}

void printAdjList(GraphType *g){
	GraphNode *print_node; 
	for(int u = 0; u<g->n; ++u){
		if( u == 0)printf("1)\n");
		printf("%c -> |", u +'A');
		print_node = g->adj_list[u];
		while(print_node!=NULL){
			printf("%c ->", print_node ->vertex + 'A');
			print_node = print_node->link;
		}
	printf("nil\n");
	}
}
void init_visit(int visited[], int discover[], GraphType *g){
	for(int i = 0; i <g->n; ++i){
		visited[i] = 0;
		discover[i] = 0;
	}
}
void init_finish(finish_node finish[],GraphType *g){
	for(int i = 0; i <g->n; ++i){
		finish[i].finish_time=0;
		finish[i].index_number = i;
	}
}
void dfs_visit(GraphType *g, int u){
	visited[u] = 1;
	discover[u] = cur_Time++;
	GraphNode *w;
	for(w = g->adj_list[u]; w; w=w->link){
		if(!visited[w->vertex]){
			dfs_visit(g,w->vertex);
		}
	}
	finish[u].finish_time=cur_Time++;
}
void dfs(GraphType *g){
	cur_Time = 1; 
	for(int i =0; i<g->n; ++i){
		if(!visited[i]) dfs_visit(g,i);
	}
}
void printdfstime(GraphType *g){
	for(int u = 0; u<g->n; ++u){
		if(u==0) printf("2)\n");
		printf("%c  |", u +'A');
		printf("%d / ", discover[u]);
		printf("%d\n", finish[u].finish_time);
	}
}
void printAdjList2(GraphType *g){
	GraphNode *print_node; 
	for(int u = 0; u<g->n; ++u){
		if( u == 0)printf("3)\n");
		printf("%c -> |", u +'A');
		print_node = g->adj_list[u];
		while(print_node!=NULL){
			printf("%c ->", print_node ->vertex + 'A');
			print_node = print_node->link;
		}
	printf("nil\n");
	}
}
void dfs2(GraphType *g, finish_node arr[]){
	cur_Time=1;
	for(int i = 0; i<g->n; ++i){
		if(!visited[arr[i].index_number]){
			dfs_visit(g,arr[i].index_number);
		}
	}
}
void decrease(finish_node arr[], GraphType *g){
	finish_node temp;
	for(int i =0; i <g->n-1; i++){
		for(int j = 0; j <g->n -1-i; j++){
			if(arr[j].finish_time <arr[j+1].finish_time){
				temp = arr[j];
				arr[j]= arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
void decrease2(finish_node arr[], GraphType *g){
	finish_node temp;
	for(int i =0; i <g->n-1; i++){
		for(int j = 0; j <g->n-1-i; j++){
			if(arr[j].finish_time<arr[j+1].finish_time){
				temp.finish_time = arr[j].finish_time;
				temp.index_number = arr[j].index_number;
				arr[j].finish_time= arr[j+1].finish_time;
				arr[j].index_number = arr[j+1].index_number;
				arr[j+1].finish_time = temp.finish_time;
				arr[j+1].index_number = temp.index_number;
			}
		}
	}
}
void printdfstime2(GraphType *g){
	for(int u = 0; u<g->n; ++u){
		if(u==0) printf("4)\n");
		printf("%c  |", u +'A');
		printf("%d / ", discover[u]);
		printf("%d\n", finish[u].finish_time);
	}
}
void test(finish_node arr[], GraphType *g,final_node final[]){
	for(int i = 0; i <g->n; ++i){
		final[i].finish_time = arr[i].finish_time;
		final[i].discover = discover[arr[i].index_number];
		final[i].index_number = arr[i].index_number;
	}
	
}
void test_print(final_node arr[], GraphType *g){
	for(int i = 0; i <g->n; ++i){
		printf("%d /", arr[i].discover);
		printf("%d / ", arr[i].finish_time);
		printf("%c \n", arr[i].index_number +'A');
	}
}
void scc(final_node arr[], GraphType *g){
	 
	printf("5)\n");
	int count = 1; 
	printf("scc %d): ", count);
	for(int i = (g->n)-1; i>=0; --i){
		int flag1 = 0; 
		for(int j = 0; j <g->n; ++j){
			if(j==0)printf("%c ", arr[i].index_number +'A');
			
			if(arr[j].discover == arr[i].finish_time+1){ 
				flag1 = 1;
			   for(int k =0; k <g->n; ++k){
			   if(arr[i].discover-1 == arr[k].discover && j<i) flag1 =0;
			   }
			}
			
			if(flag1 && j==g->n-1){ printf("\nscc %d): ",++count);	
		
			}
		}
	}
	printf("\n");
}
int main(){
	FILE *fd; 
	vertex_count = countV(fd);
	trans_array = (int **)malloc(sizeof(int*)*vertex_count);
	basic_array = (int **)malloc(sizeof(int*)*vertex_count); 
	for(int i = 0; i<vertex_count; ++i){
		*(basic_array+i) = (int *)malloc(sizeof(int)*vertex_count);
		*(trans_array+i) = (int *)malloc(sizeof(int)*vertex_count); 
	}
	GraphType *real_graph  =(GraphType *)malloc(sizeof(GraphType));
	GraphType *trans_graph =(GraphType *)malloc(sizeof(GraphType));
	final_node final[vertex_count]; 
	graph_init(real_graph, vertex_count);
	read_array(fd,real_graph);
	draw_edge(real_graph, basic_array);
	printAdjList(real_graph);
	init_visit(visited,discover,real_graph);
	init_finish(finish,real_graph);
	dfs(real_graph);
	printdfstime(real_graph);
	//---------------------------------
	graph_init(trans_graph, vertex_count);
	read_array(fd,trans_graph);
	draw_edge(trans_graph, trans_array);
	printAdjList2(trans_graph);
	//---------------------------------
	decrease(finish, trans_graph);
	init_visit(visited,discover,trans_graph);
	dfs2(trans_graph, finish);
	printdfstime2(trans_graph);
	//----------------------------------
	for(int i = 0; i <vertex_count;++i){
		finish[i].index_number = i;
	}
	decrease2(finish,trans_graph);
	
	test(finish,trans_graph,final);
	//test_print(final,trans_graph);
	scc(final,trans_graph);
}
