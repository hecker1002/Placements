#include <bits/stdc++.h>
using namespace std;
#define ll long long int 


/*

given an array of rope length , find the minimum cost for connecting all the ropes (cost of rope = length ) and cost here => 
sum of cost after adding cost at each instant of joining

e.g. - arr[] = 1,2,3 , join 1 & 2 , cost = 3 , now join new 3 and old 3 , cost += 6 (cost = cost + 6) , so cost = 3 + 6.

Logic - Maintain a min heap (toopmost element ALWAYS show the current least elemnt of current stack / heap ) and add 2 topmost elements and pop them
and psh their sum back in heap .


// Implement min(extra params.) /max  heap by  - priority_queue<int> pq .

*/

// PS - passing an array to a function(by refernece) is like passing an int pointer (int *ptr)

int ropes_min_cost(int *arr, int n ){

    priority_queue<int , vector<int> , greater<int> > min_heap;
    int i =0 ;
  

  // pushing all element in min heap (priority queue in increasing order from top to bottom)
    while(i<n){
        min_heap.push(arr[i]);
        i++;
    }

  int cost =0 ;

  // do it only till you have 2 ropes at least 

  while(min_heap.size() >= 2){

// first smallest rope 
    int first = min_heap.top() ;
    min_heap.pop();

// second smallest rope
    int second = min_heap.top();
    min_heap.pop();
   

   cost = cost + first + second ;
   
// total cost of new rope  to be used agin (pushed in min heap )
   min_heap.push(first + second);



  }

  // final cost (optimally minimised)

  return cost ;

}



int main(){


int arr[5] = {1 , 2 , 3, 4, 5};

cout << ropes_min_cost(arr , 5) << endl ;


    return  0;
}

