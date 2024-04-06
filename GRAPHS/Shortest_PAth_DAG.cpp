#include <iostream> 
#include <utility>  // for pairs header file 
#include <vector> 
#include <queue> 
#include <stack>
#include<climits> // for INT_MAX 

using namespace std ; 

const int M = 1e9 + 7 ;

/*

GIven a Directed Acyclic Graph ( wth Edge WEIGHTS) find the Shortest path from any source to any possible vertex 
Logic - 
Do the Topo Srt 
and then pop ele ony by one from toppo sort and mark its distance from the source , 
Now travel int its adjacency lsit (storing pair of adj NB and its corresponding edge weight ) 
 and in dist[curr] =  update it by minimum possible of (curr edge weight + dist[parent] , curr value) 
 as we take ele from topo osrt stack  
 and when stack is empty , we get array storing weiht of sum of weights o  n all possible apth of given DAG 
*/

void dfs_topo(int node , vector<pair<int , int>> adj[] , vector<int> &vis , stack<int> &st ){ // pass the stack by reference 

vis[node] = 1 ;

for(auto it : adj[node]){
    if(!vis[it.first]){
        dfs_topo(it.first , adj , vis , st ) ;
    }
}

st.push(node) ;
}


vector<int> shortestPath ( int N,int M, vector<vector<int>>& edges ){

// do the toposort 



vector< pair<int , int> > adj[N] ;//NB and edge weight

for(int j= 0 ; j < M ; j++ ){
    int u =  edges[j][0] ; 
    int v =  edges[j][1] ;
    int wt =  edges[j][2] ; 

   adj[u ].push_back({ v , wt } ) ;
}

vector<int> vis(N , 0 ) ;
stack<int> topo ;

for(int  i =0 ; i < N ; i++ ){
    if(!vis[i]){
        dfs_topo( i , adj , vis ,  topo )  ;
    }
}


// make a distance array storing distance )9acc to weights from curr node  to src

vector<int> dist(N , INT_MAX ) ;
// keep on popping ele and finding min distance to reach from a=src to curr node
// by comparing its parent + w with old)distance speciified in dist array 

dist[0] =0 ;

while(!topo.empty()){

 int parent = topo.top() ;
 topo.pop() ;

// Here , assume parent  =0  (shortest dit from 0  to any other vertex ius being found 
// so  , dist[parent] =0 ;



for(auto it : adj[parent]){
    int child = it.first ;
    int weight  = it.second ;

    dist[child] = min (dist[child] , dist[parent] + weight ) ;
 }
}
// to account for cses where no Path even exists 
for(int j= 0; j < dist.size()  ; j++ ) {
    if (dist[j] == 1e9 ) dist[j] = -1 ;
}

return dist ;

}


int main() {

    int N  , M ;
    cin >> N  >> M ;

    // N= no of nodes total 
    // M = no of edges 
    vector< vector<int> > edges ;
    for(int j= 0 ; j < M ;j++ ){
        vector<int> temp ;
        for(int k =0 ; k < 3 ; k++ ){
            int a , b , c ; 
            cin >> a >> b >> c ;
            temp.push_back(a) ;
            temp.push_back(b) ;
            temp.push_back(c) ;
        }
    }
vector<int> ans = shortestPath(N , M , edges ) ;

for (int j= 0 ; j < ans.size() ; j++ ){
    cout << ans[j] <<" " ;
} cout << endl ;

    return 0 ;
}
