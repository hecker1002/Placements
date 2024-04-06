#include<bits/stdc++.h>
using namespace std ; 

// const int M = 1e9+ 7 ;

/*

Given a pair of activities with pre-requisites like {0 , 1} where Task 0 has to be completed before Task 1 
then find is it possoble to complete all theTasks 

Logic - MAke a directed Graph using these node s(if Task u has to completed before v , then there's an edge from u to v )
and do zTopo Sort using BFS (Kanhs ALgo . ) and if it there exist no Cycle , then All tasks can be completed 
Since practically tasks have to be cpmpleted in Linear fashion 

*/

// N - no of tasks , P = no of pairss given , vector of pairs 
bool Task_Complete(int N , int P , vector<pair<int, int> >& prerequisites){

// form an adhancecy list for the Directed Graph 
vector<int> adj[N] ;

for( auto it : prerequisites){

int task1 = it.first ;  int task2 = it.second  ;
//task1 to be completed before task2 

adj[task1].push_back(task2) ;


}

// Topo Sort usin Kahns  BFS 

vector<int> topo ; 
queue<int> q ;

vector<int> indegree(N , 0 );

for(int j =0 ; j < N ; j++ ){
   for(auto it : adj[j]){
    indegree[it]++ ;
   }
}
for(int j =0 ; j < N ; j++ ){
    if(indegree[j]==0) q.push(j) ;
}

while(!q.empty()){
    int node = q.front() ; // this n ode has indegree 0 
    q.pop() ;
    topo.push_back(node) ;
    for(auto it : adj[node]){
        indegree[it]-- ;
        if(indegree[it]==0)q.push(it) ;
    }
}

if(topo.size()==N) return true ;// no cycle , all task complete 

return false ;

/*

TO get one of the ordering in which we can do the Tasks , Use Topological Sort 
*/
}


int main ( ) {

int V , E ;

  cin >> V >> E ;
vector< pair<int , int> > preq ;


  for(int j =0 ; j < E ; j++ ){
   int u , v ;
  preq.push_back({u , v}) ;

  }
  bool ans  = Task_Complete(V , 4 , preq) ;

 if(ans){
    cout << "YES" ;
 }
 else cout << "NO" ;


    return 0 ;
}