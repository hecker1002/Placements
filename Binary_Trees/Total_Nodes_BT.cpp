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

Total Nodes in a complete BT = (every level in the BT is cCOMPLETELY filled except the last level and all the leaf nodes are 
as left as possible .) in < O(n) T.C. 

travel from root to child and if that child (alongwith all nodes below it , form a complete balanced BT ) , then , use formula 
just use traversal  .

TC =O ( (log N ) ^ 2 ) since we use formula if lh=rh 
 */


int find_Lheight (struct Node* node ) {

int temp =0 ;
while (node){
    temp ++; 
    node = node -> left ;
}

return temp ;
}

int find_Rheight (struct Node* node ) {

int temp =0 ;
while (node){
    temp ++; 
    node = node -> right ;
}
return temp ;
}

int count_Nodes (struct Node* root ) {

if(root==NULL){
    return 0 ;
}
int lh = find_Lheight(root) ;
int rh = find_Rheight(root) ; // lefta nd right subtree height (including the rorr node )

if(lh == rh ){
    return (1 << lh) -1 ; // Height = pow ( 2 , lh) -1 
}

else {
    return 1 + count_Nodes(root->left) + count_Nodes(root->right ) ;
}



}


int main(){

// new node(1) = initlaizes a node in memory ar random position but BT structre automatically gives its a storage a heirrachivhal fashion .
struct Node * root = new Node(1) ;

root->left = new Node(2) ;
root->right = new Node(3) ;

root->left->right = new Node(4) ;

root->right->left = new Node(5) ;
root->right->right = new Node(6);


/*
Our Tree above 

     1
   /   \
 2      3
 \     / \
  4   5   6
*/

cout << count_Nodes (root ) << endl ;

    return 0 ;
}