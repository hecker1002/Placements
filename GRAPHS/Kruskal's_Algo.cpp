#include <bits/stdc++.h>
using namespace std  ;


/*
Kruskal's ALgo - to find MST from a given Graph ( of N nodes and N-1 edges )


*/

#include <vector>
class Disjoint {

// memebrs 
  vector <int> rank , parent , size_of  ; 
// Ultimate parent - Recursive call to find a node whose parent is node itself -> ( parent of all nodes in that component _
// rank - height of node 

// Path compression if Node 'u' uP is 'a' then connect directly  'u' to 'a'

public :

// constructor C++
// same name as class 

Disjoint ( int n ) {
    rank.resize( n+1 , 0 ) ;
    parent.resize( n+1 ,   0 ) ; // resize vector // 1 base indexing of nodes 
    size_of.resize( n+1 , 0) ;
    for(int i=0 ; i <=n ;i++  ){
        parent[i] = i ; // intially , all nodes are alone ( paarent  = node itself initially )
        size_of[i] =1 ;
    }


}

// finds utlimate parent of a node 
int find_Parent (int node )
{
    // BC - Ultiamte parent 
    if ( node == parent[node]) return node ;

// PATH COMPRESSION ocuuring here 
   return parent[node] = find_Parent ( parent [node]) ; // recursively search for  Ultiamte Parent and update all prev parent wit this UP 
}
// ading smalelr rank to bigger rnak node , No change in rank 
// but adding same rank Node s, rank changes by one for one of the nodes 

void Union_by_Rank ( int u , int v ) {

// ultimate parent of u 
int ulp_u = find_Parent( u ) ;
int ulp_v = find_Parent( v ) ;

if( ulp_u == ulp_v ){
    return ; 
}


// CONNECT SMALLER RANK TO LARGER 
else if ( rank[ulp_u] < rank[ulp_v]){
    // atach smaller rank UP to biggerr ank UP 
    parent[ ulp_u] = ulp_v ;
}
else if ( rank[ulp_v] < rank[ulp_u]){
    // atach smaller rank UP to biggerr ank UP 
    parent[ ulp_v] = ulp_u ;
}

else {
    // if same rank , atatch either of UP and increase rank  
    parent[ ulp_u] = ulp_v ;
    rank[ulp_v]++ ;
}
}

// Union by size - size of each componet , attacher smaller size componet to bigger size component 

void Union_by_Size(int u , int v ) {

// ultimate parent of u 
int ulp_u = find_Parent( u ) ;
int ulp_v = find_Parent( v ) ;

if( ulp_u == ulp_v ){
    return ; 
}

// CONNECT SMALLER RANK TO LARGER 
else if ( size_of[ulp_u] < size_of[ulp_v]){
    // atach smaller size comp  to biggerr ank UP 
    size_of[ ulp_u] += ulp_v ;
    parent[ulp_u] = ulp_v ;
}
else {
   
    parent[ ulp_v] = ulp_u ;
    size_of[ulp_u]++ ;
}
}
} ;


// Kruskals ALgo USING DSU 

//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        // Kruskal's Algo - use Disjoint set to sort the edges acc to weight 
        // and go on Union (adding) smaller component to larger component (if both node sin diff components)
        
        vector <  pair <int , pair < int , int > >  > edges ;
        
        for (int j =0 ; j < V ; j++ ){
            for ( auto it : adj[j]){
                int wt = it[1] ;
                int v = it[0] ;
                int node = j ;
                edges.push_back( { wt , { node  , v }}) ; // v is neighbor of v and vice versa 
                // no need to do this twice since Disjoint set 9 will treat it already as bidirectional edge 
                
            }
        }
        
    // sort acc.to the edge wts 
    sort ( edges.begin() , edges.end() ) ;
    int mst_wt  =0 ;
    
    // travel through all edges and respective node s( u and v )
    // and add v to u (Union bySize) samlelr to bigger comp. 
    // if u and v in diff comp else NO need ( since MST we need to find)-> Minimum

    Disjoint ds(V ) ;
    
for ( auto it : edges ){
    int wt  = it.first ; 
    int u = it.second.first ; 
    int v = it.second.second  ; 
    
    // USe disjoint Union
    
    // if uand v in diff comp , add these ( Hint - sue Ultiamte parent of u and v )
    // if ( diff UP means diff components for Mst ){
    //   Union (connect ) u and v 
    // }
    

    
     if (  ds.find_Parent(u) != ds.find_Parent(v)){
         mst_wt += wt ;
      ds.Union_by_Size(u , v) ;
    }
    
}     
 return mst_wt ;
    }
