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

Boundary Traversal in BT - we travel through  the boundary of BT ( the most Outermost nodes of BT) in Anti-CW dir 
- Left Boundary (leftmost child  nodes of current nodes) excluding leaf nodes 
-Leaf Nodes (pre-order of whole BT )
-Right Boundary (right outermost nodes ) excluding leaf nodes

*/

bool isLeaf(struct Node* curr) {
    return  ((curr->left==NULL) && (curr->right==NULL ) ) ;
}

void addLeftBoundary(struct Node* root , vector<int> &res ){

struct Node* curr = root->left ;
while(curr!=NULL){
    if  ( !isLeaf(curr)) res.push_back(curr->data) ;
    if(curr->left!=NULL) {curr = curr->left ; }
    else curr = curr->right  ;

}


}

void addLeaves(struct Node* root , vector<int> &res){

if (isLeaf(root)){
    res.push_back(root->data) ;
}

if(root->left!=NULL)addLeaves(root->left , res ) ;

if(root->right!=NULL)addLeaves(root->right , res ) ;

}


void addRightBoundary(struct Node* root , vector<int> &res){

struct Node* curr = root->right ;
vector<int> ans1 ;
while(curr!=NULL){
     if  ( !isLeaf(curr)) ans1.push_back(curr->data) ;
    if(curr->right!=NULL) {curr = curr->right ; }
    else  curr = curr->left  ;

}
// reverse the righmost boundary 
// reverse(ans1.begin() , ans1.end()) ;

for(int j=ans1.size()-1 ; j>=0 ; j--){
res.push_back(ans1[j]) ;
}

}


vector<int> Boundary_traversal(struct Node* root) {
    vector<int> ans ;
    ans.push_back(root->data) ;

    addLeftBoundary(root , ans ) ;
    addLeaves(root ,ans ) ;
    addRightBoundary(root , ans ) ;
    return ans ;
}

int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->right->left = new Node(5) ;
  root->right->right = new Node(6) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .
 
 vector<int> res  = Boundary_traversal(root );

for (int j=0 ; j < res.size() ; j++) {
    cout << res[j] << endl ;
}
    return 0 ;
}