#include <bits/stdc++.h>
using namespace std ;

/*

GRAPHS 
- Non linear DS where data is stored at vertices (nodes) and all these nodes are connected by edges . 



Flood FIll - Start from a given Node in a pixel @D matrix and move to all 4 neighbours and whichever pizxel have sam einit_color , color 
them with a new GIVEN color (using DFS / BFS ) and go on like this . 
*/


// ASSUMPTION - Labelling of Nodes Using 1-based Indexing 

// Customised DFS traversal 

    void dfs ( vector<vector<int>>& image, int sr, int sc, int color ,vector<vector<int>> &vis , int init_col ,vector<int> delRow , vector<int> delCol ){
        vis[sr][sc] = 1 ; // visit the node 

        int n = image.size() , m = image[0].size() ;
        if(image[sr][sc]==init_col)image[sr][sc] = color ;

        for(int i= 0 ; i < 4 ; i++){
            int nRow = sr + delRow[i] ;
            int nCol = sc + delCol[i] ; 
             
             if((nRow <n && nRow>=0 ) && (nCol < m && nCol>=0 ) && (!vis[nRow][nCol]) &&
             (image[nRow][nCol] == init_col)){
                 dfs(image , nRow , nCol , color , vis , init_col , delRow , delCol); // for all its first NB , color them .
             }
        }

    }

// Call the DFS here 

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init_col = image[sr][sc] ;
        vector<vector<int>> vis(image.size() , vector<int> (image[0].size() , 0 )) ;
       vector<int> delRow = {-1 , 0 , +1 , 0 } ;
       vector<int> delCol = {0 , +1 , 0 , -1 } ;

        dfs(image , sr , sc , color , vis , init_col , delRow , delCol) ;
        return image ;

    }

int main(){








    return 0 ;
}