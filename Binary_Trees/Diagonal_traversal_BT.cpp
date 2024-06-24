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



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
Pick a Node and travel till its extreme right and each time check if its left child exists
and if YES , push its left child in queue . 
Now , if right child == nULL , jump back to parent node's left to start new diagonal (right)
traversal . This we do by picking first ele of queuue and popping it . 

and left of prev traversal is autamtiaclly included and since no right , it occurs singly in 
new traversal . 
*/

vector<int> Diagonal_Travel(Node* root ) {
    
    vector<int> ans ;
    
    if( root == NULL ){
        return ans ;
    }
    
    queue < Node* > q ; 
    
    q.push( root ) ;
    
    
    
    while ( !q.empty()) {
        
        Node* curr = q.front() ;
        q.pop() ;
        
        while( curr!= NULL){
            //check if left child exists 
            if ( curr->left) { q.push(curr->left);  }
            
            // else push back curr ele (right traversal )
            ans.push_back( curr->data) ;
            curr = curr->right ; 
        }
        
    }
    
    
    return ans ;
   
}


int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .
root->left->left = new Node(5) ; 








vector<int> ans_1 = Diagonal_Travel(root)  ;


for(int j=0 ; j<ans_1.size() ; j++) cout << ans_1[j] << " " ;


    return 0 ;
}