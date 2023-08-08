// TO geneare all the subsets of a given string (power Set )
// and indirectly , it will be same as generating all the subSequences of a given string

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 


void All_Subsequences( string s , int index=0 ,  string output = "" ){


// Base Cond.

if(index==s.size()){
    // output = empty

    cout << output << endl; 
    return ;
}


// Hypothesis
// Induction(2 ind, since we have 2 branches(choices).

// subsets you get when including s[index ]
All_Subsequences(s , index+1 ,output + s[index] ); // adding s[ind]

//// subsets you get when excluding s[index ]
All_Subsequences(s , index+1 ,output  );



    

}


int main(){

string s ="abc" , out="" ;

All_Subsequences(s ,0 ,out);



    return  0;
}
