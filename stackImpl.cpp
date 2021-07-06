#include<iostream>

using namespace std ;

struct Stack {
  int size ;
  int top ;
  int *arr ;
};

//isFull
int isFull(struct Stack *ptr){
  if(ptr->top == ptr->size - 1){
    
    return 1;
  }
  return 0 ;
}

//isEmpty
int isEmpty(struct Stack *ptr){
  if(ptr->top == -1){
    return 1 ;
  }
  return 0 ;
}
// push
 void push(struct Stack *ptr, int val){
  if(isFull(ptr)) {
    cout<<"stack overflow " <<"cannot push "<< val <<endl;
  }
  ptr->top++ ;
  ptr->arr[ptr->top] = val ;
}
// pop
int pop(struct Stack *ptr){
  if(isEmpty(ptr)){
    cout<<"stack underflow "<< endl ;
    return -1 ;
  }
  int val = ptr->arr[ptr->top] ;
  ptr->top-- ;
  return val ;
}

int peek(struct Stack *sp, int i) {
  int arrayPosition = sp->top - i + 1 ;
  if(arrayPosition < 0){
    cout<<"Invalid position" << endl ;
    return -1 ;
  }
  return sp->arr[sp->top-i+1] ;
  
}

// Top element
int stackTop(struct Stack *ptr){
  return ptr->arr[ptr->top] ;
}

// Bottom element
int stackBottom(struct Stack *ptr){
  return ptr->arr[0] ;
}
int main(){
  struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack)) ;
  sp->size = 6 ;
  sp->top = -1 ;
  sp->arr = new int(sp->size) ;
  cout<<"Before pushing:"<<endl ;
  cout<<"Full:"<<isFull(sp)<<endl ;
  cout<<"Empty:"<<isEmpty(sp)<<endl ;

  push(sp,10) ;
  push(sp,20) ;
  push(sp,30) ;
  push(sp, 40) ;

  cout<<"After pushing:"<<endl ;
  cout<<"Full:"<<isFull(sp)<<endl ;
  cout<<"Empty:"<<isEmpty(sp)<<endl ;

  cout<<"POP element: "<<pop(sp)<<endl ;

  for(int j = 1; j <= sp->top + 1; j++){
    cout<<"The value at position "<<j <<" "<< peek(sp,j)<<endl ;
  }

  cout<<"POP element: "<<pop(sp)<<endl ;

  for(int j = 1; j <= sp->top + 1; j++){
    cout<<"The value at position "<<j <<" "<< peek(sp,j)<<endl ;
  }
  cout<<endl ;
  push(sp,50) ;
  for(int j = 1; j <= sp->top + 1; j++){
    cout<<"The value at position "<<j <<" "<< peek(sp,j)<<endl ;
  }
  cout<<endl ;
  cout<<"Stack top most element is: "<<stackTop(sp) ;

  cout<<endl ;
  pop(sp) ;
  cout<<"Stack top most element is: "<<stackTop(sp) ;

  cout<<endl ;
  cout<<"Stack Bottom is:" << stackBottom(sp) ;
  return 0 ; 
}