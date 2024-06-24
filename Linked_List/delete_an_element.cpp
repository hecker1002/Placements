#include <bits/stdc++.h>
using namespace std ;


/*

deleting an element from a linked list by deleeting data and changing connections only between the nodes of LL .

travel in a LL till 1 node before the node to be deleted (nsed on position of node) and
when you are 1 node prev to it , update the pointer of prev  to prev->next->next and free the pointer of the node to be deleted (free(ptr))
and delete the node too. (optional )
*/


class node {

    public :

    int data ;
    node* next ;

    // constructor 
    node(int val){
        data = val ;
        next = NULL ;
    }
};
// whenever you are dealing with LL , always deal with pointers to access nodes / other elements of LL .

// if we pass head , we are passing the whole LL .

void insert(node* &head , int val){

    node* add = new node(val) ;

   if(head==NULL){
    head = add ;
    return ;
   }
  // temporary node pointer (stores current node address , to move forward in LL , change the address in current node to next node .)
   node* temp = head ;

   while(temp->next!=NULL){
    temp = temp->next ;
   }

   temp->next = add ;

}

void display(node* head){

    node* temp = head ;

    if(head==NULL){
        return ;
    }

    while(temp!=NULL){

        cout << temp->data <<" " ;
        temp = temp->next ;
    }
}


// deletion of an element from a LL . based on position

// 0 base indexing is followed in LL by default .
void delete_node(node* &head , int pos ){

node* temp = head ;

// for deleting head , pass the head by reference (since we are changing head if pssoble) 
if(pos==0 ){
    head = temp->next ;
   free(temp) ;
    return ;
}

// travel tilll you find a node whose enxt element is given no.
int i =0 ;
while(temp != NULL && i<pos-1){
   
   temp = temp->next ;
   i++;
}

// delete that given no. by re-aligning the connection abd freeing the ppointer .
 node* temp1 = temp ;
    temp1 = temp->next ;
    temp->next = temp->next->next ;
   
    free(temp1);
    
}

// deleting a node without head pointer 

// void delete_no_head (node* head){


// }


int main(){
  

  node* head  = NULL ;

  insert(head , 3) ;
  insert(head , 4) ;
  insert(head , 5) ;
  insert(head , 6) ;

  display(head) ; // gives 3 4 5 6
  cout << endl ;
 
 delete_node(head , 2); // gives 3 4 6 
 display(head) ;

    return 0 ;
}