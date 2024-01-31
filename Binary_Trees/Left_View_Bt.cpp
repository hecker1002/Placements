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
 Left View of a BT - how will the BT look from left side 
 (firsr node of each level )
 */

vector<int> right_view(struct Node * root ) {
    
    vector<int> ans ;

   // BFS 
   if(root==NULL) return ans ;

   queue<pair<struct Node* , int >> q ; // node and level 
    map <int , int > mp ; // level and node 

    q.push({root , 0}) ;

    while (!q.empty()) {
      
      auto val = q.front() ;

     struct Node* curr = val.first ;
     int level = val.second ;
      q.pop() ;
     mp[level] = curr->data ;

     if(curr->left != NULL) q.push({curr->left , level + 1}) ;
     if(curr->right != NULL) q.push({curr->right, level + 1}) ;


      
     
    }

    for( auto j : mp) {
        ans.push_back(j.second) ;
    }
    return ans ; 

}


vector<int> left_view(struct Node * root ) {
    
    vector<int> ans ;

   // BFS 
   if(root==NULL) return ans ;

   queue<pair<struct Node* , int >> q ; // node and level 
    map <int , int > mp ; // level and node 

    q.push({root , 0}) ;

    while (!q.empty()) {
      
      auto val = q.front() ;

     struct Node* curr = val.first ;
     int level = val.second ;
      q.pop() ;
     if(mp.find(level)==mp.end() ) mp[level] = curr->data ;

     if(curr->left != NULL) q.push({curr->left , level + 1}) ;
     if(curr->right != NULL) q.push({curr->right, level + 1}) ;


      
     
    }

    for( auto j : mp) {
        ans.push_back(j.second) ;
    }
    return ans ; 

}

// Recursive Soln  -  to get right view of BT -> only push nodes in DS when ( curr_level == ds.curr_size ).

void rec_right_view (struct Node* root , int level  , vector<int> &ans ) {
   
  
   //BC 
    if(root == NULL){
        return ;
    }

  // Hypo + induction 
  if( ans.size() == level ) ans.push_back(root -> data ) ;

  rec_right_view(root->right , level + 1 , ans ) ; // level = y-coordinate 
  rec_right_view(root->left , level + 1 , ans );

}

// Similar is the code for a right view , last node visited is of right view (at each level )

int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .
root->left->left = new Node(5) ; 


vector<int> ans = left_view(root) ;

for(int j=0 ; j<ans.size() ; j++) cout << ans[j] << " " ;

cout << endl ;

vector<int> ans_1  ;
rec_right_view ( root , 0 , ans_1 ) ;

for(int j=0 ; j<ans_1.size() ; j++) cout << ans_1[j] << " " ;


    return 0 ;
}