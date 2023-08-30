# include <bits/stdc++.h>
using namespace std ;


/*


given 2 strings x and y , print the shortest common supersequence (SCS) ie a string containing both strings x and y as its subsesquence


e.g. - x + y - LCS 

fill the LCS dp table by trop down approach 

 Here , we are using LCS dp table , as it gives us an approach that how we traversed the dp table , is same as 
 how we traversed both string in search of LCS elements , NOw , the only diff is we use possibility of including common ele only once (by i->i-1 and j->j-1)
 and if NOT equal , explore possibility of exploring both the uncommon elements by ONLY updating i OR ONLY j . 

 
*/

int dp[1002][1002] ;

void  LCS(string x ,string y , int n , int m ){

 // initialization - BC 

 for(int i=0 ; i<n+1 ; i++){
    for(int j=0;j<m+1 ; j++){
    
    if(i==0  || j==0) dp[i][j] = 0 ;
       
    }
 }

// choice diag 

for(int i=1 ; i<n+1 ; i++){
    for(int j=1 ;j<m+1 ; j++){
    
   // if last ele equal 

   if(x[i-1] == y[j-1] ){
    dp[i][j] = 1 + dp[i-1][j-1] ;
   }

   else {

   dp[i][j] = max(dp[i][j-1] , dp[i-1][j]) ;
   }
       
    }
 }

}

void SCS( string x ,string y , int n , int m ){

    // fill the dp LCS table 

    LCS(x , y, n , m ) ;
    
    string s = "" ;
    // traverse from last elemtn of dp table 

    int i=n , j= m ;

    while(i>0 && j>0 ){

        // if curr ele is same , only occ is saved 

        if(x[i-1] == y[j-1]){
         
         s+= x[i-1] ;
         i-- , j--; 
        }

        else {


            // if LCS in dir of X is greater , include Y less frequent ele .

            if(dp[i-1][j] > dp[i][j-1]){
                s+= x[i-1] ;
                i--;
            }

            else {
                // else store the other char 

                s+= y[j-1] ;
                j--;
            }
        }
    }
 
 // if any string remained untraversed , travel it and include evry ele of it 
    while(i>0){
     
     s+= x[i-1] ;
     i--;
    }

    while(j>0){
        s+= y[j-1] ;
        j-- ;
    }

reverse(s.begin() , s.end()) ;
cout << s ;
}


int main(){


string x = "dacb" ;
string y = "ahb";

SCS(x , y , x.size() , y.size()) ;
    return 0 ;
}