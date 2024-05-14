#include <bits/stdc++.h>
using namespace std  ; 

/*

Bellman Ford Algo -> used to find Shortest distance (using Edge Weights ) , from source node to every node of graph 
It works for Negative Weights Also (dont stuck like Djstra's in Negative Edge Weightd )

Works ONly for Directeg Graph ( so Change  UG to DG by making another reversed edge with same weight )

Logic -> Relax all the edges (given in any Order) N-1 times 
Relaxin the edge ->if edge from u to v with weight wt -> if( dist[u] + wt < dist[v]) dist[v] = dist[u] + wt ; 

# Why N-1 itr ? Since src initalized with =0  in dist[] array hence we require MAx N-1 itr to update min dist to reach every 
pther N-1 nodes (from src)

How to detect Negative PAth Cycle -> Sum of wt on Cycle < 0 
ByBellman Ford , I should have got my ans in (n-1) itr , if NOT , it mean it emmans 0ve cycle (sicne path weight)
is stil being reduced in Nth itr (which was actually not needed )

*/

vector<int> Bellman_Ford(int V, vector<vector<int>> &edges, int src) {
       
// make adjacency list )edges[0] ={ u , v , wt } 
vector<int> adj[V] ;
int E = edges.size()  ; // no of edges 

for(int j= 0 ; j < E; j++ ){
   adj[edges[j][0]].push_back( edges[j][1] ) ;

}
vector<int> dist(V , INT_MAX) ;

dist[src] =0 ; // initilaization of distance array 

for(int i =0 ; i < V-1 ; i++ ){

for(int j= 0 ; j < E; j++ ){
  int u = edges[j][0] ;
  int v = edges[j][1] ;
  int wt = edges[j][2] ;

  if(dist[u] + wt < dist[v]){ dist[v] = dist[u] + wt ; }

}


}

// Special Last Relaxation of all edges ( N iter) to check for negative cycle in Graph 
// if dist still reduces in this last itr . its negatove cycle and return array of -1 
for(int j=0 ; j< E ; j++){
int u = edges[j][0] ;
int v = edges[j][1] ;
int wt = edges[j][2] ;

if(dist[u]!=INT_MAX && dist[u] + wt < dist[v]) return {-1} ; // if dist[nodes] still reducing in N itr 
}

return dist ;

}


int main() {

int V , E ;
cin >> V >> E  ;

vector< vector<int> > edges  ; 

for(int j= 0 ; j < E ; j++){
    vector<int> test  ;
    int u , v , wt ; 
    cin >> u >> v >> wt  ;
    test.push_back(u) ;
     test.push_back(v) ;
      test.push_back(wt) ;
    edges.push_back(test) ;
}

vector<int> ans =  Bellman_Ford(V , edges , 0) ;

for(int j= 0; j < ans.size() ; j++ ){
    cout <<ans[j] << " ";
}cout << endl ;
    return 0 ;
}