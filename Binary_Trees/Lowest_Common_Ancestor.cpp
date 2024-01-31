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

LCA(node1 , node2 ) > is the ancestor node (at upper level)coomon to node1 and node2 .

Find (root to node path) for node1 and node 2 and fidn the last common and eqal ele in this path 

*/


/*

Printh the path - from Root Node to given Node in a Binry Tree 

*/


bool  path(struct Node* root , int target , vector<int> &ans  ){
   
   // Recursive 

   //BC 
   if(root==NULL){
    return false ;
   }

   // insert curr node and test 
   ans.push_back(root->data ) ;
    
// if node found
  if(root->data == target) return true ;


// if any of left / right sutre return node found 
  if( path(root->left , target , ans) || path(root->right , target , ans )) return true ;

// if returned false , remove last inserted node 
  else{ ans.pop_back() ; return false ; }

}


vector<int>  path_to_node(struct Node* root , int target ) {
    vector<int> ans ;
    path(root , target , ans  ) ;

    return ans ;
}
//

int LCA( int val1 , int val2  , struct Node* root ){
    vector<int> node1_path = path_to_node(  root, val1 ) ;
    vector<int> node2_path = path_to_node(  root, val2 ) ;

int ans = -1 ;
for (int j=0 ; j < min(node1_path.size() , node2_path.size() ) ; j++) {
    if( node1_path[j] == node2_path[j]) ans = node1_path[j] ;
    else break ;

}

return ans ;

}


// Logic2 : of LCA 

//  Stand at every node and look under it (call recursive function returning the address of node for which we need to find LCA
// and if choose NOn-NULL value returned at every node ) and if at aparticualr node , both left and right recursive
// call = return NOT-NULLL  , then it means - we found our LCA as our current standing node (not null = node found under curr node )


struct Node* lca( struct Node* root , struct Node* node1 , struct Node* node2){

    // BC 
if(root==NULL || root==node1  || root == node2 ){  // Ordder of conditions inside if() is also IMPORTANT 
 
 return root ;
}
    // Induction + hypothesis 

    struct Node* left_pos = lca(root->left , node1, node2 ) ;
    struct Node* right_pos = lca(root->right , node1 , node2 ) ;

// Choose not-null values from left and right part of curr node 
if(left_pos==NULL){ 
    return right_pos ;
}
else if(right_pos==NULL){
    return left_pos ;
}

// not null both , return curr node ( root )
else {
    return root ;
}
}
int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .
root->left->left = new Node(6) ;


struct Node* ans = lca(root ,root->left->left  , root->left->right ) ;

cout << ans->data << endl ; // print the value at the LCA addresses node 
    return 0 ;
}