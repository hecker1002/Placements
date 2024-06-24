#include <bits/stdc++.h> 
using namespace std  ; 

/*

LOngest Increasing Subsequence  -  Subsequence of an array ( of int) which are in increasing order and of longest possible length . 
find length of this LIS 

lOGIC -  WRITE A RECURSIVE function that gives length of LIS  from curr_index+1 till last index (n-1) . 
Now here we have a choice ,  to CHOOSE curr_index elemnt in the returned LIS length or NOT , 
if we dont choose it , length does NOT increase . BUrt , if we choose it , length increases by 1 
and we choose the l=elelmnt under the condition that its the first elemnt or its greater than prev_index elemnt of current subsequnce 
we are dealing with 

*/


int LIS ( int curr_ind , int prev_ind, vector<int> A ,  vector< vector<int> > &dp){
     // Base case  - if we are at last index , no LIS possible 
      if ( curr_ind == A.size()  ) {
          return  0 ;
      }

   if ( dp[curr_ind][prev_ind + 1 ] != -1 ) return dp[curr_ind][prev_ind + 1 ]  ;
   // HYpo - works for every index till last index 

    // INduction - from curr index till last index ele , find the LIS and take choice 

    //  not take curr index ele  , find LIS length from curr _index till last (prev reamins same
    // since curr ele not taken )
    
    int not_take = 0 +  LIS( curr_ind +1 , prev_ind , A , dp ) ;
     
    // if take curr ele , then add1  to LIS from curr inde to last and prev updated to old curr 
    // COndition to take 
    int take  = -1 ;
    if ( prev_ind == -1 || A[curr_ind] > A[prev_ind])
     take  =  1 + LIS ( curr_ind +1 , curr_ind , A , dp  ) ;
    
    return dp[curr_ind][prev_ind + 1 ] = max( not_take , take ) ;
    
}



int Solution::lis(const vector<int> &A) {
    int n = A.size() ;
    // changing quantities are  - curr index (n) and prev_index (n+1) since -1 also included 
    vector< vector<int> > dp ( n ,  vector<int> (n+1 , -1 )  ) ;
    return LIS( 0 , -1 , A , dp  ) ;
}



int main() {


    return  0 ;
}