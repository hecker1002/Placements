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

Chidren Sum Property - At every node of a BT , the curr node's value is equal sum of the  the left anfd right child value 

Logic - While going down in the BT , increase the node's value as much as possible so there is no shortage of valuyes .
*/


void children_sum(struct Node* root ){

    if(root==NULL){
        return ;
    }

    int child =0  ;


    if(root->left != NULL )child+= (root->left->data) ;
    if(root->right != NULL )child+=(root->right->data ) ;

 // if children sum is greater , replace curr nodes value with child sum
    if(child >= root->data) {
        root->data = child ;
        
    }

// if curr node is greater , replace each child with max , ie , curr nodes vale so we dont fall short of any value .
    else {
        if(root->left) root->left->data = root->data ;
        else if(root->right) root->right->data = root->data ;
    }

    

    children_sum(root->left) ;
    children_sum(root->right ) ;
// now , on case we get an incremented again children value then 
int new_sum = 0 ;

if(root->left) new_sum += root->left->data ;
if(root->right) new_sum+= root->right->data ;

// if leaf  node , do NOT updtae else update with new_sum
if (root->left or root->right)
root->data = new_sum ;

}

void preorder(struct Node* root) {

    if(root==NULL){
        return ;
    }
    cout << root->data << " " ;

    preorder(root->left) ;
    preorder(root->right ) ;

}

int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .


children_sum(root) ;

preorder(root ) ;
    return 0 ;
}