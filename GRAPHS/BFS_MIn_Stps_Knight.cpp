
#include <bits/stdc++.h>
using namespace std ;

    
/*

Given index of knight inchessboard(n x N ) , find min steps for knight(k) to reach target index ( T) . ( 1 abse indexing)


BFS in matrix  - use matrix to reach children node and then push it  sub children if unvisited 
Always use queue for BFS . 


*/
    int minStepToReachTarget(vector<int>&K,vector<int>&T,int n )
	{
	    
	    // Logic  - Do the BFS traversal in  matrix ( in term of indexes)
	    // and update steps to reach index = value at (parent index) + 1 
	    // initially all 0 ( steps to reach each node )
	    
	    // BFS in matrx ( use queue , push first index ,and travel to each child
	    // and then in next itr , push sub-children )
	    
	    // knight pos 
	    int k1  = K[0] , k2 = K[1] ;
	    
	    // target pos (index)
	    int t1 = T[0] , t2 = T[1] ;
	    
	    queue < pair<int , int> > q ; 
	    q.push( { k2 , k1 }) ;
	    
	   int del_r[4] = { -1 , 1 , -2 , 2  } ;
	   int del_c[4] = { -1 , 1 , -2 , 2  }  ;
	        
	    // matrix to show steps to reach that index 
	    vector< vector<int> > dp ( n+1 , vector<int> (n+1 , 0 )) ;
	    if( k1==t1 && k2==t2){
	        return 0 ;
	    }
	    while (!q.empty()) {
	        
	        auto parent = q.front() ;
	        q.pop() ;
	        
	        //  travel to curr nodes children
	        
	        // for Knight , there are 8 possible children decided by - 
	        
	    
	        
	        for ( int i =0 ; i < 4 ; i++ ){
	            for(int j =0 ; j < 4 ; j++ ){
	       // we are doing this since we have 4 sized array and trying all combiantiosn
	       // giving 16 children but ONLY 8 children possible When 
	       // old row + num1 , old col + num2 , and num1 and num2 should be diff ( so we use
	       // magnitude to sperate tem and complete task in less code )
	           if ( abs(del_r[i])!=abs( del_c[j])){
	                // children indices 
	                int n_col  = parent.first + del_c[i] ; 
	                int n_row = parent.second + del_r[j]; 
	                
	                // check if children is NOT parent and if they are acceptable children 
	                // then update steps to reach tem 
	                // dp[row][col] == 0 ( means unvisited node )
	                // for min steps , show ans at first instance when 0 changes 
	                if ( n_row>=0 && n_row<n+1 && n_col>=0 && n_col<n+1 && dp[n_col][n_row]==0){
	                    q.push({n_col , n_row}) ;
	                    // adding 1 since 
	                    //steps[ to reach parent] + 1 = steps[to reach child]
	                    dp[n_col][n_row] = 1 + dp[parent.first][parent.second ] ;
	                }
	           }
	           }
	        }
	    }
	    
	   // if ( dp[t2][t1] == 0) { return -1 ; }
	    return dp[t2][t1] ;
	    
	}