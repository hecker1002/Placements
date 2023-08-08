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

/*
 Given a 2D matrix , travel it spirally and print all elelemnts 

 1 -> 2 -> 3
          |
9-> 10     4
|          |
8<-7 <-6<-5 


*/

  // Use 4 itr (top , bottom , left , right and update them after each round .)
  vector<int> spiral_Order(vector<vector<int>>& matrix) {
        // make 4 pointers named top , bottom , left and right and in a loop run all of them
        // and update all after 1 complete round .

        int top = 0 , bottom = matrix.size()-1 , left = 0 , right = matrix[0].size()-1;
         vector<int> ans ;
        while(top<=bottom && left<=right){
        
        // for 1 complete round 

         // in top row , travel left to right
        
         for(int j=left;j<=right;j++){ // no extra condtion since they are already true since they have been checked by main outer loop .
           ans.push_back(matrix[top][j]);
         }

         top++; // top travelled , now for new top , inc. by 1 

         // travel rightmost col , from top(new) to down

         for(int j=top;j<=bottom ;j++){
             ans.push_back(matrix[j][right]);
         }

         // right update
         right--;

         // travel bottom from right)new to left
        if(top<=bottom){ // this top<=bottom and left<=right added to accomodate chnages when bottom> right happens inside the loop itself (not sensed by loop) so to counter this condition
         for(int j=right;j>=left;j--){
              ans.push_back(matrix[bottom][j]);
         }
        }
         // bottom update
         bottom--;

         // travel left col, bottom to top.
         if(left<=right){  // this top<=bottom and left<=right added to accomodate chnages when bottom> right happens inside the loop itself (not sensed by loop) so to counter this condition
         for(int j=bottom;j>=top;j--){
             ans.push_back(matrix[j][left]);
         }
         }


         //left traversed , update

         left++;




        }
       // returns the order of elemnts in spiral traversal (as a vector .)
        return ans ;

    }
int main(){

 vector<vector<int>> v = { {1,2,3} , {4 , 5, 6} , {7 ,8 , 9}};
 vector<int> ans = spiral_Order(v);

 print_v(ans);




    return  0;
}

