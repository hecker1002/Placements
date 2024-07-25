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



void solve() {
int n ;
cin >> n ;

vector<int> v(n) ;

for(int j =0 ; j<  n ;j++ ){
    cin >> v[j];
}

vector<int> left(n) , right(n)  ; 

stack<int> L, R  ;

L.push(v[0]) ;
left[0]=0 ;
for(int j =1  ; j < n ;j++ ){

if( v[j-1]%v[j]==0 ){
int cnt =0 ;
 while(!L.empty() && L.top()%v[j]==0){
    L.pop() ;  cnt++ ;// pop all the ele divisible form curr ele ( => gcd of all these number that we popped )
 }
 left[j]=cnt ;
}

else { L.push( v[j] ) ; left[j]=0 ;}
}
// RIght stack
R.push(v[n-1]) ;
right[n-1]=0 ;
for(int j =n-2  ; j >=0;j-- ){

if( v[j+1]%v[j]==0 ){
int cnt =0 ;
 while(!R.empty() && R.top()%v[j]==0){
    R.pop() ; cnt++ ;  // pop all the ele divisible form curr ele ( => gcd of all these number that we popped )
 }
 right[j] = cnt ;
}

else { R.push( v[j] ) ; right[j]=0 ; }
}

int dist  = INT_MIN ;

for(int j =0 ; j < n ;j++ ){
    dist = max( dist , abs( (j-left[j]) - (right[j] + j ) )) ;
}
int pairs =0 ;
vector<int> arr ;
for(int j =0 ; j < n ;j++ ){
    if(abs(  (j-left[j]) - (right[j] + j ) )==dist){ pairs++ ; arr.push_back(j-left[j]+1 ) ;}
}

cout << pairs << " " << dist << endl ;
for(int j =0 ; j < arr.size() ; j++ ){
    cout << arr[j] << " " ;
}
cout << endl ;

}



signed main() {
// FAST I/O
ios_base::sync_with_stdio(0) ;
cin.tie(0) ;
cout.tie(0) ; 

// int t ; cin >> t ;

// for(int i_ =0 ; i_ < t ; i_++ )
solve() ;


}

