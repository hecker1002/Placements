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

Balanced BT - at every node of BT abs( height of left subtree - height of right subtree) <= 1 ALWAYS 

Use MAx depth with recursive code = to return -1 if abs( height of left subtree - height of right subtree) > 1 . and break the code 

*/

int max_depth(struct node* root){

// BC 
if(root==NULL){
 return 0 ;
}

int left_subtree_height = max_depth(root->left) ;
int right_subtree_height = max_depth(root->right) ;


// Unvalanced BT code  , ANY of these 2 condition if fullfilled 
if(left_subtree_height == -1 || right_subtree_height==-1) return -1 ;
if( abs(left_subtree_height - right_subtree_height)>1) return -1 ;


// induction + hypo
return 1 + max(left_subtree_height , right_subtree_height) ;

}
bool check_balanced(node* root){
    
    if(max_depth(root) >=0) return true  ;
    else return false ;

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

cout << check_balanced(root) ; // solution : max depth of BT = 3



return 0;
}
