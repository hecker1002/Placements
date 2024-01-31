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
Check if 2 Trees are identical or NOT . 
Check Pre-Orde , Post-Order , In-order traversal simultaneously in both trees . If its same , the trees are equal 

*/

bool sameTree(struct Node* root1 , struct Node* root2 ){
// compare values , NOT addresses

if(root1 == NULL || root2==NULL  ) {
 
 return (root1==root2) ;
}

// Use && (logical AND  - - for statements ) , not bitwise AND (ONLY for integers ).

// Use Pre-order traversal - root-left-right
return (root1->data == root2->data ) && sameTree(root1->left , root2->left ) && sameTree(root1->right , root2->right ) ;

}

int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .

  struct Node* root1 = new Node(1) ;

  root1->left = new Node(2) ;
  root1->right = new Node(4) ;
  root1->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .

cout << sameTree(root , root1) ;
    return 0 ;
}