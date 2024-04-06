#include <bits/stdc++.h>
using namespace std ;

/*

GRAPHS 
- Non linear DS where data is stored at vertices (nodes) and all these nodes are connected by edges . 

No of Provinces ( CONNECTED COMPONENTS) ion a GRAPH - 
CAll the dfs for every node in GRAPH and visit it and for 
every new unvisited node , cnt++ ( NEW COMPONENT ) 

*/


// ASSUMPTION - Labelling of Nodes Using 1-based Indexing 

//dfs ( FROM A PARTICULAR NODE ) -> automatically traverses all GRAPH (since recursive calls )
void dfs( int node ,int N ,  vector<int> adj[] , int vis[] , vector<int> &dfs_order){

// Recursive call for each Node and its UNVISITED nB unless BC is reached 
vis[node] =1 ;
dfs_order.push_back(node) ; // BC 

// induction and hypo

for( auto it : adj[node]){
    if(!vis[it]){
        vis[it] = 1 ;
        dfs(it ,  N , adj , vis , dfs_order) ;
    }
}
}


vector<int> dfs_Of_Graph(int N , vector<int> adj[]  ){

vector<int> dfs_order ;
int vis[N+1]= {0} ;

dfs(1 , N , adj , vis , dfs_order);

return dfs_order ;
}

// There can be many permutations for the DFS og Graph 

// no of connected componets (provinces) in a graph 

// Undirected Graph 

int no_of_provinces (int N , vector<int> adj[]){

int vis[N+1] = {0} ; // visited array - tracks all visited nodes duringa dfs 
int cnt=0 ;

vector<int> dfs_order ;
for(int i = 1 ; i <= N ; i++ ){
    if(!vis[i]){
        cnt++ ;
        dfs(i , N , adj , vis , dfs_order ) ;
        dfs_order.push_back(i) ;
    }
}
return cnt ;
}




// dfs() -> is actually traversing the graph from a node
// no of provinces is finding appropriate place to call a dfs . 

int main(){

int n , m ;
cin >> n >> m ;

// Nodes - n , edges - m 

// adjancey list 
vector<int>  adj_list[n+1] ;


for(int i=0 ; i < m ; i++ ){
    int node1 , node2 ;
    cin >> node1 >> node2 ;

// Undirected Graph

 
adj_list[node1 ].push_back(node2) ;
adj_list[node2].push_back(node1) ;


}

int prov = no_of_provinces(n , adj_list) ;

cout << prov << endl ;

    return 0 ;
}