#include <bits/stdtr1c++.h>
using namespace std  ;

/*

Floyd Warshal Algo -> helps to find shortest path (path of least weights) from any node i to any other node j . 
We use adjacency matrix (to store weight of edge ) and find all paths through every other node / vertex and store it in adj amtrix
and the last matrix we get is -> shortest apth matrix (Brute Force) 

for(i=0 -> n ){
    for(j =- -> n ){
        cost [i][j] = min(cost[i][j] , cost[i][via] + cost[via][j])    }
}

where cost[i][j]  = min cost of reaching from nodei to node j currently 
*/

void shortest_distance(vector< vector<int> > & matrix ){

// store where there is no edge => INF 

// total nodes = n 
int n = matrix.size() ;

for(int i = 0 ; i < n ;i++){
    for( int j= 0 ; j < n ;j++ ){
      if(matrix[i][j] == -1) matrix[i][j] = INT_MAX ; // since in quesn , wherever edge didnt exist ,
      // it was stated as -1 so to simplify it , we replace it 
     
     // to reach node to node itself , cost  =0 
     // so diagonal ele =0  

       if(i== j ) matrix[i][j] = 0 ;
    }
}

//0 base indexing Graph 

// FLoyd Warshal Algo 

for(int via= 0 ; via < n ;via++){ // wrt every node 
    for(int i =0 ; i < n ;i++ ){ // store all possible  min paths from every other pair form remaining nodes 
        for(int j= 0 ; j < n ;j++ ){
        
        // Check to make sure we dont travel b/w 2 nodes via an unreachable node 
        if(matrix[i][via]!=INT_MAX && matrix[via][j]!=INT_MAX)
            matrix[i][j] = min( matrix[i][j]  , matrix[i][via] + matrix[via][j] ) ;
        }
    }
}

// Just for the sake of ans As given in Ques 
for(int i  =0 ; i < n ;i++) {
    for(int j =0 ; j < n ;j++ ){
        if(matrix[i][j] == INT_MAX) matrix[i][j] = -1 ;
    }
}
}


int main(){
int n ; cin >> n ;

vector<vector<int>> matrix(n , vector<int> ( n , 0 )) ;

for(int i= 0; i < n ;i++ ){
    for(int j= 0; j < n;j++ ){
        int inp ; cin >> inp ;
        matrix[i][j] = inp ;
    }
}

shortest_distance(matrix) ;

for(int i= 0; i < n ;i++ ){
    for(int j= 0; j < n;j++ ){
      cout << matrix[i][j] << " " ;
    }cout << endl ;
}

}