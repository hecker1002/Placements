#include <bits/stdc++.h>
using namespace std ;


/*

GRAPHS - Non-Linear ds where data is stored at different spaces in memory as Nodes(vertices) and connected by edges .

Represnation of Graph - as Adjacency Matrix -> showing which Nodes are connected by an edge 

SC = O(N2) 
TC = O(m)

N =  no of nodes
M = no of edges in Graph 

To STORE WEIGHTED GRAPH in ADjacency Matrix , PUSH edge weights (if edhe exists) INSTEAD of 1 at (i,j) and (j,i )-( For UNDIRECTED GARPHS)
*/



int main (){

int n , m ; // nodes and edges of a UNDIRECTED GRAPH (bidirectional edges ) // edge b./w u and v => edge between v an u also for travesal
cin >> n >> m ;

// adjacency matrix (showing which nodes are connected )
 
int adj[n+1][n+1]={ {0} } ; // max cases = all nodes connected , thats why , (n+1)(n+1) size 

for (int j= 0 ; j < m ; j++){
    int u , v ;
    cin >> u >> v ; // input the node1 and node2 

    adj[u][v] = 1 ;
    adj[v][u] =1 ;  // edge b/w  u and v => edge b/w v and u ALSO = ONLY in UNDIRECTED GRAPHS (travel in both /any directions on an edge)
    

// Edge present = 1
// edge NOT present =0 


}

// adj[U][V] = to check if an EDGE is b/w NODES U and V . 

    return 0 ;
}