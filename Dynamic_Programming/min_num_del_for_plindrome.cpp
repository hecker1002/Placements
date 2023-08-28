#include<bits/stdc++.h>
using namespace std;

/*

given a string s = "agbcba" , what are the min. no of deletions we can dop to make the string a palindrome 


In other wordsa , min no. of deletions to make the string a palindrome and we know mno. of deletions is inversely prop. to 
n= len(palindrome formed ) , so for min no. of deletion , we find LPS (longest aplindrome subsequence from given string x .)



*/
int dp[1002][1002] ;

int LCS (string x ,string y , int n , int m ){

    // BC 
    
    if(n==0 || m==0) return 0 ;

// dp part

if(dp[n][m]!=-1){
    return dp[n][m] ;
}
    // choice diag .

    if(x[n-1]==y[m-1]){
        return dp[n][m] = 1+LCS(x , y , n-1 , m-1) ;
    }

    else {
        return  dp[n][m] = max(LCS(x , y , n-1 , m) , LCS(x , y, n , m-1)) ;
    }
}

int LPS (string s){
    string s1 = s ;
 reverse(s1.begin() , s1.end());
    return LCS(s , s1 , s.size() ,s1.size() ) ;
}

int min_del_for_palindrome(string s ){

return s.size()  - LPS (s) ;
}

int main(){
  
  memset( dp , -1 , sizeof dp );
  string s = "agbcba" ;

  cout << min_del_for_palindrome(s) << endl ;

    return 0;
}