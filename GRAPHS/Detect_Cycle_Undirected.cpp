#include <bits/stdc++.h>
using namespace std ;


/*

Detect Cycle in an Undirected Graph 

Logic - Do a BFS traversal from a starting node . And if a Node is already visited whillee doing BFS , it means someone reached 
it earlier from a different dir at same distance. => Cycle exists in the Graph 

// Important - if Some Node is already visited and its NOT the parent of current Node 
Implies - a Cycle exists i n the Graph and somebody already visited it .

*/

bool detect_Cycle(int node , int V , vector<int> adj[] , int vis[]  ){

vis[node] = 1 ;
queue<pair<int , int> > q ;
q.push({node , -1 }) ;

bool ans = false ;
while(!q.empty()){
    int curr = q.front().first ;
    int parent = q.front().second ;

    for(auto i : adj[curr]){
        if(!vis[i])q.push({ i , curr} ) , vis[i]=1 ;
        else if(vis[i] && i!=parent){ans = true ; }
    }
    q.pop() ;
}

return ans ;
}

bool Cycle( int V , vector<int> adj[]){

int vis[V+1] ={0} ;
bool ans = false ;
for(int j =1 ; j < V+1 ; j++){
    // new compeonent of graph arrives , if its UNVISITED , call the bFS that travels whole of that conencted componet ans 
    // checks for a Cycle in the Graph .
if(!vis[j]) {
bool presence  = detect_Cycle( j , V , adj , vis ) ;
if(presence == true ){
    return ans = true ;
} 
}
}
 
return ans ;
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
  
    */
// SC = for undirected graph - Adj_list => O(2E)
//SC - for directed graph  - Adj_lis => O(E)

// cout << adj_list[3][1] << endl;

// To check NB of a node (u) in adjacency list -> adj_list[Node][NB_index]

// adj[U][V] = to check if an EDGE is b/w NODES U and V . 

bool ans = Cycle(n , adj_list) ;
cout <<ans << endl ;

    return 0 ;
}