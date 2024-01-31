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

Insert a Node at Valid POS in BST - Take the node and at each root node, check validity if root> or < root and thne do insertion .
Insertion of a Node in BST always happen at Leaf Node . 
*/

Node* insert_BST(struct Node* root , int val ){

    if(root==NULL){
        return new Node(val) ;
    }

    struct Node* curr = root ;

    while (true ){
        // check wrt root node'svalue 
        if(curr->data <= val ){
            // check if rooot->right exists or NOT 
            if(curr->right)curr = curr->right ;
            // if NOT , do insertion and stop and return root of BST 
            else { curr->right = new Node(val ) ; break;}
        }

        // for other case 
       else {
        if(curr->left)curr = curr->left ;
        else { curr->left = new Node(val) ; break ;}
       }
    }
    return root ;
}

void preo( struct Node* root ){
    if(root==NULL){
        return ;
    }
cout << root->data <<" " ;
preo(root->left) ;
preo(root->right) ;
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

struct Node* ans = insert_BST (root , 8 ) ;

preo(ans) ;

    return 0 ;
}