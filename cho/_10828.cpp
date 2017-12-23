#include <iostream>
#include <limits>
using namespace std;

//class
class Node{
private:
  int value;
  Node* prev;
  Node* next;

public:
  Node(int value){
    this->value = value;
    this->prev = NULL;
    this->next = NULL;
  }

  ~Node(){
    this->prev = NULL;
    this->next = NULL;
  }

  int getValue(){
    return this->value;
  }

  void setValue(int input){
    this->value = input;
  }

  void setPrev(Node* node){
    this->prev = node;
  }

  void setNext(Node* node){
    this->next = node;
  }

  Node* getPrev(){
    return this->prev;
  }

  Node* getNext(){
    return this->next;
  }

};

class LinkedList{
protected:
  Node* pos;
  int size;

public:
  LinkedList(){
    this->pos = NULL;
    size = 0;
  }
  LinkedList(int a){
    this->pos = NULL;
    this->add(a, this->pos);
  }

  ~LinkedList(){
    endPos(this->pos);
    while(this->pos->getPrev() != NULL){
      del(this->pos);
    }
    del(this->pos);
  }

  Node* getPos(){
    return this->pos;
  }

  void add(int a, Node* pos){
    Node* node = new Node(a);

    if(pos != NULL){
      if(pos->getNext() == NULL){
        pos->setNext(node);
        node->setPrev(pos);
        node->setNext(NULL);
      }
      else{
        pos->getNext()->setPrev(node);
        node->setNext(pos->getNext());
        node->setPrev(pos);
        pos->setNext(node);
        nextPos(pos);
      }
    }
    else{
      pos = node;
      node->setPrev(NULL);
      node->setNext(NULL);
    }

    this->size++;
  }

  void del(Node* pos){
    if(pos->getNext() == NULL){
      if(pos->getPrev() == NULL){
        pos = NULL;
      }
      else{
        pos = pos->getPrev();
        pos->getNext()->setPrev(NULL);
        delete(pos);
        pos->setNext(NULL);
      }
    }
    else{
      pos = pos->getPrev();
      pos->setNext(pos->getNext()->getNext());
      pos->getNext()->getPrev()->setPrev(NULL);
      pos->getNext()->getPrev()->setNext(NULL);
      delete(pos->getNext()->getPrev());
      pos->getNext()->setPrev(pos);
    }
    this->size--;
  }

  void nextPos(Node* pos){
    pos = pos->getNext();
  }

  void prevPos(Node* pos){
    pos = pos->getPrev();
  }

  void endPos(Node* pos){
    if(pos!=NULL){
        while(pos->getNext() != NULL){
          nextPos(pos);
        }
    }
  }

  void startPos(Node* pos){
    if(pos!=NULL){
        while(pos->getPrev() != NULL){
          prevPos(pos);
        }
    }
  }

  int sizeOf(){
    return this->size;
  }

  int peek(Node* pos){
    if(pos != NULL){
      return pos->getValue();
    }
    else{
      //cout << "Warning! : Stack Empty!" << endl;
      return numeric_limits<int>::max();
    }
  }
};

class Stack : public LinkedList{
protected:
  Node* top;
  Node* bottom;

public:
  Stack(){
    this->top = NULL;
    this->bottom = NULL;
  }

  Stack(int a){
     this->top = NULL;
     this->bottom = NULL;

     this->add(a,top);
     this->bottom = this->top;
  }

  ~Stack(){
    endPos(this->top);
    while(this->top->getPrev() != NULL){
      del(this->top);
    }
    del(this->top);
    this->bottom = NULL;
  }

  Node* getTop(){
    return this->top;
  }

  Node* getBottom(){
    return this->bottom;
  }

  int isEmpty(){
    if(this->bottom == NULL){
      return 1;
    }
    else{
      return 0;
    }
  }

  void push(int a){
    Node* node = new Node(a);

    if(this->bottom == NULL){
      this->bottom = node;
      this->top = node;
      this->size++;
    }
    else{
      this->top->setNext(node);
      node->setPrev(this->top);
      this->top = node;
      this->size++;
    }
  }

  int pop(){
    if(this->isEmpty()){
      int a = this->top->getValue();
      this->del(this->top);
      this->size--;
      return a;
    }
    else{
      //cout << "Warning! : Stack Empty!" << endl;
      //return numeric_limits<int>::max();
      return -1;
    }
  }
};

int main(){
  int temp;
  string inputBuf;
  int inputNum = 0;
  Stack* st = new Stack();

  cin >> temp;
  for(int i = 0; i < temp; i++){
    cin >> inputBuf;
    if(inputBuf.compare("push") == 0){
      cin >> inputNum;
      st->push(inputNum);
    }
    else if(inputBuf.compare("pop") == 0){
      cout << st->pop() << endl;
    }
    else if(inputBuf.compare("empty") == 0){
      cout << st->isEmpty() << endl;
    }
    else if(inputBuf.compare("size") == 0){
      cout << st->sizeOf() << endl;
    }
    else if(inputBuf.compare("top") == 0){
      cout << st->peek(st->getTop()) << endl;
    }
  }
  return 0;
}
