#include <bits/stdc++.h>
using namespace std ;

// Iterative and Recursive soln both .
// In LL , node* curr OR node* head is default way to access nodes 

// Creating  a Linked  List (custom data type ==> collection of node s )

class node {

public :

  int data ;
  node* next ;

  node(int val){

    data= val ;
    next = NULL ;
  }
};

// No need to change the head , so pass by value (node* head )

// iterative soln .

node* reverse_LL (node* head ){

  if(head==NULL){
    return NULL ;
  }

// iterator  node 
  node* curr = head ;


stack<node*> st ;

while(curr->next!=NULL){
  st.push(curr) ;
  curr = curr->next ;
}

node* ans = curr ;

while(!st.empty()){

  node* prev = st.top() ;

 curr->next = prev ;
 curr = curr->next ;
  st.pop() ;
}

curr->next = NULL ;

return ans  ;

}



// recursive soln to reverse a LL , 

node* reverse_LL_recursion (node* head){

  // BC 
if(head==NULL){
  return NULL ;
}

  if(head->next==NULL ){

    return head ;
  }
  // hypothesis - it can reverse LL for  any head 
  // here by hypothesis , we mean that the recursive function reverses the LL and returns to us , the head of such a reversed LL .

  // Induction 

  node* curr = head->next ;

  node* head1 = reverse_LL_recursion(curr) ; // making input smaller


// re-defining the connection of reversed LL with node just after head in LL , 
//it should be connected(head->next->next = is next of node after head node) with the old head node . and old head node's next = NULL.
 head->next->next  = head ;
  head->next = NULL ;

return head1 ;


}
void insert_LL (node* &head , int val ){

  node* curr = head ;

  node* add = new node(val) ;


if(head== NULL){

  head = add ;
  return ;
}
  while(curr->next!=NULL){

    curr = curr->next ;
  }

  curr->next = add ;

}


void display(node* head){

  node* curr = head ;
if(head==NULL){
    return ;

  }

  while(curr != NULL){
    cout << curr->data << " " ;
    curr = curr->next ;
  }

cout << endl ;
}





int main(){
  
  node* head = NULL ;

  insert_LL(head , 3) ;
  insert_LL(head , 4) ;
  insert_LL(head , 5) ;


// before reversal 
display(head) ;

node* new_head  = reverse_LL(head) ;

// after reversal 

display(new_head) ;

// after revrsal from recursion 

node* head2 = NULL ;

  insert_LL(head2 , 3) ;
  insert_LL(head2 , 4) ;
  insert_LL(head2 , 5);


node* new_head1  = reverse_LL_recursion(head2) ;
display(new_head1) ;

    return 0 ;
}