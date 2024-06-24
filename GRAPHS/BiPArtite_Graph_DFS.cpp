#include <iostream> // iostream header file of C++ containg definitons of cout , endl , cin 
#include <queue> 
#include <vector>  

// int arr[N] = {-1 } -> Does NOT initialize all elemnt to -1 
// Instead , for arrays INITIALIZATION , use -> fill_n (arr , N , -1 ) ;
using namespace std ; 
// inside header files , the variables / functions geenrally used in C++ is definedscope namespace std 
// so to use multiple instances of such var/funct and tell the comp. where to go looking for the deinition of such var 
// we use std;  -> (INSIDE header file ) -> namespace std { ostream var }

/*

Bi-Partite Graph - A garph where each pair of the adjacent Nodes are colored by 2 different colors .
-> linear graphs-> ALWAYS Bi-PArtite  BUT  Graphs with Odd CYcle length are -> NEVER biPartitie 

// To find if a Graph is Bipartite or Not ? -> Start coloring Nodes one-by-one and if at any instant , adj nodes are of same color 
return False .

*/

// 0 base indexing 

// Using DFS to check for Bi-Partite Graph 

bool dfs_color ( int start ,int V , int color[] ,vector<int> adj[] , int curr){   // input -> no of Nodes , adjacency List 


//color the node ~ visiting a node ( since its first node of a component )

color[start] = (curr) ; // color it with opposite of current color given 

for( auto it : adj[start]) {
    // induction 
    if(color[it]== -1 ){
        if (dfs_color(it , V , color , adj , !curr) == false ) return false ;
    }
   // base condition ( smallest valid input )
    else if(color[it] == curr ){
        return false ;
    }
}
return true ;
}

bool isBipartite( int V , vector<int> adj[]) {
    
   int color[V]  ;
   fill_n(color , V , -1 ) ;

   // travel in each component of graph and color its adjacent nodes with diff color 

   for(int j =0 ; j < V ; j++ ){
    
    if(color[j] == -1 ){ // unvisited component of graph 
        if (dfs_color(j , V , color , adj , 0) == false ) { return false ;}
    }
   }

   return true ;
}



int main() {

 int V , E ;
 cin >> V >> E ;

 vector<int> adj[V]  ;

 for(int i =0 ; i < E ; i++){
 int u , v ;
 cin >> u >> v ;

 adj[u].push_back(v) ;
 adj[v].push_back(u) ; // Undirected graph


 }

if (isBipartite(V , adj )) {
    cout << "Bi partite" << endl ;
}

else 
{
    cout << "Not Bi-Partite" << endl ;
}


    return 0 ;
}