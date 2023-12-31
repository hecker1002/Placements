//by Raja Bhavesh
//Difficulty Level-> Medium
//Question Link-> https://leetcode.com/problems/maximum-product-subarray/

//Method 1-> 
//The idea is to traverse over every contiguous subarray, find the product of each of these subarrays
// and return the maximum product from these results.
//Time Complexity-> O(N*N)
//Space Complexity-> O(1)
// C++ program to find Maximum Product Subarray
#include <bits/stdc++.h>
using namespace std;

/* Returns the product of max product subarray.*/
int maxSubarrayProduct(int arr[], int n)
{
    // Initializing result
    int result = arr[0];

    for (int i = 0; i < n; i++) {
        int mul = arr[i];
        // traversing in current subarray
        for (int j = i + 1; j < n; j++) {
            // updating result every time
            // to keep an eye over the maximum product
            result = max(result, mul);
            mul *= arr[j];
        }
        // updating the result for (n-1)th index.
        result = max(result, mul);
    }
    return result;
}

// Driver code
int main()
{
    int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
        << maxSubarrayProduct(arr, n);
    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)




//Method 2-> 
//In this method we initialise two variable that stores the prefix and suffix product upto a given index accordingly
//then we update the max value at each step and whenever prefix or suffix product becomes zero means 0 is encountered then
//we start new subarray traversing by updating prefix sum=1,suffix sum=1;
//C++ Code

//Time Complexity-> O(N)
//Space Complexity-> O(1)

 int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;//used to store the max sub array product
        int n=nums.size();
        int pref=1;
        int suff=1;

        for(int i=0;i<n;i++){
            if(pref==0){//means 0 is encoutered updation required
                pref=1;
            }
            if(suff==0){//means 0 is encoutered updation required
                suff=1;
            }
            pref=pref*nums[i];
            suff=suff*nums[n-i-1];
            ans=max(ans,max(pref,suff));
        }
        
        return ans;
    }



//Thanks!!!!!!!!!!!!!!!!!!!!!
