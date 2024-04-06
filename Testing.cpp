#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll M = 1e9 + 7;

ll mod_with_M(ll ans)
{
  return (ans % M + M) % M;
}

// MY INBULILT FUNCTION ( CUSTOM )
// NEVER DELETE IT .

// __gcd( n , m) - to find GCD of two numbers

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

int countSubstring(const std::string &str, const std::string &sub)
{
  if (sub.length() == 0)
    return 0;
  int count = 0;
  for (size_t offset = str.find(sub); offset != std::string::npos;
       offset = str.find(sub, offset + sub.length()))
  {
    ++count;
  }
  return count;
}

int highestPowerofTwoLessThanN(int n)
{
  if (n < 1)
    return 0;
  int pow = 1;
  while ((1 << pow) <= n)
    pow++;
  return (1 << (pow - 1));
}

bool func(pair<int, pair<ll, ll>> &a, pair<int, pair<ll, ll>> &b)
{
 
  if (a.second.first == b.second.first && a.second.second == b.second.second ){
    
    return a.first < b.first ;
  }
  else  if (a.second.first == b.second.first)
  {
    return a.second.second < b.second.second;
  }

  return a.second.first > b.second.first;
}

// int in C++ -> 4 bytes -> capapcity ( more than 2 x 10 ^9 ) 
/*

Logic - for each player , find time vector sort it and find all ques he can attempt
and thenpush tme in evcotr and sort and find position of indexed 1 player .
*/
int main()
{

  
	int t ; cin >> t ;
	

	for(int i_ =0 ; i_ < t ; i_++ ){
	int n ;
	cin >> n ;

  char arr[2*n][2*n] ;

	bool f =1 ;
  
	for(int j =0 ; j < n ; j+=2 ){
      
	  for(int  i =0 ; i < n ;i+=2 ){
		  if(f){
			  arr[j][i] = '#' ; arr[j][i+1] = '#' ; arr[j+1][i] = '#' ; arr[j+1][i+1] = '#' ;
		  }
		  else {
			  arr[j][i] = '.' ; arr[j][i+1] = '.' ; arr[j+1][i] = '.' ; arr[j+1][i+1] = '.' ;
		  }
		  f = !(f) ;
	  }

	  
	}

   for(int j= 0 ; j < 2*n ; j++){
		  for(int i =0 ; i < 2*n ; i++ ){
			  cout << arr[j][i]  ;
		  }
		  cout << endl ;
	  }
cout << endl ;

	}
  
  return 0;
}
// PS  - We are using INT_MAX -1 as infinity and NOT INT_MAX , so that the value if incread by 1 in some dp[i][j] , the value does NOT go
// out of the bounds of int , i.e. -  1 + (INT_MAX -1 ) = INT_MAX <  (int) .