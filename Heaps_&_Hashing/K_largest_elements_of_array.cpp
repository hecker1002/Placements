#include <bits/stdc++.h>
using namespace std ;

/*

given an arr[] , find the K (given) largest elements of array 

Logic - min heap 

*/

void k_largest (int arr[] , int n , int k){

    priority_queue<int , vector<int> , greater<int>> min_h ;

    for(int i=0;i<n;i++){
        
        min_h.push(arr[i]);

        if(min_h.size() > k){
            min_h.pop();
        }
    } 

    while(!min_h.empty()){
        cout << min_h.top() << endl;

        min_h.pop() ;
    }
}

// Time complexity - O ( N * log K) since insertion in min heap requires log(K) time among  k elelemnts  , and n times outer loop runs .
int main(){

int arr[5] = {34 , 1, 23 , 12 , 6};
k_largest(arr ,5 , 3) ;


return 0;

}