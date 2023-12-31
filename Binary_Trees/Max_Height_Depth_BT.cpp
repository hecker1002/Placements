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

Max. Height of BT - max. number of levels in BT (root to some leaf node)

Recursive = 1 + max(height_left_subtree , height_right_subtree) at any node

Hypothesis - works for any node gives max depth wrt that node  , Induction - max(left , right) + 1 , 
BC - if root = NULL , max height = 0

*/

int max_depth(struct node* root){

// BC 
if(root==NULL){
 return 0 ;
}

int left_subtree_height = max_depth(root->left) ;
int right_subtree_height = max_depth(root->right) ;

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

cout << max_depth(root) ; // solution : max depth of BT = 3



return 0;
}
