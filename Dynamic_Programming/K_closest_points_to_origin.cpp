#include <bits/stdc++.h>
using namespace std;
#define ll long long int 


/*

given a collection of orered pair of coordinates (x,y) , find the 'K' closest points to the origin .

logic - distance of x,y from origin = root(x*x + y*y) and since root(x*x + y*y) ~ x*x + y*y , hence , we store 
this distance as a pair with its respective corrdinates  ( dist , (x,y)) in a MAX_HEAP (topmost element curr max of heap )


Now ,keep on calculating dotance from orgin and push in amx heapand whenever no of element in heap > K , remove the top most elemen
it is a very clever trick as now we know that if we get even k+1 elements , 
the top most elemnrt is farthest from origin and not in first K closest points /element s.

*/

//n = no of ordered pairs given - (x,y)
//input - 2D array of (x,y ) x= arr[i][0] and y =arr[i][1]


// IMPORTANT - TRY TO ACCESS POINTS X,Y CORRESPONDING TO THE DISTANCE by - storing the second element (pair) of top most eleemtn in
// another pair  p and then only access p.first and p.second for corresponding closest (x,y) coordinates .

void K_closest_to_origin(int arr[][2] , int n  , int k ){

    // initialize a max heap (by priority queue)

    priority_queue<pair<int , pair<int,int>>> max_h ;

    for(int i=0;i<n;i++){

        max_h.push({arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1] , {arr[i][0] , arr[i][1]}});

        // if size of maxheap exceeds k , remove top most (garbage value) as now , we have got our k closest points from bottom of ma heap

        if(max_h.size()>k){

            max_h.pop();

        }

    }

    // print the points 

    while(!max_h.empty()){
        pair<int,int> p  = max_h.top().second;

        cout << p.first << " " << p.second << endl ;
        max_h.pop();


    }

}

int main(){



int arr[5][2] = {
    {0, -1} ,
    {4, 7} , 
    {9,1},
    {2,2}
};

K_closest_to_origin(arr , 4 , 2);



    return  0;
}

