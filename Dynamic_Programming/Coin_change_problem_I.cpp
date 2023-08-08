
#include <bits/stdc++.h>
using namespace std ;


/*

given a coin[] and a sum , find the Total No. of Ways we can exchange the sum for coins of some denomination (where each coin can be used
multiple times also ) , then find total no. of ways to make sum from the given coin[] in any way possible.

Logic - it is unbounded knapack with subset sum problem and also ADD the ways from each decision to get total no of ways .

*/

// Top Down approach - DP 


int total_ways( int coin[] , int sum , int n){

int dp[n+2][sum+2];

// j = current sum in top down aproach
// i=  current no. of coins from start 


// Initialization of dp[][] - 2D array 

for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
     
    dp[0][j] = 0 ;
     dp[i][0] = 1 ;
    }
}


// Choice diag - ADD for total no of ways 

for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++){

        // Unbonded knapsack + subset sum
     
    if(coin[i-1]<=j){ // if last coin denom. is less than sum , include / exclude it .

    dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j] ;

    }
   
   // else exclude it ansd find the no of ways from rest n-1 elements (i-1 elem .)
    else dp[i][j] = dp[i-1][j] ;

    }
}


return dp[n][sum];

}




int main (){

int coin[3] = {1,2, 3};
int sum = 5 ;

int total = total_ways(coin , sum , 3) ; // correct ans = 5

cout << total << endl ;

    return 0 ;
}