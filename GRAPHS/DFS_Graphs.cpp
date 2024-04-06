#include <bits/stdc++.h>
using namespace std ;

/*

GRAPHS 
- Non linear DS where data is stored at vertices (nodes) and all these nodes are connected by edges . 

DFS (Depth First Search) in Graphs 
= Pick a Node ( TRavel its complete depth and then when you can NOT travel any further , return to previous NB node (up side) and 
when you come at already 
visited nosde, travel its other depth ( a Node can have many depth in different directions ))

*/


// ASSUMPTION - Labelling of Nodes Using 1-based Indexing 


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

vector<int> order = dfs_Of_Graph(n , adj_list  ) ;

for(int j= 0 ; j < order.size() ; j++) cout << order[j] << " " ;

    return 0 ;
}