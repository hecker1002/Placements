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

Print all the nodes at a distance of K (K edges) from given target node 

Move radially outward from each of the node and not visiit the visited node and keep on increaing the diatnce ++ .
*/

// to store child nodes and its parent (as a map  )

void mark_Parent(struct Node* root , unordered_map <struct Node* , struct Node* > &mp ) {
 // do a BFS 

 queue<struct Node* > q ;
q.push(root ) ;

 while (!q.empty()){
    
    int sz = q.size() ;

    for (int j=0 ; j < sz ; j++){

        struct Node * curr = q.front() ;
        q.pop() ;

        if (curr->left ) q.push(curr->left )  , mp[curr->left] = curr  ;
        if(curr->right ) q.push(curr->right )  , mp[curr->right ] = curr ;

    }
 }

}

vector<int> distance_K (struct Node* root , struct Node* target , int k ){

    unordered_map<struct Node*  , struct Node* > parent ; /// map of parents  and child

    
    unordered_map < struct Node*  , bool > vis ; // map to store visited nodes  
   queue <struct Node* > q ; // queue to store curr nodes visited radially 

q.push(target ) ;

vis[target] = true ;
int dist = 0 ; // current distance from target node 

mark_Parent(root , parent ) ;


    
    // q.push(root) ;

    while(!q.empty()){

        int sz = q.size() ;
       
       if( dist++ == k ) {break ; }
       
    
        for(int j=0 ; j < sz ; j++){
            struct  Node* curr = q.front() ;
            q.pop() ;

            if(curr->left && !vis[curr->left]) q.push(curr->left )  , vis[curr->left] = true ;
            if(curr-> right && !vis[curr->right ] ) q.push(curr-> right ) , vis[curr->right] = true  ;
        // extra traversal (radially outward to the curr node's parent )

if( parent[curr] && !vis [ parent[curr] ]) q.push(parent[curr]) , vis[ parent[curr ] ] = true ; // eacnh node in BT has ONLY 1 parent 
        }
    }

    vector<int> ans ;
   // since when the queue's LOOP broke in the previous step , then 
   // the last ele stored in  were the parent and child nodes at distance = k from target .

    while(!q.empty()){
        ans.push_back(q.front()->data ) ;
        q.pop() ;


    }

    return ans ;
}


struct Node* preorder(struct Node* root , int target ) {

    if(root==NULL){
        return root ;
    }
    
    if( (root->data)  == target ) {
        return root ;
    }
    
    if(root->left)preorder(root->left , target ) ;
    if(root->right) preorder(root->right , target  ) ;

}

int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .

 struct Node*  find = preorder(root , 2 ) ;
  vector<int> ans = distance_K(root , find  , 1) ;
cout << find << endl ;


    return 0 ;
}