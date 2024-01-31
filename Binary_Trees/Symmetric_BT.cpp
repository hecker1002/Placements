#include <bits/stdc++.h>
using namespace std ;

// Binary Trees - a Hierarchichal data structre where data is stored in heirarchichal manner .
// and Data is stored in nodes where each node has maximum 2 child nodes . 


// Binary Tree code -  make  a Node custom data type which has 3 parts ( data , 2 pointers for left child and right child )
// start initializing from root node .

// Node for Binary Tree 
struct Node {
    int data ; // data for Node 
    struct Node *left , *right ;  // ponters to store address of left and right child 

    // Constructor that runs automatically when Node is made .
    Node(int val){

        data = val ; // fill data space in Node memory
        left = NULL ;  // make left and right pointer point to NULLL by default whenever a nOde is made .
        right = NULL ;
    }



} ;

/*

Symmetric BT- left and right half of BT (abouts its  mirror ) is same
DO some traversal (pre-order) but in opposite sense on left and right subtree and if both return true then - Symmetric BT . 

*/


bool is_symm(struct Node* left_s , struct Node* right_s ){
    // if any of the node becomes non-exitent (null) , stop right there .
if ((left_s == NULL) || (right_s == NULL) ) return left_s == right_s ; // if both nodes ==NULL return true else False 


// else check traversal for both direction 9in opposite sense and check curr nodes data equality alongwith it .

return is_symm(left_s->left , right_s->right) && is_symm(left_s -> right  , right_s -> left) && (left_s->data == right_s->data ) ;

}



bool symmmetric_BT(struct Node* root) {

if(root==NULL)
return true ;

return is_symm(root->left , root->right ) ;

}



int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(2) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .
 root->right->left  = new Node(5) ; 

if(symmmetric_BT(root)) cout << "Symmetric" << endl ;
else cout << "non - symmmetric " << endl ;
    return 0 ;
}