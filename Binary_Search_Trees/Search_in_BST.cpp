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

Binary Search Tree - a SPECIAL BT where where at any node , its left child < root and right child > root .

To search for an element in a BST , check if val < root -> go to root->left and if  val > root , go to root->right .
*/
// Write a simple loop 

struct Node* find_BST ( struct Node* root  , int val ){

struct Node* curr = root ;
while ( curr!=NULL &&  (curr->data )!= val){

// check val wrt curr root  in  search // similar to BS 

if (val <(curr->data)) curr = curr->left ; // move to left subtree
else  curr = curr->right ;
}
return curr ;
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

struct Node* ans = find_BST (root , 5 ) ;

cout << ans->data << endl ;

    return 0 ;
}