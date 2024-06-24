#include <bits/stdc++.h> 
using namespace std ; 


/*
 Disjoint Set DS - for ever changing graphs , at any instance , using disjoint set , 
 we can tell if 2 nodes u and v lie in same component or Not  . 

 We do this by Union by Rank(of 2 nodes) succesiively , find up of u and v , 
 find rank(~ height , beneath nodes ) and conenct smaller rank to bigger rank 
 and then , compress the path when UP is asked .( using recursion )

*/

// Use a Disjoit set as a new DS ( custom Data type that solves graph problems )
// s make it as a class 
// Union by Size - Connect 2 edges u and v , by comparing their up and attaching the smaller size component to bigger componetn 

// TC - O ( 1) almost O( 4 alpha) 

class Disjoint_set {
vector<int> size , parent ; 

public : 
// V = totla vertices 
Disjoint_set( int V ) {
    // initialize a parent(nodes above) and size( size of component  in which the node belongs to)
    // each node is a parent of itself 

    parent.resize(V+1 , 0 ) ;
    
    size.resize( V+1 , 0 ); // all nodes are parent of itslef initially 

    // every ndoe should be its own parent ,INTITIALLY
    for( int j =1 ; j <= V  ; j++ ){
        // aprent array 
        parent[j] = j ;
        size[j] = 1 ; // initlaly all nodes are alone ( size of each comp . initially is 1 )
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

 // Union by size -  pik 2 nodes to conenct , find their UP 
 // and conenct smaller size componet to bgeer component 

 void UnionBySize( int u , int v ) {

    // find Up of u and v 
    int pu = find_Ultimate_Par(u ) ; 
    int pv = find_Ultimate_Par(v ) ;

    if ( pu == pv ) { return ; // already lie in same compoent 
    }

    else if ( size[pu] < size[pv] ) { // connect smaller size to bigger size comp
     parent[pu] = pv ;
     // BUt here , since a new compoent is attached , the NEW resultant comp. gets bigger in size 
     // so in UnionBySize , there IS a change increase  in szie ( by new comp attached )
     size[pv]+=size[pu] ;
    }
    else if ( size[pv] < size[pu] ){
        parent[pv] = pu ;
        size[pu]+= size[pv] ;
    }
    else if( size[pu] ==  size[pv]){
        // do either of above conenction and increase size 
        parent[pv] = pu ;
        size[pu]+= size[pv] ;
    }
 }


} ; 

int main() {
  // but while joint , just  passs singly the nodes 
  // union by size automaticlaly soes the conection and  starts making the graphb 
    Disjoint_set ds1(5) ;
    ds1.UnionBySize(1 ,2 ) ;

   ds1.UnionBySize(2 ,3 ) ;

   if ( ds1.find_Ultimate_Par(3 )==ds1.find_Ultimate_Par(4)) {
       cout << "Same" ;
  } 
  else { cout << "Not Same "  << endl ;  }

   ds1.UnionBySize( 3 ,4 ) ;

   if ( ds1.find_Ultimate_Par(3 )==ds1.find_Ultimate_Par(4)) {
       cout << "Same" ;
  } 
  else { cout << "Not Same "  << endl ;  }
    return 0 ;
}