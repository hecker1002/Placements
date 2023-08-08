#include <bits/stdc++.h>
using namespace std ;

/*

given an int arr[]  which is SORTED , find the index of an element given by user if it is present in the sorted array else return -1 .

Logic -  Use BS (Binary Search) since the array is sorted and break the searching space in half each time and compare middle-most element 
with the ele to be searched for .


*/

// start , end , mid = store indexes , NOT the actual element of the array .

//This is a General Binary Function which goes on breaking the searching space in array in half , and searches for an element 
// and if found , it returns the index of that element .

// "=" sign in start <= end very important as it is the smallest cae , when only 1 element left in searching space , start = end = [1 element] (like a B.C. )
int binary_search(int arr[] , int n , int start , int end ,int ele){

// calculate mid index in each iteration after breaking the searching space in half 

while(start <= end ){
    
    int mid = start + (end - start) / 2 ; // to prevent overflows in integer .

    // break the searching space in 3 parts (mid , < mid , > mid ) and compare 'ele' with mid , if found stop and return the index else 
    // break the searching space in half again 

    if( ele == arr[mid]) {
        return mid ;

    }

    else if( ele < arr[mid]){
        
        end = mid -1 ; // since , we already checked if middlemost element of array is equal to ele or not . , now search in first searching space.
    }

    else if (ele > arr[mid] ){

        start = mid + 1 ;// since , we already checked if middlemost element of array is equal to ele or not  , now search in second searching space 
    }



}

// reeturn -1 outside of loop 
return -1 ; // if no return value even when start = end ( means only 1 element left in the array ) and still ele not found , it means 
// ele is NOT present in the given array 


}

// return statement is like a break; statement .

int main(){
   // keep the array sorted 
  int arr[5] = {3 , 5, 10 , 17 ,34} ;
  
  // foloow 0-base indexing

// initializing the start and end index at ends of initial searching space 
  int start = 0  , end = 4;

  // calling the function and returning thre index of the element 
  int index = binary_search( arr , 5 , start , end , 5) ;

  cout << "from binary seach , the Index of 5 is " << index << endl ; // corrrect answer =  1

    return 0 ;
}