#include <bits/stdc++.h>
using namespace std ;


/*

Travel in a Linked List .

Linked List is a linear data structure which stores the elements in a linear way and is like a dynamic-sized array .
building block of LL are - Nodes 

Nodes - are memory spaces where data and address of the next node is stored . and these nodes are connected in a chain 
(in non-contiguous way) and that makes a linked list .

make a linked list by declaring a custom data type (node) whose data members are data and address of the next node and use representatio
of a node (like node curr) to access any node of a linked list and  and last nodes of a LL -> points to NULL (nothing) to symbolize
the end of a LL .

by convention , first node of a LL = head node .

Node* x = is a repreentation of the node 

*/

/*

Constructors in C++ - these functions / methods are called automatically when new instance of the object is created .
AND VERY VERY IMP. " CONSTRUCTORS IN C++ HAVE SAME NAME AS CLASS NAME .  and constructors do NOT need to be called seperately .

*/



// Making the Node (custom data type )


class node {

public :

// data stored in current node 
int data ;
// address of the next node  
node* next ;

// constructor so when a node is initialized in memory , it makes all these aprts ready-made 

 node(int val ){
    data = val ;
    next = NULL ;
 }

} ;






// we use node* &head to pass head by reference (and not by value) since we need to update head too if LL is empty .

void insert_In_LL( node* &head , int data  ){

node* Add = new node(data) ;

node* curr = head ;

// Corner Case 
if(head==NULL){
    
 head = Add ;
 return ;

}

while(curr->next!=NULL){

curr = curr->next ;
}
curr->next = Add ;

}




//Traverse in  a LL (in a linear way )

// we pass head by value (and not by reference ) , since we are NOT changing any head or any other nde of the LL .

void traverse_LL (node* head ){


node* curr = head ;

// edge case (empty LL)
if(head==NULL){
    return ;
}

// travel in a LL till we reach the last node .

while(curr!=NULL){
    cout << curr->data << " " ;
    curr = curr->next ;
}
cout << endl ; 


}


// main function 

int main(){

// make an empty linked list .
node* head  = NULL ;

  insert_In_LL(head , 3) ;
  insert_In_LL(head , 4) ;
  insert_In_LL(head , 5) ;

  traverse_LL(head) ;

    return 0 ;
}

/*

While dealing with nodes in a Linked Lisat , always use pointers , ( node* name_of_node )

*/