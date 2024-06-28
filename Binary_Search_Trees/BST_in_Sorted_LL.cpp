#include <bits/stdc++.h>
using namespace std ;

/*

Binary Search Tree - a SPECIAL BT where where at any node , its left child < root and right child > root .

To search for an element in a BST , check if val < root -> go to root->left and if  val > root , go to root->right .
*/
// Write a simple loop 


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

void inorder (Node* root){
//BC
if(root == NULL){
    return ; 
}
//Induction 
inorder(root->left) ;
cout << root->data << " " ;
inorder(root->right) ;

}

/*
Question - given a BST , print it in form  of a sorted Linked List ( where after every node, all nodes are greater than curr)
and left of curr points to nULL .  

BUT , do  it in O(H) SC  - H - height of BST 

LOGIC - While doinf recursive calls in INORDER( BST always sorted in this ) 0 te SC = O(H) 
and if we store tha nodes , SC = O(N) 
So , to escapre form O(N) ,w e dont unecesarrilt dtore the ndoes. 
Instead , while doing the rec calls of inordr , we know we wont ever visit the prev visited Node aain , so just change the conenctiosn 
of prev visited node .  ( prev.right =curr since curr> rpev always) and (prev.left = NULL)

*/

// Modified inorder(sorted) for BST // keeep a prev pointer to keep track of just previously visited node (pass prev by REFERENCE )
  
void mod_inorder( Node* curr , Node* &prev  ){

if( curr ==NULL){
    return  ; //last node 
}
mod_inorder( curr->left , prev ) ;
// at curr , chaneg conections of prev 
//inducion 
prev->right = curr ; // prev (L) < curr
prev->left = NULL ; // A/q
prev = curr ; // to iterate further 

mod_inorder( curr->right , prev ) ;
}



Node* flatten_BST(Node* root){

// make pointer prev initilly point to a madeu p dumy node (since addres cant be left empty )
Node* dummy = new Node(-1) ;
Node* prev = dummy ;

mod_inorder( root , prev ) ;

// for alst visited ndoe 
prev->right = NULL ;
prev->left =NULL ;

return dummy->right ; // actually , tis  is the first head ndoe of sotted LL 

}

int main(){

// new node(1) = initlaizes a node in memory ar random position but BT structre automatically gives its a storage a heirrachivhal fashion .
struct Node * root = new Node(4) ;

root->left = new Node(2) ;
root->left->right = new Node(3) ;
root->left->left = new Node(1) ;

root->right = new Node(6) ;
root->right->left = new Node(5) ;
root->right->right = new Node(7);


/*
Our Tree above 

     4
   /   \
  2      6
 /\     / \
 1 3   5   7
*/

Node* ans = flatten_BST( root) ;

inorder(ans) ;

    return 0 ;
}