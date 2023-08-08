
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 


/*

  SUBSET SUM PROBLEM 

   given an integer array , arr[] = {2, 4, 8,12, 3} and a target sum/sum = 11 , then answer in Yes / No , if there exists a subset of the given
   arr[] whose sum of elements in the subset  is equal to given sum .



It is similar to a 0-1 Knapsack since final answer depends on the decisions we take (of chossing or NOT chossing an element ) based on 
remaining sum to be fulfiled (remaining weight of knapsack based on condition if we selected / NOT the current element .)
*/

// n , sum = variable quantities so use them to make the 2D matrix


// memoization 
int dp[102][1002];



bool subset_sum(int arr[] , int n , int sum){

// base condition

if(n==0){
    if(sum==0) return true ;

    else return false ;
}

if(sum==0){

    return true ;
}


if(dp[n][sum]!=-1){
    return dp[n][sum];
}
// choice diag 

if (arr[n-1] <= sum) {

    // select/ NOT select (use OR condition siccne we WANT at least 1 True to occur )
  
  return dp[n][sum]  = (subset_sum(arr , n-1 , sum-arr[n-1]) || subset_sum(arr ,n-1 , sum) ) ;

}

else {

    // never select

    return dp[n][sum] = subset_sum(arr,n-1 , sum);

}

}


// top-down approach 


// 2D matrix

bool t[102][1002] ;

bool subset_sum_top_down(int arr[] , int n , int sum ){

// initialization (BC of memoize)

for(int i=0;i<n ;i++){
    for(int j=0;j<sum;j++){
        if(i==0) t[i][j] = false ;

        if(j==0) t[i][j] = true ;
    }
}


for(int i=1 ; i<n;i++){

    for(int j=1;j<sum;j++){
// choice diag  ( by sub-problem )

if (arr[i-1] <= j) {

    // select/ NOT select (use OR condition since we WANT at least 1 True to occur )
  
  return t[i][j]  = (t[i-1][j -arr[i-1]] || t[i-1][j] ) ;

}

else {

    // never select

    return t[i][j] = t[i-1][j];

}
    }
}

}




int main(){

memset(dp , -1 , sizeof dp);

int arr[5] = {1 , 4, 12, 6 ,8};

// Memoization approach
if(subset_sum(arr,5, 11)) cout <<"yes\n";
else cout <<"no\n";

// top down approach
if(subset_sum_top_down(arr,5, 11)) cout <<"yes";
else cout <<"no";


    return  0;
}

