#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// generate all possible combinations of uppercase and lowercase letters of same string .
// ab -> ab , aB , Ab , AB



// draw recursive tree (since we have some choices and decisions )


void permutation_with_case_change(string ip , string op){

// BC // smallest valid ip
if(ip.length()==0){
    cout << op << endl;
return ;
}

// Induction for 1 node of recursive tree

// copy output of previous node .
string op1 = op;
string op2 = op ;

// take a decision of capitalizaing or NOT the first char of my current ip .

op1.push_back(ip[0]);
op2.push_back(toupper(ip[0]));


// now remove the processed aprt of input on which decision is already taken -> string.erase(string.begin() + i) removes char at index =i 
ip.erase(ip.begin() + 0);

// use recursive calls for each of children node (= no of new output for curr node)
permutation_with_case_change(ip , op1);
permutation_with_case_change(ip , op2);

}


int main(){

string ans ="ab";

permutation_with_case_change(ans , "");


    return  0;
}
