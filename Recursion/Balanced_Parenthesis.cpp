#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// given integer n -> 'n' open and 'n' closed brackets  and generate all possible combination that are balanced parenthesis .
// by recursion

// we have 2*n boxes , where choice at each box is ( or ) but we cant choose anything without a rule .


// IMP. RECURSIVE FUNCTION S

void solve(int open , int close , string op , vector<string> &ans){

// BC ( when open and close both used up)

if(open==0 && close==0){
   ans.push_back(op);
    return ;
}

// hypothesis - it works for any node 

// induction step for each node - wether we can choose '(' or ')'.

string op1 = op ;
string op2 = op ;

// decision -1 
// choosing ( at a  box
if(open>0){


// recursive call for this decision's child node 
solve(open-1  , close , op1+'(' , ans);
 
}

// decision - 2
// choosing ) at a  box
if(open < close){ // more open used so it needs to be closed by )



// recursive call for this decision's child node 
solve(open  , close-1 , op2+')' , ans);
 
}




}




// CALLING FUNCTION 
vector<string>  generate_balanced_parenthesis(int n){

int open = n;
int close = n ;
string op = "";
vector<string> ans ;

// recursive function

solve(open , close , op , ans);

return ans ;

}





int main(){

vector<string> ans = generate_balanced_parenthesis(3);

for(int j=0;j<ans.size();j++){


cout << ans[j] << endl ;
}
 
    return  0;
}


// pass by name != pass by refernce 