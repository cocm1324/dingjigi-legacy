#include <stdio.h>
#include <iostream>

using namespace std;

class LinkedList{
private:
      Node* record;
      Node* pos;
      void quickSort(int, int, int);
      void swap(int, int);
public:
      LinkedList();
      ~LinkedList();
      int isEmpty();
      int hasNext();
      void add(int);
      void destroy(int);
      void sort(int);
      Node* index(int);
      int getValue(int);
}

typedef struct{
      int value;
      Node* left;
      Node* right;
}Node;

int main(){
      int n;
      int* a;
      int* b;

      scanf("%d", &n);
      a = new int[n];
      b = new int[n];

      for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
      }

      for (int i = 0; i < n; i++){
            scanf("%d", &b[i]);
      }

      sort(a, n);
      sort(b, n);

      delete[] a;
      delete[] b;
      a = NULL;
      b = NULL;

      return 0;
}

void LinkedList::quickSort(int left, int right);
void LinkedList::swap(int index1, int index2){

}

LinkedList::LinkedList(){
      this->record = NULL;
      this->pos = NULL;
}

LinkedList::~LinkedList(){

}

int LinkedList::isEmpty(){
      if(this->record == NULL && this->pos == NULL){
            return 1;
      }
      else{
            return 0;
      }
}

int LinkedList::hasNext(){

}

void LinkedList::add(int input){
      Node* temp = new Node;
      temp->value = input;
      temp->left = NULL;
      temp->right = NULL;

      if(!isEmpty()){
            this->pos->right = temp;
            this->pos = temp;
      }
      else{
            pos = temp;
            this->record = temp;
      }
}

void LinkedList::destroy(int){
      if(!isEmpty()){
            this->pos = this->pos->left;
            delete(this->pos->right);
            this->pos->right = NULL;
      }
      else if(this->pos->left == NULL){
            delete(this->pos);
            this->pos = NULL;
            this->record = NULL;
      }
}

void LinkedList::sort(int){

}

Node* LinkedList::index(int){

}

int LinkedList::getValue(int){

}
