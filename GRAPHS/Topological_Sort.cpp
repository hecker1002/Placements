#include <iostream> 
#include <stack>
#include <vector> 

const int M  = 1e9 + 7 ;

using namespace std ;


/*

Topological Sort - it is defined ONLY for DAG ( Directed Acyclic Graph ) 
Its a linear ordering of DAG nodes where if an edge is from u to v , u always appear before v in that linear ordering 
( shows traversal in graph )

do the dfs of each unvisited node and when you can not travel any further on that depth (ath)
 while returning , psush the parent node in stack 
 */

void dfs_top(int start , vector<int> adj[] , vector<int> &vis , stack<int> &st  ){

vis[start] = 1 ;

for(auto it : adj[start]){
    if(!vis[it]){
        dfs_top(it , adj , vis , st ) ;
    }
    // since directef graph , so o matter for children with same parent , any ordering is acceptable ONLY for these children 

}
st.push(start) ;

}



vector<int> topoSort(int V , vector<int> adj[]){

vector<int> vis(V , 0 );
stack<int> st ;

for(int j =0 ; j < V ; j++){
    if(!vis[j]){
        dfs_top(j , adj , vis   , st ) ;
    }
}

// stori ng topo sort ele in a stack ds . 
vector<int> top_sort ;
while(!st.empty()){
    top_sort.push_back(st.top()) ;
    st.pop() ;
}

return top_sort ;
}


int main() {
  
  int V , E ;

  cin >> V >> E ;
vector<int> adj[V] ;


  for(int j =0 ; j < E ; j++ ){
   int u , v ;
   cin >> u >> v ;

   adj[u].push_back(v) ;

  }
  vector<int> ans  = topoSort(V , adj) ;

  for(int j =0 ; j < ans.size() ; j++ ){
    cout << ans[j] << " " ;
  }

    return 0 ;

}