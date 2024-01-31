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

Binary Search Tree - a SPECIAL BT where where at any node , its (left child < root) and (right child > root .)

To search for an element in a BST , check if val < root -> go to root->left and if  val > root , go to root->right .

Ceil of BST - given a key value , find smallest node from BST , where val >= key 
*/
// Write a simple loop 

int ceil_BST ( struct Node* root  , int key ){

int ceil =-1 ;
while (root){

    // if key == root's data 
    if( (root->data)== key ){
        ceil = root->data ;
        return ceil ;
    }

    if( (root->data) < key ){ //val < key 
        // surely inc it 
        root = root->right ;
    }

    else {
        // val >= key 
        ceil = root->data ; // also store lastest old value of nodes where val >= key .
        root = root->left ;
    }

    
}
return ceil ;

}

/*

Floor in BST - given a BST , find the largets most possible value in BST , wehre val <= key 

*/

int floor_BST ( struct Node* root  , int key ){

int floor  =-1 ;
while (root){

    // if key == root's data 
    if( (root->data)== key ){
        floor  = root->data ;
        return floor ;
    }

    if( (root->data) > key ){ //val < key 
        // surely inc it 
        root = root->left;
    }

    else {
        // val >= key 
        floor = root->data ; // also store lastest old value of nodes where val >= key .as odf now 
        root = root->right  ;
    }

    
}
return floor ;

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

int ans = floor_BST(root , 5 ) ;

cout << ans << endl ;

    return 0 ;
}