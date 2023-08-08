#include <bits/stdc++.h>
using namespace std ;


/*
  Rod Cutting Problem -  Given a rod of length (N) alongwith the (price[]) array for each length of rod cut (length[]) , find the max.
  profit achieved by cutting the rod in any way 

  Logic - This is an Unbounded Knapsack problem since the pieces of rod are like item (of which multiple instances can be put in  a knapsack
  of max. capacity N  and we have a decision to take a [iece in the knapsack orNOT based on condition of current weight of knapsack .])


 Code - Same as unbounded knapsack
*/


/*
 Analogy 

Knapsack    -  Rod Cutting 

W          -  N 
wt[]       - length[]
val[]      -  price[]

*/



int dp[102][1002];  // dp[len_array][max_length_of_rod_N]

int max_profit_rod(int N , int length[] , int price[] , int n ){

    //base condition

for(int i=0;i<n+1;i++){
    for(int j=0;j<N+1;j++){
    
    if(i==0 || j==0){
        dp[i][j] = 0;
    }
}
}

    // choice diag.
for(int i=1;i<n+1;i++){
    for(int j=1;j<N+1 ;j++){
    if(length[i-1]<= j){ // pick last item of length[] and
    // check if its length is less than max length = N then take a decision to include/ exclude it .
  
   dp[i][j] = max(price[i-1]+ dp[i][j-length[i-1]] , dp[i-1][j]);


    }

    else dp[i][j] = dp[i-1][j] ;
    }
}


return dp[n][N] ;
}

int main(){

    int length[5] = {1,2, 3, 4 , 5};
    int price[5] = {2, 5, 7 , 8 , 10};

    int N = 5 ;

    int max_profit = max_profit_rod(N , length , price , 5 ); // correct ans = 12 

    cout << max_profit << endl; 

    return 0 ;
}