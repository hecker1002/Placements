#include <bits/stdc++.h> 
using namespace std ; 


/*
 Disjoint Set DS - for ever changing graphs , at any instance , using disjoint set , 
 we can tell if 2 nodes u and v lie in same component or Not  . 

 We do this by Union by Rank(of 2 nodes) succesiively , find up of u and v , 
 find rank(~ height , beneath nodes ) and conenct smaller rank to bigger rank 
 and then , compress the path when UP is asked .( using recursion )

 Union by Rank - Conencting 2 nodes by an edge ( by updating the aprent of smaller rank node ) to bigger rank node 

*/

// Use a Disjoit set as a new DS ( custom Data type that solves graph problems )
// s make it as a class 

// COnnections in a Disjoint Set are made on basis of Ultimate PArent ( not Immideate [parent])

class Disjoint_set {
vector<int> rank , parent ; 

public : 
// V = totla vertices 
Disjoint_set( int V ) {
    // initialize a parent(nodes above) and rank(level of nodes below ) array
    // each node is a parent of itself 

    // IMP - RANK IS NOT EXATLY SAME AS HEIGHT , SINCE , IT DOES NOT CHANGE DURING PATH COMPRESSION .
    rank.resize( V+1 , 0 ) ; // 1 base indexing dyanic graphs 
    parent.resize( V+1 , 0 ); // all nodes are parent of itslef initially 

    // every ndoe should be its own parent ,INTITIALLY
    for( int j =1 ; j <= V  ; j++ ){
     parent[j] = j ;
    }
}

// PAth Compression ( does NOT change rank) to find UP of a Node faster ( without changing rank)
// TC - O (1)

// Recursive ( DP ) solution 
int find_Ultimate_Par( int node ) {
    
    if(  node == parent[node] ){
        return node ; // ultimate boss
    }

    return parent[node]=find_Ultimate_Par( parent[node] ) ;

}

// doing Union By Rank , Union By RANK
// conects nodes u and v , (find ULtimate PArent(Not just Parent ) of u and v  their ranks , and conect smaller rank to bigger rank )

void UnionByRank ( int u , int v ) {
    // find up 
    int pu = find_Ultimate_Par(u) ; 
    int pv = find_Ultimate_Par(v) ;
   
   // if up are same , they lie in same component , NO need of conenction (Union )
   if ( pu == pv ) { return ;} 

   // else connect smaler rnak to bigger rank // by changing immideate PArents -  of Ultimate parents = UP itself 
   else if( rank[pu] < rank[pv]) { parent[pu] = pv ; }
   else if ( rank[pu] > rank[pv] ) { parent[pv] = pu ;}
   else if( rank[pv] == rank[pu]) { // do any coenction but increase rank to which the UP of anode si Conencted to .
   parent[pv] = pu ; rank[pu]++ ;
   }
}

} ; 

int main() {

   Disjoint_set ds( 5 ) ;
   // doing union of all these 5 nodes 
   ds.UnionByRank( 1 , 2) ;
   ds.UnionByRank( 2 , 3) ;
   ds.UnionByRank( 3 , 4 ) ;
  
  // at an instance of formation of dynamic graph , checking if 2 node slie in same componet ( in O(1) constant TC )
  if ( ds.find_Ultimate_Par(4 )==ds.find_Ultimate_Par(5)) {
       cout << "Same" ;
  } 
  else { cout << "Not Same "  << endl ;  }

  ds.UnionByRank(4 , 5) ;

  if ( ds.find_Ultimate_Par(4 )==ds.find_Ultimate_Par(5)) {
       cout << "Same" ;
  } 
  else { cout << "Not Same " << endl ; }

    return 0 ;
}