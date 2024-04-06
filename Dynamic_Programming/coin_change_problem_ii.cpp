#include <bits/stdc++.h>
using namespace std ;

/*
given a no. of coins , coin[] and a sum , find the min. number of coins required (if possible) to make the given sum .
 e.g. - coin[] ={1,2, 3}  , sum= 5 , min_coins = 2 (2+3=5 , smaller than 1+1+1+1+1 = 5)

Logic - unbounded knapsack + subset sum 

Code - But , here a special case arises , sometimes , we might have such coins which even when used infinitely , can NOT make req
sum , for such cases , we use INFINITE coins - (INT_MAX -1 ~ infinity)

So , in initialization , we do initialization of row 2 also (if sum divisible by n=1 , first coin , then OK but if NOT , infinite 
coins needed , dp[1][j] = INT_MAX -1 )

and for each subsequent cell of 2D matrix , we either include that coin for min ways ( 1 + dp[i][j-coin[i-1]] , else exclude it dp[i-1][j] (never include dit as unbounded knapsack ))
*/


int min_coins(int *coin, int sum , int n ){


// 2D matrix for overlapping sub problem 

int dp[n+1][sum+1] ;


// initialization (i = i coins from start , j = sum to be formed )

for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1 ;j++){

        if(j==0) dp[i][0] = 0 ; // if sum=0 , 0 coins needed min 

        if(i==0){
            // infinite coins needed to form sum if we have NO coins

            dp[0][j] = INT_MAX -1 ;
        }


    }
}


// initialization of second row ( ESPECIALLY FOR THIS PROBLEM ) since , we do NOT have sometinmes req. coins to make that sum .
// if (sum/ arr[0](1 st coin value) , then ONLY coins possible else infinite coins )

for(int j=1;j<sum+1 ;j++){

   // if (sum/ arr[0](1 st coin value) , then ONLY coins possible else infinite coins )
  // we are solving sub - problem  , so  , so use j inseteadd of  sum.
    if( j%coin[0]==0) dp[1][j] = j / coin[0] ;
    else  dp[1][j] = INT_MAX - 1; // infinite coins needed 

}

// start from row3 (i=2)
for(int i=2 ; i<n+1 ; i++){
    for (int j=1 ;j<sum+1 ; j++){
        
        // unbounded knapsack code with min() and add +1 if you include the ciurrrent (i-1)th coin or else  NOT and call for (i-1) rest 
        // coins , if NOT included  ( since unbounded knapsack) .

        if( coin[i-1]<= j ){

            // include ( add +1  for this coin to rec call for i coins ) / NOT include it 

            dp[i][j] = min( 1 + dp[i][j-coin[i-1]] , dp[i-1][j]);

        }

        // never include it 

        else dp[i][j]  = dp[i-1][j] ;

    }
}


return dp[n][sum] ;


}


int main(){


int t ; cin >> t ; 

for(int i_= 0  ; i_ < t ; i_++){

  int target  ;
  cin >> target ;

 int  coins[5] = {1 , 3 , 6 , 10 , 15 } ;




int ans = min_coins(coins  , target  , 5  ) ;

cout << ans << endl ;

}


    return 0 ;
}

// PS  - We are using INT_MAX -1 as infinity and NOT INT_MAX , so that the value if incread by 1 in some dp[i][j] , the value does NOT go 
// out of the bounds of int , i.e. -  1 + (INT_MAX -1 ) = INT_MAX <  (int) .