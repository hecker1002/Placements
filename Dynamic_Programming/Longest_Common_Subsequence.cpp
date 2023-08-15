#include <bits/stdc++.h> 
using namespace std ;


/*

Longest Common Subsequence - given 2 strings x and y , find the length of the longest possible subsequence 
which is common in  both the strings .

e.g. - x ="anbc" , y="acd" 
Longest common subsequence is - "ac" (length = 2) 

(subsequence - can be discontinuous also )

Logic - since we can select any common elements of both the strings , we can select discontnous elements also

Now , we have a choice to pick elements to form an lcs or not (choice and decisions)  and optimal soln (longest) is asked .(DP quesn)
so , we find the choice diag . and BC 

// Choice diag  -

if last element of both the strings given are same , then it means it will ALWAYS be included in our lcs and hence we can add 1 and call
the LCS function for rest of each string x and y ( with new length - len_x-1 and len_y-1 ). But , if last element of both string are 
NOT same , then , we can call the LCS function for selecting 2 possibilities .( either last of x and some other char of y are same OR 
last of y and some other char of x are same )  , so , now , call the LCS function for x with len_x-1 but y with len_y and vice versa .

and return in such a case , max of LCS length returned by both possibilites

and base condition here is since string x or y any can become smaller so smallest valid input when either of them has length =0  and 
LCS length in such a case = 0 .

ALways remebeer , recursive funcn. works like magic if written correctly (here rec= choice diag .)


*/


int dp[1002][1002] ;



int LCS (string x , string y , int len_x , int len_y){

// Base condition

if(len_x==0 || len_y==0 ){

return 0;

}
// Memoized code 

if(dp[len_x][len_y]!=-1){
    return dp[len_x][len_y] ;
}

// Choice diag .


// condition 1 : if last char of both strings are same , it will always be included in our subsequence
if( x[len_x -1 ] == y[len_y -1 ]){
    return dp[len_x][len_y] = 1 + LCS (x , y , len_x -1 , len_y - 1) ;

}

// condition 2 : if last char are NOT same , take 2 possibilities that any other char of theirs can match .
// So now , find maximum among LCS length from selecting 1 char less  part of 1 string  and whole part of other string .

else {

    return dp[len_x][len_y] = max (LCS (x , y , len_x , len_y -1)  , LCS (x , y , len_x -1 , len_y)) ;
}


}


// Top Down approach - 




int main (){

  string x = "abcfgh" ;
  string y = "acgtt";
  memset(dp , -1 , sizeof dp) ;
  int LCS_len = LCS(x , y , x.size() , y.size()) ; // correct answer =  3 .

  cout << LCS_len << endl ;
    return 0 ;
}