#include<bits/stdc++.h>
using namespace std;


/*

given a string x , find the lrs (Longest Repeating Subsequence) of given string x ie the subsequence that repeat in given string
and find the max possible length of such subsequence ( do not choose the same char for both sub-sequences )

find LCS(s , s) but with condition that same elemnt should 
not occur at same index .


Solution - we know that only elemnts commona nd repeating twice or more than twice can only be included in our LRS so , in the LCS
find the common ele of diff LCS but remeber , NOT take the ele which are common and in same index (since if this was true  , we would have to select
the whole string as our LRS .)
*/

// In C++ , while declaring args of a function , you can NOT pass same arg multiple times (even when you know later , you have to call teh 
//function by using thta same arg multiple times . )


// memoize 

int dp[1002][1002] ;

int LCS_special(string x , string y , int n , int m ){

// BC 
if(n==0 || m ==0){
    return dp[n][m] =  0 ;
}

// memoization
if(dp[n][m]!=-1){
    return dp[n][m] ;
}

//choice diag . 
if(x[n-1]==x[m-1] && n!=m){
    return dp[n][m] = 1 + LCS_special(x , y , n-1 , m-1) ;
}

else {
    return dp[n][m] = max(LCS_special(x , y , n-1 , m ) , LCS_special(x , y , n , m-1)) ;
}

}

int LRS (string x){

    return LCS_special(x , x , x.size() , x.size()) ;
}


int main(){
    
    memset(dp , -1 , sizeof dp );
    string x = "aafbbedd" ;
   cout <<  LRS(x) ; // correct answer = 3 (LCS repeating 2 times - abd)
    return 0;
}