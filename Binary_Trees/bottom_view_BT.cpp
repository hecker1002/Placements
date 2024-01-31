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

Top -View of BT - how doesthe BT loook from top 

Traverse based on ( x , node ) and a newly arrived x-coordinate (line) store the first encountered node on that line in a map 
 */

vector<int> bottom_view(struct Node* root ) {

map<int , int > mp ;
queue < pair< struct Node*, int >> q ;

q.push({root , 0 } ) ;
 

while (!q.empty()) {
    
   auto cur= q.front();
   struct Node* curr = cur.first ;
   int v_line = cur.second ;

  q.pop() ;

  // if key ( line no. ) Not present in map , then only update its key in map else it means , the line has already been rreched before .
//  if (mp.find(v_line)==mp.end())mp[v_line] = curr->data;
 mp[v_line]= curr->data ;
    if(curr->left != NULL){q.push({curr->left , v_line-1}) ; }
    if(curr->right!= NULL){ q.push( {curr->right , v_line +1} ); }
  
}
vector<int> ans ;
for (auto i : mp) {
  ans.push_back(i.second) ;
}

return ans ;

}


int main(){
// initialize a root Node for bT and then hust go on connecting the child nodes using pointers .
  struct Node* root = new Node(1) ;

  root->left = new Node(2) ;
  root->right = new Node(3) ;
  root->left->right = new Node(4) ; // all subsequent nodes are initialized wrt root node .

vector<int> ans = bottom_view(root) ;

for(int j=0 ; j<ans.size() ; j++) cout << ans[j] << " " ;

    return 0 ;
}