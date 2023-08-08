#include <bits/stdc++.h>
using namespace std;
#define ll long long int 


/*

Unbounded Knapsack - Same as 0-1 Knapsack , but here , we can have multiple instances of same item in our knapsack .

- Logic -> if we include an item (decision) in our knapsack , there is a possibility of including it again (so call the recursive 
 for 'n' elements , rather thann (n-1) but with reduced weight of knapsack since item included W-wt[n-1] and rest of the code remains same .)
since if we take decision to NOT include that item even once , it means we will never include it int he knapsack (dure to weight condition)
so , call for (n-1 element with same weight W of knapsack)

Unbounded knapsack - 0-1 knapsack with infinite supply of each / all type of items .

*/

// Top down approach -  n- i and W-j

int unbounded_knapsack( int wt[] ,int val[] ,  int n , int W   ){

int dp[n+2][W+2];

// initialization

for(int i=0;i<n+1;i++){
    for(int j=0;j<W+1;j++){
        if(i==0 ||  j==0) dp[i][j] = 0 ;
    }
}

// choice diag - breaking into sub-problem and solving them .
// do it by travelling in whole 2D array 

for(int i=1;i<n+1;i++){
    for(int j=1;j<W+1;j++){
        
    // SUB Problem

     if(wt[i-1]<=j){
        // include(for n = i elements again call with reduced weights) / NOT include (call for n-1 = i-1 elements ) and store it in corresponding 2D  array
        dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]] , dp[i-1][j]);
     }

     // else NOT include it 
      else dp[i][j] = dp[i-1][j]; // j = W of knapsack and i = no of items 

    }
   
}

return dp[n][W];

}

// Return dp[n][W] after top down approach to find maximum value possible in knapsack if we have n items and max weight = W .

// even after substitution , of n with i ,i still follows 0-base indexing , hence , last element of wt[] = wt[i-1] .


int main(){


int val[4] = {5 ,11 ,13} ;
int wt[4] = {2 ,4 ,6 };

int W = 10 ;

cout << unbounded_knapsack(wt , val , 3 , W) << endl;






    return  0;
}

