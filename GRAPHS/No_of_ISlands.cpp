#include <bits/stdc++.h>
using namespace std ;

/*

GRAPHS 
- Non linear DS where data is stored at vertices (nodes) and all these nodes are connected by edges . 
No of Islands in a Graph - Given a simple 2D matrix of 0 and 1 , find how many islands in the matrx ( 
    ISLAND - a group of (1) surrounded by (0)'s on ALL the sides possible . 
)
*/


// ASSUMPTION - Labelling of Nodes Using 1-based Indexing 

// Customised BFS traversal to touch all the nodes (containing 1 ) -> islands searching

 void bfs(int row , int col , vector<vector<int>> &vis , vector<vector<char>>grid){
       vis[row][col] =1 ;
       queue< pair<int , int> > q ;
       q.push({row , col } ) ; 
      int N = grid.size() ; int  M = grid[0].size() ;
       while(!q.empty()){
           // Curr Node of Graph 
           int curr_row =  q.front() .first ; // curr row of matrix 
           int curr_col =  q.front() .second; // curr col of matrix 
           q.pop() ;


           // travers all the Firest NB of curr node 
           for(int delta_row  =-1 ; delta_row <= 1 ; delta_row++ ){
               for(int delta_col =-1 ; delta_col <=1 ; delta_col++){

                   int new_row  = curr_row + delta_row ;
                   int new_col = curr_col + delta_col ;

                   if( (new_row<N)
                   && (new_row >=0) && (new_col<M) && (new_col>=0 ) &&
                   (!vis[new_row][new_col]) && grid[new_row][new_col]=='1' ){
                       vis[new_row][new_col] =1 ; // first nearest NB of parent node is visited 
                        q.push({new_row , new_col }) ;
                   }
               }
           }
       }
    }
    
    
 
// Function to find the number of islands.
 
    int numIslands(vector<vector<char>>& grid) {
         int rows = grid.size() ;
        int cols = grid[0].size() ;
       vector<vector<int>> vis (rows , vector<int> (cols , 0 )); // 2D matrix input (1 and 0 )
        int cnt =0 ;
        for(int row = 0 ; row < rows ; row ++){
            for (int col =0 ; col < cols ; col++){
            // DOing a BFS traversal and whenever I visit  a New UNVISITED component of amtrix (graph) , I add +1 to my answer .
            //Since BFS travels all the Nodes containing 1 .
                if( !vis[row][col] && grid[row][col]=='1'){
                    bfs(row , col , vis , grid ) ;
                    cnt++ ; 

                }
            }
        }

        return cnt ; 
    }


int main(){

int n , m ;
cin >> n >> m ;

// Nodes - n , edges - m 

// adjancey list 
vector<int>  adj_list[n+1] ;


for(int i=0 ; i < m ; i++ ){
    int node1 , node2 ;
    cin >> node1 >> node2 ;

// Undirected Graph

 
adj_list[node1 ].push_back(node2) ;
adj_list[node2].push_back(node1) ;


}



    return 0 ;
}