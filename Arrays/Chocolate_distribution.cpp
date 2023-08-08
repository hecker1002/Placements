#include <bits/stdc++.h>
using namespace std;
#define ll long long int 


// Sliding Window Algorithm 

int distribute (vector<int> &v , int m ){

    int s = 0;
    int e = m-1 ;
    int ans = INT_MAX;
   sort(v.begin() , v.end()) ;

    while(e < v.size()){
      

        ans = min(ans , v[e]- v[s]);
        s++; e++;
    }
    return ans ;
}


int main(){


vector<int> v = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
int m  =7 ;

cout << distribute(v, m );









    return  0;
}
