#include <bits/stdc++.h>

#define int  long long  
const int M =  1e9 + 7 ;
using namespace std ;

/*
LOGIC 
*/

// function for ONE test case 

int exp_mod_M ( int a , int b  ){
    // find a^b mod ( M ) -> exponetiatil fun / bin exp 
    // ( remeber) , b^(p-2) is mod inv of (b mod p)  where p = prime 

    // bc
    if( b== 0) return 1  ;

    else if ( b%2 ==1 )return a * exp_mod_M(a , b-1 )%M ;
    else return  exp_mod_M(a , b/2 ) * exp_mod_M( a , b/2  )%M;


}

// find mod inv of a number by fermat little th 
// if p = prime and a^(p-1) => 1 mod M , then a^(p-2) is mod inverse of (a mod M). 

void solve() {


int n ; cin >> n ;
vector<int> v( n , 0)  , prev(n , 0);

for (int j =0 ; j < n ;j++ ){
  cin >> v[j] ;
  if(j > 0)prev[j] = v[j]| prev[j-1] ;
}
prev[0] = v[0] ;


int ans  = 0 , idx =0  , step =0 ;

for (int j =0 ; j < n ;j++ ){
cout << prev[j] << " " ;
// ans  =0 ;
//  while ( prev[j]== prev[j+1] && j+1 < n && prev[j]!=0){  ans++ ;  j++;}
//  if(prev[j]==0){ans++; continue;} ans++ ;
}

 cout << ans <<  endl ;


}

signed main() {
// FAST I/O
ios_base::sync_with_stdio(0) ;
cin.tie(0) ;
cout.tie(0) ; 

int t ; cin >> t ;

for(int i_ =0 ; i_ < t ; i_++ )
solve() ;


}

