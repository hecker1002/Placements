#include <bits/stdc++.h>
using namespace std ;

/*
DFS - Depth First Search traversal technique in BT 

Pre- Order Traversal - (Root _>  left subtree -> right subtree )
apply this principal at every Node 

*/

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

// important -  pointers actuall are boxed containing address and inside them is actual daat whose adress it stores 
// and any data type = custom data type , so its contrusctor actaully stores address of such custom data obj=> data* x =  new data(2s) 


// Pre-Order Traversal of BT ( root , left , right ) -> Recursive (IBH) , Base cond. - leaf node , hyp - for every node works 
// Ind - print current node and then travel comlete left sub and then com right subtre 


// pass a custom data type in function using data type of custom data and its name .
void preorder(struct node* Node){

//BC 
if(Node==NULL){
    return ; // do NOTHING 
}


// induction
cout << Node->data << " "; 
preorder(Node->left) ;
preorder(Node->right) ;

}


// Inorder traversal - DFS -  left ->root ->right 

void inorder (struct node* Node){
//BC
if(Node == NULL){
    return ; 
}
//Induction 
inorder(Node->left) ;
cout << Node->data << " " ;
inorder(Node->right) ;

}

// Post Order Traversal ( DFS) - left ->right -> root 
void postorder(struct node* Node){

    //BC
    if(Node==NULL){
     return ;
    }

    // induction + hypo.
    postorder(Node->left) ;
    postorder(Node->right) ;
    cout << Node->data << " " ;
}


int main(){

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

preorder(root) ; // Solution - 1 (2 4) (3 5 6) 
cout << endl ;
inorder(root) ; // solution - ( 2 4 ) 1 (5 3 6)
cout << endl ;
postorder(root) ; // solution - (4 2) (5 6 3) 1

    return 0 ;
}