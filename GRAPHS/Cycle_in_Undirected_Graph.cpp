#include <iostream>
#include <queue>
#include <algorithm>
const long long int M = 1e9 + 7 ;


using namespace std ; 


/*
Detect Cycle in a DIRECTED Graph 

Maintain a visited array (vis) and a path_visited array (path) showing 
vis[i] - node is visited 
path[i] - node i is visited while traversing same path 



*/

bool dfs_directed(int curr , int V , vector<int> adj[] , vector<int> &vis , vector<int> &path ){

vis[curr] =1 ;
path[curr] =1 ;

for(auto it : adj[curr]){
    if(!vis[it]){
    if(dfs_directed(it , V , adj , vis , path )==true) return true  ;}

    else if(path[it]==true && vis[it]==true){
        return true ;
    }
}

path[curr] = 0 ;

return false ;

}
// assume , 0-based indxing in Nodes of Graph 

// here , adjacency list shows -> only first NB of each node following directed edges rule 

bool isCyclic (int V , vector<int> adj[]){

vector<int> vis(V , 0 ) ;
vector<int> path(V , 0 ) ;

// travel all components of graph 
for(int i =0  ; i < V ; i++ ){
 if(!vis[i]){
    // if anaywhere it return true , it means cycle exist in given comopnet of graph
    if(dfs_directed( i  ,V , adj , vis , path )==true) return true  ;
 }
}

return false ;
}

int main() {

    int V , E ;
    cin >> V  >> E ;
    
    vector<int> adj[V] ;
    for (int j =0 ; j < E ; j++ ){

        int u , v  ;
        cin >> u >> v ;

        adj[u].push_back(v) ;
        // since directed graph , edge only form u to v , NOT from v to u . 

    }

    if(isCyclic(V , adj )) cout << "Cyclic " << endl ;
    else cout << "Not Cyclic " << endl  ;

    return 0 ;
}