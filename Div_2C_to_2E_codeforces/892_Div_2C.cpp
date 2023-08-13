
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 


// MY INBULILT FUNCTION ( CUSTOM )
// NEVER DELETE IT .

ll mod_mul ( ll a , ll b , ll m){ a%= m ; b%=m ; return (a*b)%m ; }
ll mod_add (ll a , ll b , ll m){a&=m ; b%= m ; return (a+b)%m ;}
ll highest_power_of_2_present (ll n){return __builtin_ctz(n); }

// if you are updating the loop counter inside the loop based on some condition, use for(ll i=0;i<n;)
// (NO i++ used).

ll total_ways_of_selecting_k_consecutive_elements(ll start, ll end , ll k){return max(0LL , end-start +1 - k);}

// printing a vector

void print_v(vector<int> v ){
    for(int j=0;j<v.size();j++)cout << v[j] << " ";

    cout << endl;
}

// iterate or travel in a set (single copy in sorted order).

void set_travel(set<int> s){
 
 for(auto it : s){
    // Righ now , it only displays all elelemnts of set .
    // cout << it << " ";
 }
}


// integer to string - to_string(n)

string i_to_s(ll n){
    string ans = to_string(n);
    return ans ;
}

// string to integer - stoi(s)

ll s_to_i(string s){
    ll n = stoi(s);
    return n ;
}


// To make a 2D matrix for Memoization of DP problems and initialize the whole 2D matrix with -1 .
// int dp_call(int W, int wt[], int val[], int n) {
    
// vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
// return solve(t , W , wt , val , n);
     
//  }
 
// }
/*


............................................................................................................................................

Problem Statement -  ( 892 - Div 2C - )

Andrey is just starting to come up with problems, and it's difficult for him. That's why he came up with a strange problem about permutations†
 and asks you to solve it. Can you do it?

Let's call the cost of a permutation p of length n
 & the value of the expression:

(∑ni=1pi⋅i)−(maxnj=1pj⋅j)

Find the maximum cost among all permutations of length n


*/


/*

Solution - 





*/




int main(){



ll t;
cin >> t ;

ll M = 1e9 ;
for( ll i=0;i<t;i++) {
    
   









}







    return  0;
}

