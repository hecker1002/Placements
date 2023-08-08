#include <bits/stdc++.h>
using namespace std;



void insert (stack<int> &st1 , int ele2){

// even if 1 element left in stack , Comparison needs to be done (NOT a Base Condition )
if(st1.size()==0|| ele2>= st1.top()){
    st1.push(ele2);
    return;
}
    int ele1 = st1.top();
    st1.pop();

    insert(st1 , ele2);
    st1.push(ele1);
}

void sort_stack(stack<int> &st){

if(st.size()==1){

    return;
}
int ele = st.top();
st.pop();

sort_stack(st);
insert(st , ele);
}


int main(){

  stack <int> st ;
  st.push(5);
  st.push(2);
  st.push(0);
  st.push(1);

sort_stack(st );

while(!st.empty()){
    cout << st.top() <<" ";
st.pop();
}

    return  0;
}
