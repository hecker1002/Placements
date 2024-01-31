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


int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .

vector<int> ans = path_to_node(root , 3) ;

for(int j=0 ; j<ans.size() ; j++) cout << ans[j] << " " ;
    return 0 ;
}