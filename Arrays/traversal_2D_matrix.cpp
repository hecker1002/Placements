#include <bits/stdc++.h>
using namespace std ;
    


// Travel in a 2D matrix formed by vector of vectors A

// A -
// [[1,2],
//  [3,5]
// ]


// Treat vector of vectors also as  simple 2D array with i row and j column pre-defined .

// IMPORTANT 

// 2d ARRAY SAME AS = VECTOR<VECTOR<INT>> V
// Arrray[i][j] = V[i][j]


vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		
		vector<int> ans ;
		
		/// traversal wrt row 1 (first row )
		for(int j=0;j<N;j++){
		   int c =j;
		   int i = 0;
		   
		   while(i<N && c>=0){
		       ans.push_back(A[i][c]);
		       i++; c--;
		   }
		}
		
		
		  
		  if(N>=1){
		   
		   // traversal wrt last column (N-1)
		  for(int i=1;i<N;i++){
		      
		      int i1 = i;
		      int c1 =N-1;
		      while(i1<N){
		          ans.push_back(A[i1][c1]);
		          i1++; c1--;
		      }
		      
		  }
		
		
		  }
		return ans ;
	}


int main(){
vector<int> ans;
vector<vector<int>> A = {
    {1,2,4},
    {3,5,6},
    {3,4,8}
};

ans = downwardDiagonal(3,A);

for(auto i : ans) cout << i <<" ";
// cout << ans[0] << endl;
    return 0;

}


/// ANOTHER APPROACH 

// Use 2D array  and travel through wholel 2D matrix and Use ( ans[i+j].push_back(A[i][j])  ) => where vector<vector<int>> ans(n + m -1);