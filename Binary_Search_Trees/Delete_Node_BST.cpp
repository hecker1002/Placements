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
Delete a Node in a BST - 
delete the given Node in BST , and then attach its parent to the deleted node's left and the right subtree of del node to 
the leftmost child of left subtree . 

*/

Node* search_BST( struct Node* root , int val ){

struct Node* curr = NULL ;

while (root) {
if(root->data == val ){
    curr = root ;
    break ;
}
    if(root->data < val ){
        if(root->right)root = root->right ;
    }
   else if(root->data > val ) {
       if(root->left) root = root->left ;
    }
}

return curr ;
}

struct Node* last_right (struct Node* root ){
    if(root->right == NULL ){
        return root;
    }
    return last_right(root->right ) ;

}



// rearranges the connection after the given Node's deletion 
struct Node* helper(Node* root ){

// BC - edge (easy) cases 
if(root->left == NULL){
    return root->right ; 
}
if(root->right == NULL){
    return root->left ;
}

// deleted node's right child 

Node* right_child = root->right ;
struct Node * end_right = last_right(root->left ) ;

end_right->right = right_child ;

return root->left ;
}


struct Node* delete_BST (struct Node* root , int val ){
    struct Node* del = search_BST( root , val ) ;
    // search for the nodd to be dleted and return ROOT 
    if(root == NULL ){
       return NULL ;
    }

    if(root->data == val ){
        return helper(root ) ;
    }

    struct Node* dummy = root ;

    while (root){
        if(root->data > val ){ // go to left subtree of curr rott in BST 
         if(root->left && root->left->data == val ){ root->left  = helper(root->left) ; break;} // rearrange the coonection from deleted node's parent 
         else root = root->left ;
        }

        else {
            // go to right subtree of curr root in BST
             if(root->right && root->right->data == val ){ root->right = helper(root->right) ; break;} // rearrange the coonection from deleted node's parent 
         else root = root->right ;
        }
    }

    return dummy ; 
 
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

struct Node* del = search_BST (root , 7 ) ;

struct Node* new_rt = delete_BST(root  , 6) ;
preo( new_rt)  ;
    return 0 ;
}