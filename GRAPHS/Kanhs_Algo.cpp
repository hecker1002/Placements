#include <iostream> 
#include <stack>
#include <vector>
#include <queue> 


const int M  = 1e9 + 7 ;

using namespace std ;


/*

Topological Sort - it is defined ONLY for DAG ( Directed Acyclic Graph ) 
Its a linear ordering of DAG nodes where if an edge is from u to v , u always appear before v in that linear ordering 
( shows traversal in graph )


Kanhs Algo - Topological Sort of a Graph -> using modified BFS using
Indegrree( incoming edges) of each node, keep on pushing nodes with indegree = 0 until completed 

Kanhs - Topo Sort + BFS ( using Indegre =0  as parent node )
 */


vector<int> topoSort_Kanhs(int V , vector<int> adj[]) {
// finding indegree for each node 
// u-->v , then indegree[v]++ 

vector<int> indegree(V , 0 ) ;
for(int j =0 ; j < V ; j++ ){
    for (auto it : adj[j])
    indegree[it]++ ;
}

vector<int> topo ;
queue<int> q ;

// travel in queue (whi;le queue is NOT empty ) 
// and pop from queue its front-most ele and push in my vector ans. 
// now, travel to all its adjacent directed edged nodes and assume their aprent node is removed 
// so for all these children , reduce their indegree bt -=1 and if any one's children indegre=0 
// push it to top of queue 

for(int j =0 ; j < V ; j++ ){
    if(indegree[j]==0) q.push(j) ;
}

while( !q.empty()) {
    int inedge_0_node = q.front() ;
    q.pop() ;
    
    topo.push_back(inedge_0_node) ;
    // reduce indegre of all its children by -1 

    for( auto it : adj[inedge_0_node]){
        indegree[it]-- ;

        if(indegree[it] == 0 ){
            q.push(it) ;
        }
    }
}

return topo ;
}

int main() {
  
  int V , E ;

  cin >> V >> E ;
vector<int> adj[V] ;


  for(int j =0 ; j < E ; j++ ){
   int u , v ;
   cin >> u >> v ;

   adj[u].push_back(v) ;

  }
  vector<int> ans  = topoSort_Kanhs(V , adj) ;

  for(int j =0 ; j < ans.size() ; j++ ){
    cout << ans[j] << " " ;
  }

    return 0 ;

}