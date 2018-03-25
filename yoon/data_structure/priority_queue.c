#include<stdio.h>
#include<stdlib.h>
///우선순위 큐 ,  히프 사용
#define MAX_ELEMENT 200
typedef struct{
	int key;
}element;
typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

//초기화 함수 
void init(HeapType *h)
{
	h->heap_size = 0;
}

//삽입함수 
void insert_max_heap(HeapType *h, element item){
	int i;
	i = ++(h->heap_size);

	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정 
	while((i!= 1) && (item.key) > h->heap[i/2].key){//i 가 1이 아니고, 삽입하려는 
		//키값이 부모 키값보다 클떄, 
		h->heap[i] = h->heap[i/2];// 부모노드로 삽입한다. 
		i /= 2; // 최종 i가 가르키는 값.  말단 노드에서 어디까지 올라갔는가? 
	} 
	h->heap[i] = item;
}

element delete_max_heap(HeapType *h){
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h-> heap[(h->heap_size)--]; //말단 노드릉 집어 넣은 다음에 heap_size하나 줄여준다.
	parent = 1;
	child = 2;
	while(child <= h->heap_size){
		//현재 노드와 자식노드 중 더 큰 자식노드를 찾는다.
		if( (child <h->heap_size) && (h->heap[child].key) < h->heap[child+1].key){
			// child가 가르키는 인덱스가 heap_size를 벗어나는지 검사한다. 이유는 나중에 child가 *2씩
			// 되어지기 때문이다. 
			// 또한 현재 child 노드 중 어느 것이 더 큰 것인지 미리 검사하여 비교 값으로 삼는다.
			// 왜냐하면 parent노드에는 자식 노드 두개 중 큰 것이 들어가야 함으로 temp와 비교할 
			// 대상이 되어야지 상위 노드로 올라갈 수 있다. 
			child++; //비교할 child 노드는 오른쪽이다.  으론쪽이 더 크니까 
		}
		if(temp.key>= h->heap[child].key) break; //말단 노드가 비교할 child의 키 값보다
		//크거나 같으면 연산 할 필요가 없다.  break문으로 빠져나간다. 
		h-> heap[parent] = h->heap[child]; // parent에 child 값 넣어준다.
		parent = child; //다음에 비교할 parent 인덱스를 정해준다. 
		child *= 2; // child값은 *2 해준다. 
	}
	h->heap[parent] = temp;
	return item;
}

int main(){
	element e1={10}, e2 = {5}, e3 = {30};
	element e4, e5, e6;
	HeapType heap;
	init(&heap);
	//삽입
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);

	e4 = delete_max_heap(&heap);
	printf("%d\n", e4.key);

}
