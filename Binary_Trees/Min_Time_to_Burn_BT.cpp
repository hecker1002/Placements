#include <bits/stdc++.h>
using namespace std ;

/*
DFS - Depth First Search traversal technique in BT 

Pre- Order Traversal - (Root _>  left subtree -> right subtree )
apply this principal at every Node 

*/

// node - data sapce in memory - 1 unit of BT 
struct Node {

int data ; 
struct Node* left , *right ;

// constructor - when  [new node()] is initialized .
 
Node (int val ){
    data = val ;
   left = NULL ; right = NULL ; // simply access it inside declaration of class as left , right 
}


};

/*
 Minimum time to burn a BT (fromm a given target node) - similar to nodes at a given distance k from target 
 just use flag=1 to check for succesfull burn hile moving radially outward from target and increase time++ if flag =true .

*/

// for mappinfg child to its corresponding parent 
struct Node* parent_map (struct Node* root , map < struct Node* , struct Node* > &parent  , int target ){

queue<Node*> q ;
q.push(root) ;

struct Node* ans  ;
while (!q.empty()) {
 struct Node* curr = q.front() ;
 q.pop() ;

if(curr->data ) ans = curr ;

 if(curr->left) parent[curr->left] = curr , q.push(curr->left ) ;
 if(curr->right) parent[curr->right] = curr , q.push(curr->right ) ; // pushing the nodes in queue 

}

return ans ;
}

int min_time (struct Node* root , int ans ) {
map < struct Node* , struct Node* > parent  ;
int time =0 ;

struct Node* target  = parent_map (root , parent , ans  ) ;

 map < Node* , bool > vis ;
queue <struct Node* > q ;
q.push(target ) ;
vis[target] = true ;


while (!q.empty()) {
    struct Node* curr = q.front() ; q.pop() ;
    vis[curr] = true ;
    bool f = 0 ;
    if(curr->left && !vis[curr->left])vis[curr->left]= true , f=1 , q.push(curr->left) ;
    if(curr->right && !vis[curr->right]) vis[curr->right]= true , f=1 , q.push(curr->right);
    if(parent[curr] && !vis[ parent[curr]]) vis[parent[curr]]= true , f=1 , q.push( parent[curr]);
   
   /*
   
   at every node , left , right and  1 parent is burnt 

        |
        2
      /  \

   */
   if(f==1){
    time++;
   }
   
}

return time ;
}

int main(){

// new node(1) = initlaizes a node in memory ar random position but BT structre automatically gives its a storage a heirrachivhal fashion .
struct Node * root = new Node(1) ;

root->left = new Node(2) ;
root->right = new Node(3) ;

root->left->right = new Node(4) ;

root->right->left = new Node(5) ;
root->right->right = new Node(6);


/*
Our Tree above 

     1
   /   \
 2      3
 \     / \
  4   5   6
*/

cout << min_time (root , 3 ) << endl ;

    return 0 ;
}