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
Vertical Order Traversal - travel throgh each vertical line (drawn at every point from left to right) 
and travel from top to bottom along it . 
Give a co-ordinate to every point (x, y)in BT and all point with same x will lie on same verticla line and if nodes
overlap ,lesser value will be written first . 
DO this using BFS 

*/

vector<vector<int>>  Vertical_order_travel(struct Node* root ) {
    
    // store all the nodes-data  ( vertical line pso , lsit of all nodes data on that vertical lin )
    map < int , map < int , multiset<int> >  > nodes ; // at every x , corresponding to each level , 
    //keep the track of all these nodes data on diff levels .)


    //give coordinate to each node s

    queue < pair< struct Node* , pair< int  , int  >>> q ;

    // root = (node , 0 , 0)
    q.push( {root , {0 , 0 }}) ;


    while (!q.empty()) {

       
        auto var =  q.front() ;
        struct Node* curr = var.first; // curr node 
        q.pop() ;
   // corr of node 

   int x = var.second.first , y = var.second.second  ;


  nodes[x][y].insert(curr->data) ;

  if(curr->left){
   
   q.push( {curr->left , { x-1 , y+1 } }) ;
  }

   if(curr->right){
       q.push({curr->right , { x+1 , y+1 } } ) ;
  }



    }

    // Mapping all x and its levels data is completed 
    // Now store in 2D vector 

    vector<vector<int>> ans ;

    for(auto p : nodes ) {
        vector<int> col ; // col corresponding to curr x 
        for( auto q :p.second ) {

            col.insert( col.end() , q.second.begin() , q.second.end()) ;
        }
        ans.push_back(col) ;
    }

    return ans ;

}


int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .
 
 vector<vector<int > > v = Vertical_order_travel(root) ;


for (int r= 0 ; r < v.size() ; r++){
    for (int i=0 ; i<v[0].size() ; i++) cout << v[i][r] << " " ;
    cout << endl ;
}
    return 0 ;
}