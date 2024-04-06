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

BFS in Graphs -  travel every level of Graph .

Pick any starting Node(level 0 -> should have ONLY 1 Node) and all nodes at SAME distance from starting node 
will be at SAME level .

Keep a visited array . 

Now push elemnts in queue and then its first nearest neighbors (from adjacency list) inside queue and visit every node trvaersed .

and traverse on ONLY unvisited Nodes . 
*/
// V = total Nodes (Verties)

// BFS in Graphs 
vector<int> BFS_graph( int V , vector<int> adj_list[]){
    int vis[V+1]= {0} ; // visited array

    // starting node = 1
    vis[1]=1 ;
    queue<int> q ;
    q.push(1) ;
    vector<int> bfs ;

    while(!q.empty()){
        int curr = q.front() ;
        q.pop() ;
        bfs.push_back(curr);
        // push first nearest nb from adjacency list 

        for(auto it : adj_list[curr]){
          if(!vis[it]){
            vis[it]=1 ;
            q.push(it) ;
          }
        }
    }
    return bfs ;

}

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
    adj_list[v].push_back(u) ; // undirected graph(bidirectional edges)

}

/*
The graph used here 
      1
    /  \
   2----3
  / \     \
 4--------5
    */
// SC = for undirected graph - Adj_list => O(2E)
//SC - for directed graph  - Adj_lis => O(E)

// cout << adj_list[3][1] << endl;

// To check NB of a node (u) in adjacency list -> adj_list[Node][NB_index]

// adj[U][V] = to check if an EDGE is b/w NODES U and V . 

 vector<int> ans = BFS_graph(n , adj_list) ;

for(int j=0 ; j< ans.size() ; j++)cout << ans[j] << " " ;


    return 0 ;
}