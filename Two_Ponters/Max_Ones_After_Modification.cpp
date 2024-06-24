
#include <bits/stdc++.h> 
using namespace std  ; 

int solve(vector<int> &arr, int B) {
  
  // max ones after modification 
  // one pointer to show curr index we are at 
  // other pointer to unflip prev 0s and flip new 0 ( at curr index ) and find 
  // if this new subsegment of 1 length is more than previous found some length . 
  
  // logc - if we want to put some new thing in our already filled bag , 
  // we need to remove previously kept ele in bag 
  
  // 2 pointers 
  int curr  = 0 ; 
  int unflip_prev =0 ; 
  int n = arr.size() ;
  
  int flips  =0 ; // flips till now 
  
  int len =0 ;
  while ( curr < n ) {
      
      // check if we get 0 , then unflip it to 1 and check max subsegment of 1 length now
      if( arr[curr] == 0 ) { 
          flips++ ;
      } 
      // but before this , make sure you do NOT exceed max unflip constraint 
      // by moving the other pointer forward and unflipping the prev 0 
      // and stop when flips < max_flips_allowed 
      while ( flips > B ){
          if ( arr[unflip_prev] ==0 ){
          flips-- ;
          
        } 
        unflip_prev++ ; // after flipping , move the other pointer forward 
          //to search for more unflipping
      }
      
      // now we have unflipped max prev 0 required and flipped new 0 
      // now , in this new case , find max subsegemnt of 1 
      
      len = max ( len , curr - unflip_prev + 1 ) ; // from l to r , length is r-l+1 
      
      curr++ ;
      
  }
  
  return len ; 
}


int main() {

  vector<int> arr = { 1 , 0 , 0  , 1 } ;
  int B  =  1 ; 

  cout << solve( arr , B ) << endl ;
    return  0 ;
}