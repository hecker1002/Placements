#include<bits/stdc++.h>
using namespace std ;
const long long int M = 1e9 + 7 ;


using namespace std ;

 void dfs1( int node , vector<int> &vis1 ,vector<vector<int>>&adj ,
        stack<int>&st){
            
            vis1[node]= 1 ;
            
            for( auto it : adj[node]){
                if(!vis1[it]){
                    dfs1( it , vis1 , adj , st ) ;
                }
            }
            
            // after dfs of a node (recursive soln)
            // push aprent ele (first ele to  occur in sorted finishing time)
            
            st.push( node) ;
        }
        
        
        // simple dfs 
        
        void dfs2( int node , vector<int> &vis1 ,vector<int> adj[] ){
            
            vis1[node]= 1 ;
            
            for( auto it : adj[node]){
                if(!vis1[it]){
                    dfs2( it , vis1 , adj  ) ;
                }
            }
            
        }
        
        
	public:
	
	// LOGIC - To find SCC( strongly connected comp.) in graph ,if we reverse the edges 
	// then reacheble nodes in Sub-part of graph iss till reachble(form SCC)
	// but the individul SC will be disconected and ditinct and 
	// run a dfs sol on each unvisited node 
	// BEfore this , sort the nodes base on finishing time , otherwise if some node like 0 
	//does NOT lie in SCCC1 and we strat our trvversal alwayds from it , we will 
	// lose some solutions OR get wrong ans .
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // sort nodes(0 base indexing ) based on finishing time 
        // and stoe in stack( later used for correct dfs tresal in distinct SCC)
        
        vector<int> vis1 ( V , 0) ;
        stack<int> st ;
        
        // sorting in finishing time 
        for(int j=0 ; j < V ;j++ ){
            if(!vis1[j]){
                dfs1( j , vis1 , adj , st ) ;
            }
        }
        
        
        // reverse the edges ( transpose of adj matrix)
        
        vector<int> adj2[V] ; // transpose matrix
        vector<int> vis2(V , 0) ;
        
      for ( int i =0 ; i < V ; i++){
          for ( auto it : adj[i]){
              adj2[it].push_back(i) ; // reversing the nodes 
          }
      }
        
        // travelloing in order of finishing time , 
        // calling dfs for each node 
        // and now dfs will travael only in a single SCC 
        // and then  approach another SCC 
        
        int scc=0 ;
        
        while(!st.empty()) {
            int node = st.top() ;
            st.pop() ; 
            
            if(!vis2[node]){
               
            dfs2( node , vis2 , adj2 ) ;
             scc++ ;
            
            }
        }
        
        return scc ;
        
        
int main() {

    int V , E ;
    cin >> V  >> E ;
    
    vector<int> adj[V] ;
    for (int j =0 ; j < E ; j++ ){

        int u , v  ;
        cin >> u >> v ;

        adj[u].push_back(v) ;
        // since directed graph , edge only form u to v , NOT from v to u . 

    }

    if(isCyclic(V , adj )) cout << "Cyclic " << endl ;
    else cout << "Not Cyclic " << endl  ;

    return 0 ;
}
        