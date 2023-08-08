
#include <bits/stdc++.h>
using namespace std;
#define ll long long int



// Find if there exist any triplets (any three No.s in the array) whose sum = 0.

bool findTriplets(int arr[], int n)
    { 
        
        bool f= false;
       sort(arr ,arr+n) ;
       for(int j=0;j<n;j++){
           
           
           int t = -arr[j];
           int l=0 , r=n-1;
           
           if(t>=arr[j]) l=j+1;
           else r=j-1;
           while(l<r && l>=0 && r<n){
             
               if(arr[l]+arr[r]<t) l++;
               else if(arr[l]+arr[r]>t) r--;
               else {f=true ;break;}
           }
           
           if(f) {break;}
       }
       
       if(f) return 1;
       else return 0;
    }



int main(){

   int arr[5] = {1,0 , 3 , 1 , 2};
    cout << findTriplets(arr , 5);
    return 0;
}