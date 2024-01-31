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

Zig-Zag traversal BT - 

Do the same BFS (level order traversal ) and whenever you switch levels in a BT , update a Boolean flag keeping track of direction
at each level .

*/

vector<vector<int>>  zigzag_traversal(struct Node* root ){

    queue<struct Node*> q ; // FIFO 
    vector<vector<int>> v ;
    bool left_2_right = true ;

    q.push(root) ;

    while(!q.empty()){
        int sz = q.size() ;
       vector<int> level ;
        for(int i=0 ; i<sz ; i++){
            
            struct Node* curr = q.front();
            q.pop() ;

            if(curr->left != NULL) q.push(curr->left ) ;
            if(curr->right != NULL ) q.push(curr->right ) ;
            
            level.push_back(curr->data) ;
        }
        if(!left_2_right)reverse(level.begin() , level.end()) ;

        v.push_back(level) ;

        left_2_right = (!left_2_right );

    }
}


int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .

vector<vector<int>> ans  = zigzag_traversal(root) ;

cout << ans.size() ;
    return 0 ;
}