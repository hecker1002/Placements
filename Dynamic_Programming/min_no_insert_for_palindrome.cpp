#include<bits/stdc++.h>
using namespace std;

/*


given a string s , find the min. number of insertions we can do in the string , to make it a palindrome 

solution - we can actually add ele corresponding to elemnts that do NOT occur in pair (ie that are NOT part of palindrome ) . 

hence , no of deletions = no., of insertions 

*/

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



int min_no_insert_palindrome (string s){
    return s.size() - LPS(s) ;
}


int main(){
  
  string x = "aebcbda" ;

  cout <<min_no_insert_palindrome (x) ; // correct answer = 2 
    return 0;
}