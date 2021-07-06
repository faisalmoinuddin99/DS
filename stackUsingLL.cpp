#include<iostream>

using namespace std ;

struct node {

  int data ;
  struct node* next ;
};

struct node *top = NULL ;

void push(int val){
  struct node* nn = new node() ;
  if(!nn){
    cout<<"Heap overflow "<<endl ;
  }
  nn->data = val ;
  nn->next = top ;
  top = nn ;
}

void pop(){
  if(top == NULL){
    cout<<"Heap underflow "<<endl ;
  }
  struct node * temp = NULL ;
  temp = top ;
  top = top -> next ;
  temp->next = NULL ;
  free(temp) ;
}
void display(){
  struct node *tn = NULL ;

  tn = top ;
  while(tn != NULL) {
    cout<<tn->data<<endl ;
    tn = tn->next ;
  }
}
int main(){

  push(10) ;
  push(20) ;
  push(30) ;
  cout<<"After Pushing" << endl ;
  display() ;
  cout<<endl ;
  pop() ;
  display() ;

cout<<endl ;
  push(40) ;
  push(50) ;
  display() ;
  return 0 ;
}