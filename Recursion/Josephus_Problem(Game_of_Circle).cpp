#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// Josephus Problem - 'n' people standing in a circle and everytime 'k' th person from a particular pos is shot and counting re-starts .
// Find the last person standing (everytime a  person is left alive by position ) 

// Use IBH method since straight-forward recursive ques , we are doing same thing.


void solve(vector<int> &v , int index , int k){



// BC ( if only person left alive)

if(v.size()==1){
   cout << v[0] << endl;
    return ;
}
// Induction - shoot k th person from current index 

index = index + k-1;
// since they are in circle and we are in array so use mod (%)  to generate same env .

index = (index % v.size());

v.erase(v.begin() + index);
// remove kth person
// Hypothess for any n peopel , it returns a list of lalive peoplea fter shooting k th person

solve( v ,index  , k);


}


// CALLING FUNCTION 

void Circle(int n , int k ){
    vector<int> v;
    for(int j=1;j<=n;j++){
        v.push_back(j);

    }


      solve( v , 0 , k);

}


int main(){

Circle(40 , 7);


return  0;
}
