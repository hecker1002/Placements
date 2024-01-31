#include <bits/stdc++.h>
using namespace std ;

/*
DFS - Depth First Search traversal technique in BT 

Pre- Order Traversal - (Root _>  left subtree -> right subtree )
apply this principal at every Node 

*/

// node - data sapce in memory - 1 unit of BT 
struct Node {

int data ; 
struct Node* left , *right ;

// constructor - when  [new node()] is initialized .
 
Node (int val ){
    data = val ;
   left = NULL ; right = NULL ; // simply access it inside declaration of class as left , right 
}


};
/*

Recover a BST (when 2 Nodes are alreay swapped . 

Logic - Do inorder traversal of BST , (sorted always ) , and takes 2 cases 
1. swapped ele are adjacent . ( first , middle an last vioalation  are stored )
2. swapped elements are NOT adjacent . ( ONLY first and middle vilation are stored )
and 
hence we get the swapped elemnts . 
)*/


void inorder ( struct Node* root , struct Node* &prev , struct Node* &first , Node* &middle , Node* &last  ){
  

  if(root==NULL){
    return ;
  }

inorder(root->left ,prev ,  first , middle , last ) ;

if(prev!=NULL && root->data < prev->data){ // violation 
   

   // check if its first violation then store , first an d middle only 
    if(first==NULL){
    first = prev ;
    middle = root ; }
 
 // if second vioaltion , store last 
    else {
        last = root ;
    } 
}

prev = root ; // keep on marking the prev node of BST .

inorder(root->right ,prev ,  first , middle , last ) ;

}

void recover_BST(struct Node* root) {

struct Node* prev = new Node(INT_MIN) ;

struct Node* first = NULL ;

struct Node* middle  = NULL ;

struct Node* last  = NULL ;

inorder(root ,prev ,  first , middle , last  ) ;

if(first && last) swap(first->data , last->data) ;
else if(first && middle) swap (first->data , middle->data ) ;

}


void in_or( struct Node* root ){
    if(root==NULL){
        return ;
    }
in_or(root->left) ;
cout << root->data <<" " ;
in_or(root->right) ;
}


int main(){

// new node(1) = initlaizes a node in memory ar random position but BT structre automatically gives its a storage a heirrachivhal fashion .
struct Node * root = new Node(4) ;

root->left = new Node(2) ;
root->left->right = new Node(3) ;
root->left->left = new Node(7) ;

root->right = new Node(6) ;
root->right->left = new Node(5) ;
root->right->right = new Node(1);


/*
Our Tree above 

     4
   /   \
  2      6
 /\     / \
 1 3   5   7
*/

// store the vioaltion of sorting 
struct Node* prev = NULL ;

struct Node* first = NULL ;

struct Node* middle  = NULL ;

struct Node* last  = NULL ;

recover_BST(root) ;

in_or(root) ;

    return 0 ;
}