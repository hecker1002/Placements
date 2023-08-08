#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// actual function to delete  middle most element of stack 
void solve(stack<int> &st , int mid){

if( mid==st.size()){
    st.pop();
    return;
}



int ele = st.top();
st.pop();

solve(st , mid);
st.push(ele);
 
}

// function for just calling and checking 
stack<int> delete_mid(stack<int> &st  ){


if(st.size()==1){
   st.pop() ;
   return st;

}
int mid = (int)((st.size()/2) + 1) ;
solve(st , mid ) ;
return st ;

}




int main(){



 stack <int> st ;
  st.push(5);
  st.push(2);
  st.push(0);
  st.push(1);




stack<int> st1 = delete_mid(st) ;

while(!st.empty()){
    cout << st.top() <<" ";
st.pop();
}





    return  0;
}
