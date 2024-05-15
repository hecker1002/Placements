#include <iostream> 
#include <vector > 
using namespace std  ; 

/*
Disjoint Set - is a custom data type Graph ( dynamic graph whose confg is always changing )

and we use it to find in Constant time O(1) if two nodes will lie in same compeont (at ay instant of config )

Whole ALGO works in O(1) - constant time 
*/


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
    rank[ulp_u]++ ;
}
}
} ;


int main() { 
 
Disjoint ds (4) ;

ds.Union_by_Rank(1 , 2) ;
ds.Union_by_Rank(1 , 3) ;
  // find if 2 nodes at an instant in same component ( in constant time )

//   if( ds.find_Parent(3) == ds.find_Parent(4)){
//     cout << "Same" << "\n" ;

//   }
//   else cout << "Not Same " << "\n" ;

  ds.Union_by_Rank(3 , 4) ;

   if( ds.find_Parent(3) == ds.find_Parent(4)){
    cout << "Same" << "\n" ;

  }
  else cout << "Not Same " << "\n" ;

    return 0 ;
}


