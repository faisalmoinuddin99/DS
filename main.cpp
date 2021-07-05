#include<iostream>
using namespace std ;

struct Node {
  int data ;
  struct Node *next ;
};
struct Node *start = NULL ;

void creatLL(int val){
  struct Node *nn = NULL ;
  struct Node *tn = NULL ;

  nn = (struct Node*) malloc(sizeof(struct Node));
  nn -> data = val ;
  nn -> next = NULL ;

  if(!start) {
    start = nn ;
  } else {
    tn = start ;
    while(tn -> next != NULL){
      tn = tn->next ;
    }
    tn->next = nn ;
  }
}
void insertAtBeg(int val) {
  struct Node *nn ;
  nn = (struct Node*) malloc(sizeof(struct Node));

  nn->data = val ;
  nn->next = start ;
  start = nn ;
}

void insertAtIndex(int data, int index) {

struct Node *nn = NULL ;
struct Node *tn = start ;

nn = (struct Node*) malloc(sizeof(struct Node));

int i = 0;
while(i != index - 1) {
  tn = tn -> next ;
  i++ ;
  }
  nn -> data = data ;
  nn -> next = tn -> next ;
  tn -> next = nn ;

}
void display(){
  struct Node *tn = NULL ;
  if(start == NULL) {
    cout<<"Linked List is EMPTY: "<< endl ;
  }
  tn = start ;
  while(tn != NULL){
    cout<<tn->data << " " ;
    tn = tn->next ;
  }
  
}

// Deletetion Logic

void delFirstElement() {
  struct Node *tn = start ;
  start = start -> next ;

  free(tn) ;
}

void deleteLastNode(){


  // Find the second last node
   struct Node* second_last = start;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
 
    // Delete last node
    free(second_last->next);
 
    // Change next of second last
    second_last->next = NULL;

}
int main() {

// create ll 
 creatLL(10) ;
 creatLL(20) ;
 creatLL(40) ;

 cout<<"\n"<< endl ;
 display() ;

 cout<<"\n"<< endl ;
 insertAtIndex(30, 2) ;
 display() ;

  cout<<"\n"<< endl ;
 insertAtIndex(50, 2) ;
 display() ;

  cout<<"\n"<< endl ;
 insertAtIndex(60, 4) ;
 display() ;

 // delete
 cout<<"\n"<<endl ;
 delFirstElement() ;
 display() ;

 // delete
 cout<<"\n"<<endl ;
 deleteLastNode() ;
 display() ;
  return  0 ;
}