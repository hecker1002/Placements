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



int main(){



ll t;
cin >> t ;

ll M = 1e9 ;

for( ll y=0;y<t;y++) {
int  n , m , d ;

cin >>n >> m >> d ;

int a[m] ;
map <int , int > mp ;
for(int  j=0;j<m;j++){
    cin >> a[j] ;

    mp[a[j]]++ ;
}

int  mn = 0 ;

int  cookies = 0 , cok = 0  ;

map<int  , int > mp1 ;

for(int i=1 ; i<=n ; i++) {

    if(i==1 || mp[i]>=1 || mn>=d){
       // eat a cookie 
     cookies++ ;
      //cout << cookies ;
       mn=0 ;

     
     if(mn<d && i>1){
        cok = min(cookies-1 , cok ) ;
        if(mp[i]>0)mp1[i] = cok ;
     }
       
   }
    else {
        // not eat 
        mn++ ;

        if(mn>=d){
             // eat a cookie 
     cookies++ ;
      //cout << cookies ;
       mn=0 ;

     
     if(mn<d && i>1){
        cok = min(cookies-1 , cok ) ;
        if(mp[i]>0)mp1[i] = cok ;
     }
        }
    }

   
  
}

cout << cok << " " ;

// i = n ;

// ll ans = 0 , cok1 = INT_MAX ;

// while(i<= n ){

//     if( mp[i]>0){
//         // eat a cookie 
   
//         if(mp1[i]==cok) ans++ ;
  
// }
// i++ ;
// }
// cout << ans << endl ;



}







    return  0;
}

