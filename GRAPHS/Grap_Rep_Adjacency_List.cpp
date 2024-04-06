#include <bits/stdc++.h>
using namespace std ;


/*

GRAPHS - Non-Linear ds where data is stored at different spaces in memory as Nodes(vertices) and connected by edges .

Represnation of Graph - as Adjacency LIST - shows all the FIRST NEAREST NB of a NODE . 

SC = O(N2) 
TC = O(m)

N =  no of nodes
M = no of edges in Graph 

To STORE WEIGH+TED GRAPH in ADjacency List , (weight odf edges ) stoere pairs of (neighbors ,edge_weight) in a Node's adjacency List 
*/


/*

*/

int main (){

int n , m ; // nodes and edges of a UNDIRECTED GRAPH (bidirectional edges ) // edge b./w u and v => edge between v an u also for travesal
cin >> n >> m ;

// Make an adjacency List (array) storing FIrst nearest NB of a Node 

vector<int> adj_list[n+1] ; // Using [] in NAME of vecto means - we are making ARRAY (fixed size) of vectors .

for (int j=0 ; j < m ; j++){
    // for UNDIRECTED GRAPHS - u --- v AND => v---u 
   int u , v ;
   cin >> u >>  v ;

    adj_list[u].push_back(v) ;
    adj_list[v].push_back(u) ; 

}


// SC = for undirected graph - Adj_list => O(2E)
//SC - for directed graph  - Adj_lis => O(E)

// cout << adj_list[3][1] << endl;

// To check NB of a node (u) in adjacency list -> adj_list[Node][NB_index]

// adj[U][V] = to check if an EDGE is b/w NODES U and V . 

    return 0 ;
}