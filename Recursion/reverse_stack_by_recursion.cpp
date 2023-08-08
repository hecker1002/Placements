#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

void insert_at_back(stack<int> &s , int ele1 ){
// BC
if(s.size()==0){
    s.push(ele1);
    return ;
}

// hypothesis
int temp = s.top();
s.pop();

// induction 
insert_at_back(s , ele1);
s.push(temp);



}


void reverse_stack(stack<int> &st ){

if(st.size()==1){
    return ;
}
// hypothesis
int ele= st.top();
st.pop();

reverse_stack(st) ;
//induction
insert_at_back( st , ele );



}



int main(){


stack <int> st ;
  st.push(5);
  st.push(2);
  st.push(0);
  st.push(1);

stack <int> st1 = st ;
cout << "before reversal\n ";

while(!st.empty()){
    cout << st.top() <<" ";
st.pop();
}

reverse_stack(st1);

cout << "\nafter  reversal\n ";

while(!st1.empty()){
    cout << st1.top() <<" ";
st1.pop();
}








    return  0;
}
