#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*

Target Sum Problem - given an arr[] ={1,1,2,3 } and a given target sum = 1

find no of diff ways to assign (+  / - ) to each element of arr such that sum of all elemne is NOW  = target sum .

Logic , eg = +1 +1 +2 -3 = 1 , if you observe , by assigning signs ,
we are actually dividing the arr into 2 subsets whose diff = target sum

Proof - s1 = 1,1,2  ,  s2 = 3  and now sum(s1) -sum(s2) = target sum  , (since - distributes over s2 )

Hence , code is same for - Count no of different subset pairs  whose difference = given diff

*/

// we are actually counting subset pairs here ( of a given diff )

nt dp[101][1002];

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

int subset_with_diff(int *arr, int n, int target)
{

    int req = 0;

    for (int i = 0; i < n; i++)
    {
        req += arr[i];
    }

    int sum = (req + target) / 2;

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
