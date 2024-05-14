#include <bits/stdc++.h>
using namespace std  ; 

/*
Prims Algo -> Finds the MST of the given graph (MST - tree derived a graph where N nodes and N-1 edges are present 
and every node is reachable from every other node . )

Make a pq and store ( wt , node , parent) and travel to all its children (unvisited .) push tehm in pq and 
then , process the least weighted edges . 

*/

// vector< vector<int> > &adj -> adjcency list 
//Prim's Algo 
int MST( int V ,  vector< vector<int> > &adj ) {

//Be sure , we will be given a Single Component Graph 

 priority_queue < pair < int , int > ,
      // stores the node and its adjacent edge wt (wrt parent )
       vector<pair < int, int >> , 
       greater <pair<int,int> > > pq ;
       // first node and wt 
       pq.push( { 0 , 0 }) ;
       int mst_wt =0 ;
       vector<int> vis(V , 0 ) ;
       
       // Greddily , go to every unvisited node , and choose among its adj edges , the one with least w t
       // and since we travel unvisited nodes only ,(in a connected component ) , therefore , 
       // we are connected to every otehr node 
       while(!pq.empty()){
           
           auto p = pq.top() ;
           pq.pop() ;
           
           int wt = p.first  ;
           int node = p.second ;
           
           // if node is visited
          
           if(vis[node]==1 ) continue  ;
           
           // if node is not visited , then we see around it and include its parent-curr edge  Wt 

           mst_wt += wt  ;
           
           //vis[node] curr node  =True 
           vis[node] =1 ;
           //Here , wea resure that the prev edge will be included in MST thats why I updated its visited array 

           for ( auto it : adj[node]){
               int child = it[0] ;
               int wt_child = it[1] ;
               // we are not updating the child node as visited /
               // since ,we are NOT sure which child will go inside MST 

               if(!vis[child]){
                   pq.push( { wt_child , child }) ;
               }
           }
           
       }
       
       return mst_wt ;
       
}


int main() {


    return 0 ;
}