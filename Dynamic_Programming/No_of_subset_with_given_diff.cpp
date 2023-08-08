#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*


// we are actually counting subset pairs here ( of a given diff )


given an int arr[]  = {1 , 1 , 2, 3} and  diff =1 , find No. of subsets from arr[] whose difference = given diff .

// all possible subsets = {1,1,2} {3}
                          {1,2}  {1,3}
                          {1,2}  {1,3} // these are diff. since we used 1 at different positions

(for subset , select any elements from set in any order ).

now , sum(s1) - sum(s2) = given diff  BUT we also know ,
      sum(s1) - sum(s2) = sum(arr) (LOGIC)

      Now , solving these , we get sum(s1) = (diff + sum(arr))/2 , so find all possible subsets form given set whose sum  = (diff + sum(arr))/2
       This is same as subset sum problem solved eralier by me ( a variation of 0-1 knapsack )
*/

// subset sum problem of dp , assuming solve returns if such a subset whos sum = given sum exists or NOT

int dp[101][1002];

int solve(int arr[], int n, int sum, int curr)
{

  // base condition

  if (sum == 0)
  {
    // count+=1;
    return 1;
  }

  if (n == 0)
  {
    if (sum == 0)
    {

      return 1;
    }

    return 0;
  }

  if (curr == sum)
  {
    return 1;
  }

  // memoization aprpoach of dp

  if (dp[n][sum] != -1)
  {

    return dp[n][sum];
  }
  // choice diag - final answer depends on decision we take for smaller inputs (arr = weight array)

  if (arr[n - 1] <= sum)
  {

    // we can include / NOT imclude the last elemetn in our subset , explore both possibilities and return possible subsets by rec. call for new
    // subset sum with n-1 eleemnts and add them to find total NO of POSSIBLE subsets
    return dp[n][sum] = solve(arr, n - 1, sum - arr[n - 1], curr + arr[n - 1]) + solve(arr, n - 1, sum, curr);
  }

  else
  {
    return dp[n][sum] = solve(arr, n - 1, sum, curr);
  }
}

int subset_with_diff(int *arr, int n, int diff)
{

  int req = 0;

  for (int i = 0; i < n; i++)
  {
    req += arr[i];
  }

  int sum = (req + diff) / 2;

  int curr = 0;

  int ans = solve(arr, n, sum, curr);

  return ans;
}

int main()
{

  memset(dp, -1, sizeof dp);

  int arr[4] = {1, 2, 4, 5};

  cout << subset_with_diff(arr, 4, 1);

  return 0;
}
