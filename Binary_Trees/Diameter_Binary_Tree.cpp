#include <bits/stdc++.h>
using namespace std ;


// node - data sapce in memory - 1 unit of BT 
struct node {

int data ; 
struct node* left , *right ;

// constructor - when  [new node()] is initialized .
 
node (int val ){
    data = val ;
   left = NULL ; right = NULL ; // simply access it inside declaration of class as left , right 
}


};


/*

Diameter of BT - max distance (no. of edges) between any two nodes of a BT .

Assume every node as a curving point wrt every  node (find max(lh + rh) ) .

initialize diam with 0 .
*/

// Pass diam by reference as we want to change it (NOT return it directly in recursive cllas )
int max_depth(struct node* root , int &diam ){

// BC 
if(root==NULL){
 return 0 ;
}

int left_subtree_height = max_depth(root->left , diam ) ;
int right_subtree_height = max_depth(root->right , diam ) ;

diam = max(diam , left_subtree_height + right_subtree_height) ;
// induction + hypo
return 1 + max(left_subtree_height , right_subtree_height) ;

}

// Iterative Inorder traversal 

int main() {

// new node(1) = initlaizes a node in memory ar random position but BT structre automatically gives its a storage a heirrachivhal fashion .
struct node * root = new node(1) ;

root->left = new node(2) ;
root->right = new node(3) ;

root->left->right = new node(4) ;

root->right->left = new node(5) ;
root->right->right = new node(6);


/*
Our Tree above 

     1
   /   \
 2      3
 \     / \
  4   5   6
*/

int diam = 0 ;
int ans = max_depth(root , diam ) ;

cout <<  diam ; // solution : max depth of BT = 3



return 0;
}
