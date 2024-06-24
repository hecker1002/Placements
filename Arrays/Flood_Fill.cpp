
#include <bits/stdc++.h>
using namespace std ;

/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

*/
int trap(vector<int>& height) {
    
        // Logic - Since smaller height decides water level , 
        // Use smaller height ALWAYS 

        // Logic - the 2 pointers are compared ( wrt leftmost smallest building
        // till now , left with leftmax and right with rightmax )
        // and when curr height is smaller , then we see trapped water else 
        // ONLY update hihest height till now to curr index (here , the rainwater 
        // trapped before it will already be cal since there curr height =0 )
        // < left max , so left max -0  will had been added to ans 
       
       int n = height.size() ;
       int l =0  , r = n-1 ;
       int ans  =0 , maxLeft = 0 , maxRight =0 ;

        while ( l <= r ){

            // work only with samller heighst (deciding factors )

          if ( height[l] <= height[r]){
            
            // check if curr height is smaller than largets building onLeft till nOw or NOT 

            // YES - find stored water 
            // we are NOT adding height[l] BUT max_left - height[l] to 
            // accomodate for greater buildings in right 
            // same for right case 


            // ALso , wrt that index , it shows how much water over that block is stored  OVER that block .
            if ( height[l] < maxLeft) {
              ans += maxLeft - height[l] ;
            }

            // NO 
            else { maxLeft = height[l] ; }

            l++ ;
          }

         else {

            if ( height[r] < maxRight ) { ans += maxRight - height[r] ; }
            else { maxRight  = height[r] ;  }

            r-- ;
         }

        }
      
        return ans ;
    }


    int main() {




    }