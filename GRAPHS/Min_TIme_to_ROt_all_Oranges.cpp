
#include <bits/stdc++.h>
using namespace std ;



/*

BFS ios a small complimentary function that visits aforesaid Neigbours of any node in a graph . and 
it is actually made to assit in bigger and more complex functions 

to rot all oranges (2) , do  a bfs search for each orange (1) and visit all oranges  by pushing 
in queue ( coord of orange , time ) 
*/

// Here vis[node] = 2  (rotten) and vis[node]=0 (not rotten)

// specialiozed bfs ttraversal from a rotten orange to 4 neighbours 
void bfs(int r , int c , vector<vector<int>> &grid , int time  , vector<vector<int>> &vis  ,queue < pair < pair < int , int > , int >> &q)
{

int n = grid.size() ; // rows 
int m = grid[0].size() ; // columns 

int v1[4]= {-1 , +1 , 0 , 0 } ;
int v2[4] = {0 , 0 , -1 , +1 } ;

for (int j =0  ; j < 4 ; j++ ){
   int  nr = r + v1[j] ;
   int nc = c + v2[j] ;
   
   if(nr< n && nr >=0 && nc<m && nc>=0 && vis[nr][nc]!=2 && grid[nr][nc]==1 ){
    
     
     q.push({{nr , nc} , time + 1 }) ;
      vis[nr][nc] = 2 ; 
   }
   
}
}

// here queue is of ONLY rotten oranegs alongwith time after which they are rotten .
// so  in bfs , when you are rotting the 4 neighbouring oranges , 

int rot_all_oranges ( vector<vector<int>> &grid  ) {

int n = grid.size() ; // rows 
int m = grid[0].size() ; // columns 

int time  =0 ;

queue < pair < pair < int , int > , int >  > q ;

vector<vector<int>> vis(n , vector<int> ( m , 0 )) ;
// do a BFS traversal 

for(int i =0 ; i < n ; i++  ){
    for (int j= 0  ; j < m ; j++ ){
        if(grid[i][j] == 2 )q.push({{i , j } , 0 })  , vis[i][j] =  2 ; // visiting only at t=0 , rotten oranges nodes 
        else vis[i][j] = 0 ;
    }
}

int tm = 0 ;

while(!q.empty()){
    int n1 = q.front().first.first ;
    int m1 = q.front().first.second ;
    int time  = q.front().second ;
    q.pop() ;
    tm = time ;
    bfs(n1, m1, grid , time , vis  , q) ;
}

for (int  i= 0 ; i < n ; i++){
    for(int j =0 ; j < m ; j++ ){
        if(vis[i][j] !=2 && grid[i][j] ==1 ) { return -1 ;}
    }
}

return tm ;

}






int main (){


int n , m ;
 cin >> n >> m ; 

vector< vector<int > > grid( n , vector<int> ( m , 0 )  ) ;

for(int j= 0 ; j < n ; j++ ){
    for (int i =0 ; i < m ; i++ ){
       int o ; cin >> o ; 
       grid[j][i] = o ;
    }
}
int tm = rot_all_oranges(grid ) ;

cout << tm << endl ;


    return 0 ;
}