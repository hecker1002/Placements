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

LCA - the first point of intersection (from bottom of BST ) where root-to-node path intersect . 
Recursive - call the LCA function based on a, b wrt root node's value . 
*/

int LCA_BST(struct Node* root  , int val1 , int val2 ){

    if(root == NULL){
        return -1 ;
    }

     if(root->data< val1 && root->data < val2 ){
        // right subtree 
        return LCA_BST(root->right , val1 , val2 ) ;
     }
    
    if(root->data > val1 && root->data > val2 ){
        return LCA_BST(root->left , val1 , val2 ) ;
    }

    return root->data ; 

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


cout <<  LCA_BST(root , 1 , 3 ) << endl  ; 

    return 0 ;
}