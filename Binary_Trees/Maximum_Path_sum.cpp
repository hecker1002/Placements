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


// Maximum Path Sum - considering every node as a turning point , 
//find max (val_curr_node + max(Path_sum_left_subtree) , max_path_sum_right_subtree )

/*
Recursive - - 

 Treat every node as a turning point 
 Case1 : if curr_node is ACTUALLY a turning point , then , [max_path_sum(left_subtree) + max_path_sum(right_subtree) + curr_node ] will be answer 
 Case2 : an some ancestor node is vertes , then to get atleast max_apth wrt curr node (if curr node is included in max_path of ancestor node) curr_node + max(left_max , right_max )
*/

int mx_path_sum(struct Node* node , int &maxi){
    //BC 
    if(node==NULL) return 0 ;
// Compare this left_max_sum and right_max_sum with 0 , since , we DO not want any negative max 
   int lp =  max(0 , mx_path_sum(node->left , maxi ) );
   int rp =  max(0 , mx_path_sum(node->right , maxi ) );

   // Case 1 
    maxi = max(maxi , lp + rp + (node->data) ) ;
    //Case2 :
    return (node->data) + max( lp , rp ) ;
}


int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .
int maxi =0 ;
mx_path_sum(root , maxi ) ;

cout << maxi ;

    return 0 ;
}

