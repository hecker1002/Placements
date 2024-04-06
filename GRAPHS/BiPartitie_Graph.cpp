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
-> linear graphs and Graphs with Odd CYcle length are -> always biPartitie 

// To find if a Graph is Bipartite or Not ? -> Start coloring Nodes one-by-one and if at any instant , adj nodes are of same color 
return False .

*/

// 0 base indexing 

bool check_bipartite_bfs ( int start ,int V , int color_nodes[] ,vector<int> adj[]){   // input -> no of Nodes , adjacency List 

// do a BFS call and color all visited nodes accordingly

queue<int>q ;

q.push(start ) ;
color_nodes[start ] = 0 ;

while(!q.empty()){
 int curr = q.front() ;
  q.pop() ;

  // if adjjacent node is uncolored , color it and push in queue (BFS )
 for (auto it : adj[curr]){
    if(color_nodes[it]== -1 ){
        color_nodes[it] = !(color_nodes[curr]);
        q.push(it) ;
        
    }
    // if someone already colored the adjacent Node  , check if it has same color has curr node
    else if(color_nodes[it] == color_nodes[curr] ){
        return false ;
    }
 }
}
return true ;

}

bool isBipartite( int V , vector<int> adj[]) {
    
    int color_nodes[V]  ; 
    fill_n(color_nodes , V , -1 ) ;  // -1 -> all uncolored 

    for (int j =0 ; j < V ; j++ ){
        if(color_nodes[j]==-1){
        if (check_bipartite_bfs(j ,V , color_nodes , adj ) == false ) return false  ; }
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