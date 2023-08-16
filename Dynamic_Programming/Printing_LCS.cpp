#include <bits/stdc++.h>
using namespace std ;


/*
given 2 strings x = "abcg" and y="ag" , print the LOngest Common Subsequence (can be discontinuous) common in both strings 

Print the actual string and NOT the length .

Build the dp table from  general LCS (int return type) and follow path in dp table following rule 

if equal ->( i , j )  => (i-1 , j-1 )  and add this common element int eh ans string 

if NOT equal -> (i , j) => max (dp[i-1][j]  , dp[i][j-1] )

*/

int t[1002][1002] ;


// LCS top down approach

void LCS (string x , string y , int n , int m){

// initialization 
for(int i=0 ;i<n+1 ; i++){
    for(int j=0;j<m+1 ; j++){

        if(i==0 || j==0) t[i][j] = 0 ;
    }
}

for(int i=1 ;i<n+1 ; i++){
    for(int j=1 ;j<m+1 ; j++){


   // choice diag 

   if(x[i-1]==y[j-1]){
    t[i][j] = 1 + t[i-1][j-1] ;
   }

   else {

    t[i][j] = max(t[i-1][j] , t[i][j-1] ) ;

   }
        
    }
}

// filling the dp table completed 


}


// function to PRINT THE LCS 
// It is like a reversal of top down approach of dp .

string print_LCS( string x ,string y , int n , int m ){

    int i= n , j = m ;

    string ans = "" ;


  // filling the dp table 
    LCS(x , y , n  , m) ;

    while(i>0 && j>0){

        if(x[i-1]==y[j-1]){

            // if last ele of both string equal , it means it has come from a case where some other ele might be equal so call it
            // for X (n-1 chars) and y(m-1 chars). 

            ans.push_back(x[i-1]) ;
            i-- ;
            j-- ;

        }

        else {

            // if chars NOT same , go into that case where LCS's length is more .

            if(t[i-1][j] > t[i][j-1]) i--;
            else j-- ;
        }
    }

    // reversing is IMPORTANT since we are checking and storing common elements making the LCS from backside of both strings but string
    // is read from front .

    reverse(ans.begin() , ans.end()) ;

    return ans ;
}

// PROOF & EXPLANATION OF ABOVE METHOD - 

/*

If anychar. of the strings x and y match , then we store it .So , we start from last char of both strings and if it is same , then we 
we know more common char can be found in taking i-1 and j-1 chars of x and y (since one char we already evaluated ) .

Now  , if these chars are NOT equal , remove them one-by-one and find LCS in strings combination where LCS is more .since there we can
find more common chars for LCS .

In other words , through the use of DP table (that gives us the length of LCS ) , by comparing till a partiiclar char of a particular strings
what is max len. of  LCS  possible , we are taking its help to find and compare the common chars and the 
prev case where LCS included common chars .
 And , here we are actually retracing our path from largest LCS to base case .
 
*/


int main(){



string x = "abcfgh" ;
string y = "acgtt";


cout << print_LCS( x , y, x.size() , y.size()) ; // correct answer = acg 


    return 0 ;
}