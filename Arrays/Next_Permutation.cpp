#include <bits/stdc++.h>
using namespace std;
#define ll long long int


// Logic - Next Permutation of an integer array = remove all commas and form a number from it 
// and the JUST  Greater Number than given number(array) in a dict. is its next permutation

// Solution - To go forward in dict , we want to increase the num. as right of num. as possible .
// and for this , we find first breakpoint from right  (where a[i] > a[i-1] as then only we can inc. the number in far right corner).
//    1 3 5 4 2
//        as
//         5
//      3    4
//    1        2 ( breakpoint - b/w 3 and 5)

// and now , swap the number just greater than current breakpoint( choose it from far right)
// and Now since prefix has changed and right of it will always be decreasing seq so
// for new perm. , sort / reverse from right of old breakpoint 





void nextPermutation(vector<int> &nums)
{
    bool check = false;
    int n = nums.size();
    int ind1 = 0;
    for (int j = n - 1; j >= 1; j--)
    {
        if (nums[j] > nums[j - 1])
        {
            ind1 = j - 1;
            check = true;
            break;
        }
    }

    if (!check)
    {
        reverse(nums.begin(), nums.end());
    }


    else
    {
        for (int j = n - 1; j >= 1; j--)
        {
            if (nums[j] > nums[ind1])
            {
                swap(nums[j], nums[ind1]);
                reverse(nums.begin() + ind1 + 1, nums.end());
                break;
            }
        }
    }
}

int main()
{

    vector<int> nums = {1, 3,5,4,2};
    nextPermutation(nums);

    for (int j = 0; j < nums.size(); j++)
    {
        cout << nums[j] << " ";
    }

    return 0;
}