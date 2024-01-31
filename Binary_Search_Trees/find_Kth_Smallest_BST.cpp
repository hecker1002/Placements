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
Find K th smallest element in BST - Use Specifically Inorder traversal , (left - root -right ) and in a BST , 
this inorder will give sorted elemnt . 

so to reduce SC. use a counter cnt ++ when arirve (vsiit a node) and when cnt==k , break;
*/

int find_K_smallest_BST(struct Node* root , int k , int &cnt  ){

if(root==NULL){
    return -1 ;
}

if(k==1){
    return root->data ;
}
find_K_smallest_BST(root->left ,k  , cnt ) ;
cnt++ ; 
if(cnt== k){
    return root->data ;
}
find_K_smallest_BST(root->right ,k  , cnt ) ;


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

int ans = 0;
find_K_smallest_BST(root , 4 , ans)  ;
cout << ans << endl  ; 

    return 0 ;
}