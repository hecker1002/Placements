#include <bits/stdc++.h>
using namespace std;

// IBH -  Induction  - base cond. - hypothesis
void insert(vector<int> &v , int ele ){

//BC
if(v.size()==0 || ele >= v[v.size()-1] ){
    v.push_back(ele);
    return;
}
// hypo
int ele1 = v[v.size()-1];
v.pop_back();
// induction 
insert( v , ele);
v.push_back(ele1);
}


// IBH -  Induction  - base cond - hypothesis

void sort_using_recursion(vector <int> &v  ){

// BC
if(v.size()==1){
    return ;
}
int ele = v[v.size()-1];

// Hypothesis
v.pop_back();
sort_using_recursion(v);

// induction 
insert(v , ele);


}


int main(){


vector <int> v{2 , 5 , 0  , 56, 1};

sort_using_recursion(v);

for(int j=0;j<v.size();j++){
    cout << v[j] <<" ";
}
    return  0;
}
