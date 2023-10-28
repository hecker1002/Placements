#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Find The maximum profit you get when buying a tock at lowest price on some day i and selling it
// on some day 'j' where j>i always . (how stocks work in real market .)



// APPROACH -1 
//
// we want the highest price to be at the end of array as possible . so we search for min element till 
// curr index and find max among curr. breakpoint data (where a[j+1] > a[j]) and  max till now and curr min
// and max till now and min till now (but only if index(max) > index(min))

int maxProfit(vector<int> &a)
{
    int n = a.size();
    if (n == 1)
    {
        return 0;
    }
    int mn = INT_MAX;
    int mx = INT_MIN;
    int ans = INT_MIN;
    map<int, int> mp;
    for (int j = 0; j < n; j++)
    {
        mp[a[j]] = j;
    }
    for (int j = 0; j < n - 1; j++)
    {

        if (a[j] <= a[j + 1])
        {

            mn = min(mn, a[j]);
            mx = max(mx, a[j + 1]);

            if (mp[mx] > j)
                ans = max(ans, mx - mn);
            ans = max(ans, a[j + 1] - mn);
        }
    }

    if (ans < 0)
        return 0;

    return ans;
}


// APPROACH - 2
// Two pointer approach - 
// initialize left ptr =0 and right ptr = 1
// and when you get a breakpoint (a[j+1] > a[j]) compute 
//max profit but if(curr a[right] > a[left_curr] , it means high chance of max profit , update l=r)
// and irrespective of this , in each loop , increase r to search for max price.

int maxP (vector<int> &a){

int l =0  , r=1  , maxP = INT_MIN;

if(a.size()==1) return 0;

while( r <a.size() && r>l){

    if(a[l] < a[r])
    maxP = max(maxP , a[r]-a[l]);
    else l = r;

    r++;

   
}


 return maxP ;
}

int main()
{


vector<int> prices = {5 , 8,  1, 2} ;
cout << maxProfit(prices) << endl ;
cout << maxP(prices) << endl ;
    return 0;
}
