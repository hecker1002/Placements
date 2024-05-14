#include <bits/stdc++.h>
using namespace std  ; 


const int M  = 1e7 + 3 ;

// Hint - Whenever there is an arrangement (optimal sol) , bring all the ele to the median position( len -1)/2 and
// do NOT worry about odd or even nu  of ele .

/*


There is a row of seats represented by string A. Assume that it contains N seats adjacent to each other. 
There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.

An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.

In one jump a person can move to the adjacent seat (if available).

NOTE:  1. Return your answer modulo 107 + 3.

*/


// Brute Force 

int Seats(string A) {
    
  /*
  Force all the people to form a segment at start from 0 . 
  Now , iterate CONTINUPUSLY over all segments possible and find min cost . 
  * By comparing current index of each person wrt segment's start point 
  */
  
  vector<int> pos ; 
  
  int cnt =0 ;
  for(int j =0 ; j < A.size() ; j++ ){
      //move them to index 0 together -> and calcualte cost and store it instead of actual index 
      
      
    if( A[j] == 'x') { pos.push_back( j - pos.size() ) ; }
    
  }
  
  int N = pos.size() ; // no of seated people 
  
//   for(int j =0 ; j < N ;j++ ){
//        //move them to index 0 together -> and calcualte cost and store it instead of actual index 
//       pos[j] = pos[j] - j  ;
      
//   }
  
  int ans = INT_MAX ; 
  // Now iterate over all segments 
  for(int i = 0 ; i < A.size() ;i++ ){
      int total =0 ;
      for(int j = 0 ; j < N ; j++){
          //  Find cost of moving each person to their curr index in the new segment 
          // Logic -> pos[j] permanetly stores now , cost of moving all ele(if seg starts from  0)
          // Now , every time the seg moves by 1 pos , 
          // New cost for each ele  = Cost of moving wrt 0 - curr seg start 
          // SInce , we are moving righteard And for mov toward 0 intially , we used left mov 
          //Now , since we are movingin opp direction , we actually (nearer to orig inddex)
          
          // so subtract from Original totla (wrt 0)  , curr starting point (++1) in each itr . 
          total += abs ( pos[j] -i  ) ;
          total %= M ;
      }
      ans = min(ans , total%M ) ;
  }
  
  return ans ;
  
}


// Optimized Approach -> Greddy 


const int M  = 1e7 + 3 ;

int seats_greddy(string A) {
    
  /*
  Move all  occupied indexes to median . 
  But Target is Not median , decide according to index of other ele 
  Intutu=ion -> min moves req 
  */
  
  //
  vector<int> pos ;
  for(int j =0 ; j < A.size() ; j++ ){
      if(A[j] =='x')
      pos.push_back(j) ;
  }
  
  int med = ( pos.size() - 1 )/2  ;// 0 base indexing 
  
  // if above fails 
  if(pos.size() == 1 || pos.size() ==0 ){
      return 0 ;
  }
  
  int total =0 , n = pos.size();
  for(int j =0 ; j < n ;j++ ){
      //e.g. - x.x.x...x , for leftmst index tararget =6  and NOT 5 , if med = 5 ,
      // (pos[med] - med)  this is constant quantity to be added to curr pos index to find target pos index
      // Why it works ?
      //since , (pos[med] - med)  is value by which med is greater than its index and this added to every index
      // shows the target index for that pos of x 
      
      int target = (pos[med] - med) + j  ;
      int curr = pos[j] ;
      
      total += abs( target  - curr ) ;
      total%=M ;
  }
  
  return total%M ;
  
  
}



int main() {


    return 0 ;
}