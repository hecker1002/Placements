#include <bits/stdc++.h>
using namespace std ;

// given a queue data structre (FIFO) insertion ONLY from 1 end and deletion ONLY from one end , reverse a Queue 
// in ueue , there are ONLY front and back , NOT top / bottom

// Queue oeprations -> queue<int> q , q.push(ele) , q.front() , q.back() , q.size() , q.empty() , q.pop()
// using recursion , IBH

void rev_queue(queue<int> &q){
    //BC if 0 ele in q , do nothing 
    if(q.empty()){
        return ;
    }

    //Induction(n = size of q) - remove the front ele of q and reverse the rest of q
    int ele = q.front();
    q.pop() ; // REMOVES ele from front , q.pop()
   
   // Hypo - reverse n-1 elements
    
    rev_queue(q) ;

    // insert the removed lee at front
    q.push(ele);
}
int main() {
  
  queue<int> q ;
 
 int t=1 ;

 while(t<5){
    q.push(t) ;
    t++;
 }
  rev_queue(q) ;

  while(!q.empty()){
    cout << q.front() <<" " ;
    q.pop() ;
  }
  cout << endl ;
    return 0 ;
}