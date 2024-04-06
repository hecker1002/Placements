#include <iostream> 
#include <stack>
#include <vector>
#include <queue> 


const int M  = 1e9 + 7 ;

using namespace std ;


/*

Topological Sort - it is defined ONLY for DAG ( Directed Acyclic Graph ) 
Its a linear ordering of DAG nodes where if an edge is from u to v , u always appear before v in that linear ordering 
( shows traversal in graph )


Kanhs Algo - Topological Sort of a Graph -> using modified BFS using
In-edge array of each node, keep on pushing nodes with indegree = 0 until completed 

 */


vector<int> topoSort_Kanhs(int V , vector<int> adj[]) {
// finding indegree for each node 
// u-->v , then indegree[v]++ 

vector<int> indegree(V , 0 ) ;
for(int j =0 ; j < V ; j++ ){
    for (auto it : adj[j])
    indegree[it]++ ;
}

vector<int> topo ;
queue<int> q ;

// travel in queue (whi;le queue is NOT empty ) 
// and pop from queue its front-most ele and push in my vector ans. 
// now, travel to all its adjacent directed edged nodes and assume their aprent node is removed 
// so for all these children , reduce their indegree bt -=1 and if any one's children indegre=0 
// push it to top of queue 

for(int j =0 ; j < V ; j++ ){
    if(indegree[j]==0) q.push(j) ;
}

while( !q.empty()) {
    int inedge_0_node = q.front() ;
    q.pop() ;
    
    topo.push_back(inedge_0_node) ;
    // reduce indegre of all its children by -1 

    for( auto it : adj[inedge_0_node]){
        indegree[it]-- ;

        if(indegree[it] == 0 ){
            q.push(it) ;
        }
    }
}



return topo ;
}

/*

Problem - Given an alien dict following diiferent Alphabetic Rules , 
We are given an alphabetically sorted words of a dictionary ,  and based on it , we need to find alphabetical order of characters acco
to it . How ?? -> sort the words and if 'b' appears before'a' according to the order , then 
there is an edge from 'b' to 'a' and make a Directed graph acc. to it .  and do the Topo Sort . 

*/

// dict = array of strings , N  =  no  of words , K = no of alphabets used 
string findOrder( string dict[], int N, int K){

vector<int> adj[K]  ; // adjacency list of integers corresponding to those chars 

for(int i =0 ; i < N-1 ; i++ ){
    string s1 = dict[i] ;
    string s2 = dict[i+1] ;

    // find the first letter diffferent in them thats causing alphabetical order 

    for (int j= 0 ;  j < min(s1.size() , s2.size() ); j++ ){
        if(s1[j]!=s2[j]){  adj[s1[j]- 'a'].push_back(s2[j] - 'a'); break; } // making the directed graph from the alphabetical order of letters 
    }
}

vector<int> order = topoSort_Kanhs(K , adj ) ;

string ans = "" ;

for(int j= 0; j < order.size() ; j++ ){
    ans += order[j] + 'a' ;
}

return ans ;
}

/*

edge cases where it mihght fail -  if longer string before smaller 
OR cyclic dependency starts forming in the formed Directed Graph ( abc , bac , anm)
*/

int main() {
  
  int N , k ;

  cin >> N >> k ;
string dict[N] ;


  for(int j =0 ; j < N ; j++ ){
   string in ; 
   cin >> in ; 
   dict[j] = in ;

  }

 string ans  = findOrder(dict , N , k ) ;

  cout << ans << endl ;
    return 0 ;

}