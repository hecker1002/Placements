#include <bits/stdc++.h>
using namespace std ;



/*

Given 2 strings a and b , find a supersequence (a COMBINation of BOTH STRINGS WHICH CONTAIN BOTH A AnD B as subsequences) and 
return the longest length of such a supersequence .

e.g. -  a ="ABNC" , b = "WBMCD"  , Now easiset supersEQUENCE CONTAINING both strings AS SUBSEQUENCES 
are  a+b = "ABNCWBMCD" , but on observation , we see , the common elelemnts present in both strings("BC") 
. ONLY a single copy of each of these elem. and rest of the uncommon elelments are  included as same .
need to be included . e.g. - "A W B N M C D"

Now , these common elements are actually - LCS (Longets common subsequence )

so , length of shortest subsequence = len(a) + len(b) - len(LCS) (since we are 
concerned to find the length ONLY of such shortest supersequence).

*/

int dp[1002][1002] ;

int lcs (string a , string b , int n , int m  , int dp[][1002]){

if(n==0 || m==0){
    return 0 ;
}

// choice diagram 

// dp part
if(dp[n][m] != -1 ){
    return dp[n][m] ;
}
if(a[n-1]==b[m-1]){
    return  dp[n][m] =  1+lcs(a , b , n-1 , m-1 , dp) ;
}

else {

    return dp[n][m] = max( lcs(a , b , n-1 , m , dp) , lcs(a , b, n , m-1 , dp)) ;
}

}


int len_shortest_supersequence (string a , string b){




// since we only need to return the length of such shortest super-sequence and for this we need to remove the lcs only ONCE from the 
//whole supersequence 
// of worst case .
    return a.size() + b.size() - lcs( a , b , a.size() , b.size() , dp ) ;
}


int main (){

string a = "acbd" ;
string b = "dcxerd" ;
memset(dp , -1 , sizeof dp ) ;
cout << len_shortest_supersequence(a , b ) ; // correct answer =  8 (length of SHORTEST SUPERSEQUENCE )


    return 0 ;
}