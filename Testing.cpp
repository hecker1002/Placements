#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// MY INBULILT FUNCTION ( CUSTOM )
// NEVER DELETE IT .

ll mod_mul(ll a, ll b, ll m)
{
  a %= m;
  b %= m;
  return (a * b) % m;
}
ll mod_add(ll a, ll b, ll m)
{
  a &= m;
  b %= m;
  return (a + b) % m;
}
ll highest_power_of_2_present(ll n) { return __builtin_ctz(n); }

// if you are updating the loop counter inside the loop based on some condition, use for(ll i=0;i<n;)
// (NO i++ used).

ll total_ways_of_selecting_k_consecutive_elements(ll start, ll end, ll k) { return max(0LL, end - start + 1 - k); }

// printing a vector

void print_v(vector<int> v)
{
  for (int j = 0; j < v.size(); j++)
    cout << v[j] << " ";

  cout << endl;
}

// iterate or travel in a set (single copy in sorted order).

void set_travel(set<int> s)
{

  for (auto it : s)
  {
    // Righ now , it only displays all elelemnts of set .
    // cout << it << " ";
  }
}

// integer to string - to_string(n)

string i_to_s(ll n)
{
  string ans = to_string(n);
  return ans;
}

// string to integer - stoi(s)

ll s_to_i(string s)
{
  ll n = stoi(s);
  return n;
}

// find a substring 'small' in a larger string 'large' : and return its position (-1 means 's' is NOT present in str )

int finding_s_in_str(string large, string small)
{

  size_t found = large.find(small);

  if (found != string::npos)
  {
    return found;
  }

  return -1;
}

// To make a 2D matrix for Memoization of DP problems and initialize the whole 2D matrix with -1 .
// int dp_call(int W, int wt[], int val[], int n) {

// vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
// return solve(t , W , wt , val , n);

//  }

// }


void words(string s , int n   , set<string> st ){

  // BC 
  if(n<=1){
   return ;
  }

  if(n==2){
    st.insert(s.substr(0 , 1));
    st.insert(s.substr(1 , 1)) ;
  }
  
  
// Induction  + hypo 
// Recursive Tree nd at each level , find all psosible distinct cases 
string s1 = s.substr(1 , s.size()-1) ;
string s2 = s[0] + s.substr(2 , s.size()-2) ;

// Case1                    
st.insert(s1) ;

// Case2 
st.insert(s2) ;
words(s1 , n-1 , st)  ;
 words(s2 , n-1 , st ) ;

}


int main()
{

// number with higher no. of digits should contain low magnitude ,
// but if they have equal no. of digits , equal dsitribof digits should be done , min1 (from num1) ~ min2 (from num2) , liek that

int t ; 
cin >> t ; 

while(t--){

  string s ; 
  int n ;

  cin >> n >> s ;

set<string> st ;
words(s , n , st ) ;

cout << st.size() ;

}


  return 0;
}

// #include <bits/stdc++.h>
// using namespace std ;



// int main(){


//     return 0 ;
// }