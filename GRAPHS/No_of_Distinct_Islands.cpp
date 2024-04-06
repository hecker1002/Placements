//#include<bits/stdc++.h> // a non-standard header file that includes all header files of C++ (increases compilation time)

// set works with ANY type of DS 

#include <iostream>
#include <vector>
#include <set>

using namespace std ; 

/*

No of Unique Islands in a graph ( 2D matrix where cells are -> nodes connected to every other node)

Do a BFS/DFS call for every node and store (curr node - base node) value as alist (where node==1 in NB) in a set
and find size of set 
No of unique island shapes (rotated islands are distinct ) only visually same looking islands are identical .

In DFS , we travel in ANY direction . 
In BFS , we travel ONLY breadth wise . 

*/

//Since we are not making adj list here , we have to travel among all 4 neighbours of curr node 
// AND do a recursive DFS call for each of these( Neighboring Nodes == 1 )  AGAIN .

void dfs_for_1(int  row , int col , int row_0 , int col_0 ,vector<vector<int>> &grid , vector<vector<int>> &vis , vector< pair<int , int >> &vec  ){

int n1 = grid.size() ;  // rows
int m1 = grid[0].size() ;  //cols 

// row_0 and col_0 -> coordinates of base node for an island (FIRST Node==1 of an unvisited component of a graph )
// row , col -> current row and col while traversal (DFS )

vis[row ][col] = 1 ;

vec.push_back( {row - row_0 , col - col_0 } );
// travel among 4 Nearest Neigbours 

for(int i1 =0 ; i1 < 4 ; i1++ ){
    
    int del_row[]= {-1 , +1 , 0 , 0  } ;
    int del_col[] = { 0 , 0  , -1 , +1 } ;


// new Neigbor coordinates to be checked 
    int new_row = row +  del_row[i1] ; 
    int new_col = col + del_col[i1] ;

if(new_row>=0 && new_row<n1 && new_col>=0 && new_col< m1 && !vis[new_row][new_col] && grid[new_row][new_col]==1){
// vsit the UNVISITED NODE 
// and Recursive DFS call to search for directly coonected 1s (forming Island )

dfs_for_1(new_row , new_col , row_0 , col_0 , grid , vis , vec ) ;
}
   
}

}


int countDistinctIslands(  vector<vector<int>> &grid ){

int n = grid.size() ;  // rows
int m = grid[0].size() ;  //cols 

vector<vector<int>> vis( n , vector<int> (m , 0 )) ;

set< vector < pair<int , int> > > st ;
// travel in the grid (graph) and whenver you encounter a node of a UNconnected (unvisited component) 
// increase cnt 

for(int i = 0 ; i < n ; i++ ){
    for(int j =0 ; j < m ; j++ ){
        vector< pair<int , int >> vec ;
     // vec is the shape of island (coordiantes) for the island (containg all 1s )
     if(grid[i][j] ==1  && !vis[i][j]){
        dfs_for_1( i , j , i , j , grid , vis ,  vec ) ;

        st.insert(vec) ;}
    }
}

return st.size() ;

}

int main() {
 // input 2D amtrix

 int n , m ;
 cin >> n >> m ;

vector<vector<int>> grid ( n , vector<int> (m , 0 ));


 for(int r= 0 ; r < n ; r++){
    for(int c =0 ; c < m ;c++){
        int a ;
        cin >> a ;
        grid[r][c] = a ;
    }
 }

 int ans  =  countDistinctIslands(  grid ) ;

cout <<ans << endl ;


    return 0 ;
}