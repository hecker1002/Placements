
#include <bits/stdc++.h>
using namespace std ;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
      
   // Quesn is saying  - We have to make the same graph , with same values 
   // and same connections BUT at a DIFFERENT SPACE IN MEMORY
   // its possible ONLY when we traverse the graph 
   // make a copy of each node and then connect that node to its Parent 

// here , adj list stores address , Not Node values 

// connected graph 
// modified visted graph , using address of ndoe to see if its visited or NOT
// if NULL , new Node not made , hence Unvisited 

// IMP - here adj lsit stores addreses of NB , not values 

// ALways pass the vector By Reference  

  void dfs ( Node* real , Node* copy , vector<Node*> &vis ){
  // real = some Node of given graph 
  // copy - New node of memory with same value 
  vis[ copy->val ] = copy ;

// dfs by itr in adj list of relal node( since fake node doesnt have adj list now)
for ( auto it : real->neighbors){

    // it - child , copy - parent 
    if( vis[it->val ] == NULL ){
        // not visited means no copy of node formed till now in memory 
        Node* copy_1 = new Node( it->val ) ;
        
        // now need to visite it here since next dfs will be called on it ONLY 
        // an dit will then be automatically vsited 


        // these are visited now so becomes neighbors of parent (Copy) ele 
        (copy->neighbors).push_back(copy_1 ) ;
        dfs( it  , copy_1 , vis ) ;
    }

    else {
        // if visited , jsut need to make conenction with aprent 
        // uundirected graph ( u->v and also u<-v )

        // these are visited now so becomes neighbors of parent (Copy) ele 
        (copy->neighbors).push_back(vis[it->val] ) ;
    }
}
  
  }


    Node* cloneGraph(Node* head ) {


   // IMPORTANT - in GRAPH data structure , to make connection b.w nodes(u,v)
   // WE can ONLY use adjacency List 
   // adj[u].push_back(v)(n oreferencing possible )
  
if( head== NULL) return NULL ;


// Do dfs , make copy of each node and connect it to aprent

// to make same valued node at diff space in meory ,use new Keyword 

Node* copy = new  Node( head->val);

// Modify the visited array here , storing if ndoe is vsited or NOT
// by seeing f its NULL ( new Node not amed till now in memory , Unvisited)
// else visited 

// size not know and constriant less , go to max constraint )
vector< Node*> vis(102 , NULL ) ;
dfs( head , copy , vis ) ;

return copy ; // copy of head node 
    }