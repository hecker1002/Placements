#include<bits/stdc++.h>
using namespace std ; 

// const int M = 1e9+ 7 ;

/*


Given a Directed graph , (V nodes and E edges) terminal; nodes = nodes with outdegree =0 
safe nodes  - nodes from where all possible paths lead to a terminal node 

Logic - reverse the grapg - do we travel terminal nodes first using Kanhs Tol]po sort algo . and 
after full traversal , the nodes we touchd will be safe nodes array 

*/


vector<int> eventualSafeNodes(int V , vector<int> adj[]){


// reverse the graph - by reversing the adjacency list 
// and store indegree of nodes (in reversed graph)
vector<int> adj_rev[V] ;
vector<int> indegree(V ,  0 ) ;
for( int j= 0 ; j < V  ; j++ ){

for(auto it : adj[j]){
adj_rev[it].push_back(j) ;
indegree[j]++ ;
}
}

queue<int> q ; 

for(int j =0 ; j < V ; j++ ){
    if(indegree[j]==0) q.push(j) ;
}

vector<int> topo ; 

while( !q.empty()) {
    int inedge_0_node = q.front() ;
    q.pop() ;
    
    topo.push_back(inedge_0_node) ;
    // reduce indegre of all its children by -1 

    for( auto it : adj_rev[inedge_0_node]){
        indegree[it]-- ;

        if(indegree[it] == 0 ){
            q.push(it) ;
        }
    }
}
sort(topo.begin() , topo.end() ) ;

return topo ;

}


int main ( ) {
int V , E ;

  cin >> V >> E ;
vector<int> adj[V] ;


  for(int j =0 ; j < E ; j++ ){
   int u , v ;
   cin >> u >> v ;

   adj[u].push_back(v) ;

  }
  vector<int> ans  = eventualSafeNodes(V , adj) ;

  for(int j =0 ; j < ans.size() ; j++ ){
    cout << ans[j] << " " ;
  }



    return 0 ;
}