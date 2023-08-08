#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int Kth_symbol(int n , int k){
// BC
if( n==1 && k==1){
    return 0 ;

}
// hypothesis

    int mid = (pow(2 , n-1))/2;

// iinduction 
    if(k <= mid){
       return  Kth_symbol(n-1 , k);
    }

    else {
        return (!Kth_symbol(n-1 , k-mid));
    }
    
}



int main(){

int ans = Kth_symbol(4 , 3) ;

cout << ans << endl ;

    return  0;
}
