#include <bits/stdc++.h> 
using namespace std ;


/*

Longest Common Substring - (lcs) 

For 2 given strings x and y , find the length of substring (continuous part of a string) common in both the strings and return the 
longest such length possible .

Logic - vaariatio of LCS (subsequence) since every subsequence can be a a substring 




*/

// n = length of x and m = length of y 

// top down approach 

int t[1005][1005] ;


int longest_common_substring (string x, string y , int n , int m , int ans  ){

ans = INT_MIN ;

//initialization 

for(int i=0 ; i<n+1 ; i++){
    for(int j=0 ; j<m+1 ; j++){

// base condition - if any of the strings is emptty 
    if(i==0 || j==0 )t[i][j] =  0 ;

    }
}


for(int i=1 ; i<n+1 ; i++){
    for(int j=1 ; j<m+1 ; j++){
  

  // if last element are same  , add it in common sub string

  if (x[i-1] == y[j-1]) {
    t[i][j] = 1 + t[i-1][j-1] ;
 

 // now , since it is linearly checking , so find longest substring possible in x of length i and y of length j .
    ans = max(ans , t[i][j]) ;


  }

// if last/ curr lement of both strings are NOT equal , it means - there is a discontinuity and we can  NOT include the last element 
// in our sub string .

  else {

    t[i][j] =  0 ;
  }
        
    }

   
}


 return ans ;
}

int main (){

  string x = "dfggacgh" ;
  string y = "acgtt";
  
 cout << longest_common_substring(x ,y , x.size() , y.size()  , 0) << endl ;
 
    return 0 ;
}