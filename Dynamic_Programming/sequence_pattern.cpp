#include<bits/stdc++.h>
using namespace std;



/*

Sequence Pattern Matching 

given a string a , find wether string a occurs in  string b as a sub-sequence or not .

if(LCS (s , b) == len(a) true ; else false ; ) since LCS = ( 0 to min(a,b)) , hence , if LCS=min(a,b) , a occurs in b cmpletely .

*/

// LCS (top down approach)


int t[1002][1002] ;


// LCS top down approach

int LCS (string x , string y , int n , int m){

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

 return t[n][m] ;


}

// apttern matching code 

bool pattern_matching (string a , string s) {

if(LCS(a , s , a.size() , s.size()) == a.size()) return true ;
else return false ;

}



int main(){
   
string a = "xcy" ;

string b = "sxfgcnnuy" ;

if(pattern_matching(a , b)) cout <<"string a present in b !!" ; // correct answer = true .
else cout <<"not present " ;

    return 0;
}