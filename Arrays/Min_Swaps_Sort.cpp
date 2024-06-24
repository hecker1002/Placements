#include<bits/stdc++.h>
using namespace std ; 

bool foo ( pair < int , int> p1 , pair < int , int> p2 ){
      
      return p1.first < p2.first ;
  }
  
  int min_swaps_arr( vector<int> &v ){
      int n = v.size() ;
      
      // store pairs ( ele , curr index  of unsorted arrayy
      vector < pair < int , int > > arr ;
      for(int j =0 ; j < n ;j++ ){
          arr.push_back( { v[j] , j}) ;
      }
      
      sort( arr.begin() , arr.end() , foo ) ;
      
      // now given arr is sorted with their old indices
      // now , check if old index != corr sorted index
      //  swap the new ele with old inde x ele /
      // reverse , converting sorted array into given array 
      
      int cnt =0 ;
      for (int j= 0 ; j < n ;j++ ){
          if ( arr[j].second != j ){
            swap( arr[j] , arr[ arr[j].second]) ;
             cnt++ ;
             j-- ;
          }
      }
      
      return cnt  ;
  }


int main()  {

 vector<int> arr = { 1 , 5 , 4 , 3 , 2 }  ;

 cout << min_swaps_arr( arr) ;


return  0 ;
}