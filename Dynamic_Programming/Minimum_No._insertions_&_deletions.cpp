#include <bits/stdc++.h>
using namespace std ;

/*

given 2 strings a ="heap" and b ="pea" , find the MINIMUM no. of Insertions and deletion f chars. to convert string a to string b .
e.g. - delete h and p and add p to start (deletion =2 , insertion=1 )

it uses 2 strings and output is same as LCS quesn , hence , it is a variation of LCS problem .

Logic - while converting a to b in min. no. of ways , we want to doo insertion on deletion on elemnts
s other than those which are NOT common in both strigs . 

Hence , we e=want to do insertion and deletion around LCS .
so convert a-> LCS and then this new LCS->b .


*/

// Top down approach of finding LCS 

 int dp[1002][1002] ;

int  LCS(string a , string b , int n , int m ){
 


 // initialization
for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){

       if(i==0 || j==0)  dp[i][j] = 0 ;


    }
}

// choice diag.

for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){

   // if last element of both string same , do rec. call for rest of the string 
        if(a[i-1]==b[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1] ;
        }

        else {

            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
        }


    }
}

return dp[n][m] ;

}

int deletions (string a , string b){

    // to convert a to LCS = a - lcs 

    return a.size() - LCS(a , b , a.size() , b.size()) ;



}



int insertions (string a , string b ){

// for insertion , convert lcs to string b = b - lcs 

return b.size() - LCS(a , b , a.size() , b.size()) ;


}

// CAUTION - ALWAYS USE LAST ROW / COL AS -> i <n+1 (CORRECT) , NOT i<= n (INcorrect)


int main(){

string a  = "heap" ;

string b = "pea" ;

int insert = insertions( a, b) ;
int del = deletions( a, b) ;

cout <<  "No. of insertions are " << del << endl ;

cout << "No. of insertions are " << insert << endl ;


    return 0 ;
}