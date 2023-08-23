#include<bits/stdc++.h>
using namespace std;


/*

Longest Palindromic Subsequence - if we are given a string X = "agbcba" , then find the length of Longest possible subsequence (discontinuous
part of string ) which is also a Palindrome . ( Longest Palindromic Subsequence - LPS - subsequence which reads same forward and backward ).

Soln. - by observation , it is a variation of lcs , since we have same input and Quesn types ) , so find the write the given string X 
into revverse and find the LCS of X and reverse(X) and since paluindromeic subsequences will still be conserved in both strings , hence , 
LPS = LCS (X , reverse (X) ) . 

*/

// Top Down approach for LCS 

int dp[1002][1002] ;

int LCS (string x , string y , int n , int m ){

    


    // initialization of 2D array

    for(int i=0;i<n+1 ; i++){
        for(int j=0 ; j<m+1 ; j++){
            if (i==0 || j==0) dp[i][j] = 0 ;

        }
    }
   //choice diagram 

     for(int i=1;i<n+1 ; i++){
        for(int j=1 ; j<m+1 ; j++){
          
          /// last char if in suubsequebce

          if(x[i-1]==y[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1] ;
          }

          // if not equal , then call for omitted parts of string 

          else {
            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;

          }
        }
    }

    return dp[n][m] ;

}

int LPS(string x){
 string h = x ;
   reverse(h.begin() , h.end()) ;
 // return the length of longest palindromic subsequence 
    return LCS(x , h, x.size() , h.size() ) ;
}


// CAUTION - do NOT declare the dp (2D array ) inside the dp function  / rec. function (either declare it globally or make another 
// function to handle it . )

int main(){
   
   string x = "agbcba" ;
  cout << LPS(x) << endl ; // correct answer = 5 ("abcba" )

    return 0;
}