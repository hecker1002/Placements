#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// here s = current source of a disk ( where it is currently resting )
// here d = final destination of disk (where it wil  finally rest ) and 
// these s , d , h rods are NOT absolute but relative(tentative) terms  .


void solve_tower(int n , char s , char d , char h){

// BC
if(n==1){
    cout << "moving plate" <<  1 << "from " << s << " to " <<  d << endl ;
    return ;
}

// hypothesis
solve_tower(n-1 , s , h , d) ; // helper = destination for now 

cout << "moving plate " <<  n << " from " << s << " to  " <<  d << endl ;

//induction
solve_tower(n-1 , h , d , s) ; // source = helper now 


}


int main(){

char source = 's';
char helper = 'h';
char destination = 'd';

solve_tower(2,source ,  destination , helper);

    return  0;
}
