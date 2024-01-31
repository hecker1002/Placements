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
Validate BST - At every node , check if it lies in a particular range (based on parent Nodes) or NOT 
*/

bool check_valid_BST ( struct Node* root  , int lower , int higher  ){

if(root==NULL ) return true ;
if(root->data >= lower && root->data <= higher ) return true ;

return check_valid_BST(root->left , lower , root->data) && check_valid_BST(root->right , root->data , higher ) ;
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

bool flag = check_valid_BST(root , INT_MIN , INT_MAX ) ;
cout <<  flag << endl  ; 

    return 0 ;
}