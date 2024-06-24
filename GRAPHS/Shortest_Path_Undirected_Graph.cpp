#include <iostream>
#include <vector>
#include <queue> 
#include <limits.h>
using namespace std ; 


/*

Given an Undirected Graph ( with all edge weights =1 ) , find the Shportest Path in it to travel from source node to every node 
Do a BFS traversal and for each new node ,
 UPDATE the dist(from src to new node) = min(dist(src to prev node) + 1 ,   among all possible choices)
*/

// 0 based indexed graph 

 vector<int> shortestPath(vector<vector<int>>& edges, int V,int M, int src){
        // make a distance array 
        vector<int> dist( V , INT_MAX ) ;
        // make adajcncy list 

        vector<int> adj[V] ;
        for(int j= 0 ; j < M ; j++){
            adj[ edges[j][0]].push_back( edges[j][1]) ;
            adj[ edges[j][1]].push_back( edges[j][0] ) ;
        }
        dist[src] = 0 ; // initilaization 

        //do BFS 
        queue< int > q ;
        q.push(src) ; // initialztion 

        while(!q.empty()) {
            int curr = q.front() ;
            int distance = dist[q.front()] ; // ditance from source to prev parent node and new dist for child  =parent dist +1 
            q.pop() ;

            for (auto it : adj[curr]){
                // Update distances in this way ONLy , otherwise if you dont check lie this , TLE will occur . 
               if ( distance + 1 < dist[it]){
                   dist[it] = distance + 1 ; // all edges have weight =1 
                   q.push(it) ;
               }
            }
        }
        // unreachable nodes store = -1 
        
        for (int j= 0 ; j < V ;j++ ){
            if(dist[j] == INT_MAX) dist[j] = -1 ;
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
vector<int> ans = shortestPath( edges  , N , M , 0  ) ;

for (int j= 0 ; j < ans.size() ; j++ ){
    cout << ans[j] <<" " ;
} cout << endl ;



    return  0 ;
}