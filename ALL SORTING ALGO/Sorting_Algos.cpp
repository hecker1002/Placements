#include <bits/stdc++.h>
using namespace std  ; 

/*
BUbble Sort Algo . - Bubble Up the LArgets Bubble( in terms of VOl) - LArgets ele to Top .
at any stage , (smaller subproblem)if prev>next , swap(prev , next)
Len of Unorte dpart of arr- decreases in every itr . 
*/

void Bubble_Sort( vector<int> &nums ){

int n = nums.size() ;

for(int j =0 ; j <n  ;j++ ){
 // to sort n ele by bubble sort, requires n-1 irtr(since last ele autmatically goes to
 // In firdt itr , UNSORRTED- n , IN 2nd itr-Le(UNSORTED)-n-1
 // itr - 0 base indexing  t is t-1
 for(int i =0 ; i<=(n-j-1) ; i++ ){

    if( nums[i] > nums[i+1]) swap( nums[i] , nums[i+1]) ;

 }
}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

SELECTION SORT ALGO  - From the Unorted part , Pick the MIn . Most ele , and swap it first first ele of Unsorted aprt
ie send it to front of unsorted aprt and then contnue ; 

*/

void Selection_Sort( vector<int> &nums ){
    int n = nums.size() ;

    for (int j =0 ; j< n ;j++ ){
        //n-1 itr 
        int minm = j  ;
        // no of ele in unsorte daprt = n-j BUT we are changing FROMNT ( that why starting from updated i )
        // BUT will go back till n-1 index 
        for(int i = j+1 ; i <n ; i++ ){
            if( nums[i] < nums[minm]){
                // update min ele of unsorted part  (store index )
                minm = i ;
            }
        }

        //Now send min ele to front of unsorte dpart 
        swap( nums[j] , nums[minm ]) ; // Does nOT matter where we swap the first ele (since whole of that aprt is Unsorted till now
        // and going to be sorted in future  .)
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
Insertion Sort ALgo 
= Maintaijn2 APrts inSame Arrya ( Sorted and Unsorted )

travel through eevry ele of unsorted part (in each itr ) and pale it in correct Pos in Sorted aprt and shift req ele to the right 

*/

void Insertion_Sort( vector<int> &nums ){
int n = nums.size() ;
// 1 ele -ai t =0  is Sorted always 

// Unsorted aprt start from j 

// WE are placin g FIRST ele of UNSORTED APRT (in correct pos in SORTED APRT )
for ( int j =1 ; j< n ;j++ ){

int curr = nums[j] ; // index of curr ele sicene might be lost during shifting so store it 
int insert_index = j ;

// search for its correct pos in sorte dpart 
for( int i = j-1; i>=0 ;i-- ){
    // comparing in rev order (and shiftin g is psosible and easier )

    // incorrect pso -shift 
    if( nums[i]> curr ){
        nums[i+1] = nums[i] ;
       
        // LAst i+1 NOT affect Since 
         insert_index = i ; // inde xthat becmae empty after shifting right 
    }
    else {
        // if corretc pos 
        break ;
    }
}

nums[insert_index] = curr ;
}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// void partition_sort (   int l , int r , vector<int> &nums ){
 
//  // partition starting  = l , 
//  // partition ending = right 
//  // pivot ele currently at last pos og array( partition )

//  // 2pointer approac 

//  int pivot = nums[r] ;

//  int biggest_from_left = nums[l] ;
//  int smallest_from_right = nums [r] ;

//  while( biggest_from_left <= smallest_from_right){

//     if(nums[biggest_from_left]>=pivot && nums[smallest_from_right]<=pivot ){
//         swap( biggest_from_left , smallest_from_right)  ;
//         biggest_from_left++ ;
//         smallest_from_right-- ;
//     }

//     else if(nums[biggest_from_left]>=pivot){
//         biggest_from_left++ ;
//     }

//     else if(nums[smallest_from_right]<=pivot){
//        smallest_from_right== ;
//     }

    
//  }

//  swap( pivot , biggest_from_left) ;
// }

// void Quick_Sort ( vector<int> &nums ){
//     int n = nums.size() ;
//     int pivot = (n-1)/2 ;

//     partition_sort( pivot , n-1 , nums   ) ;
//     partition_sort(  0 , pivot  , nums  ) ;

// }




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
MergeSort()  - assume it emrges left and right half so give it left and right half and it Sort them(in itself) Recursively .

merge_the_sorted() - Jsut to emrge 2 Lsit so that final araru=y is Sorted tigether

*/
vector<int> merge_the_sorted( vector<int> &nums1 , vector<int> &nums2  ){
  
  int i = 0 ; 
  int j = 0 ; // itr for elft and right arrays 
  
  vector<int> final ; 

  while( i<nums1.size()  && j<nums2.size() ){

    if( nums1[i]<=nums2[j]){
        final.push_back( nums1[i]) ;
        i++ ; // if ele of left arrya < right arrya , go on till left can have stiil msaller sele 

    }
    else {
         final.push_back( nums2[j]) ;
        j++ ;
    }
  }

  while(i<nums1.size() ){
     final.push_back( nums1[i]) ;
        i++ ;
  }

    while(j<nums2.size() ){
     final.push_back( nums2[j]) ;
        j++ ;
  }

  return final ;
}


vector<int> mergeSort( vector<int> &nums , int l , int r  ) // mergeSort(simple Sorting funcion )
{     int n = nums.size() ;

    if(l==r){
        return { nums[l]} ;
    }
    int mid = (l+r)/2 ;

    vector<int> nums1  = mergeSort (  nums , l , mid ) ; // to sort the arrya inirsllf ,use mergeSort 
    vector<int> nums2  = mergeSort ( nums , mid+1 , r  ) ;

   
    // left half and right HAlf ar eSOrtd IN THEMSLEVES 

    // so again merge and sort 

    vector<int> ans = merge_the_sorted( nums1 , nums2  ) ; // to merge the 2 lists in sorted final , USe merge()
   
   return ans ;
    
}






int main() {
vector<int> v = { 7 ,11 , 6 } ;

// Bubble_Sort( v ) ;
// Selection_Sort(v ) ;
// Insertion_Sort(v ) ;

// Quick_Sort( v ) ;

vector<int> v1 = mergeSort( v , 0 , v.size()-1) ;


for(int j= 0 ; j < v1.size() ; j++){
    cout << v1[j] << " " ;
}

    return 0 ;
}