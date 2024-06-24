#include <bits/stdc++.h>
using namespace std;


// No of Unique Apths from (i,1) index tp (n , m) last index ( using Dyanmic Progg)


// TRick - for DP problems , always draw a recurisve  tree and just code it 
// carefully see conditio at each of your choice 
   int paths ( int i , int j , int n , int m  , vector< vector<int > > &dp ){
    
    // BC ( assume 1 unique apth always exist here )
    if( i==n && j==m ){
        return dp[i][j] =  1 ;
    }

    else if ( dp[i][j]!=-1 ){ return dp[i][j] ;}
    
    int right = 0 , down =0  ;
    // this shows no of unique apth if we move right
    if ( j+1 <= m )
     right = paths(i , j+1 , n , m , dp  ) ;

   // no of unique apth if we move down( both are independent)
   // addition principle 
    if( i+1 <=n )
    down = paths( i+1 , j , n , m , dp ) ;

// add both the results 
    return dp[i][j] = right + down ;

   }
   int uniquePaths(int m, int n) {
        
        vector< vector<int> > dp ( n+1 , vector<int> ( m+1 , -1 )) ;
    return  paths( 1 ,1 , n , m , dp ) ;
   }