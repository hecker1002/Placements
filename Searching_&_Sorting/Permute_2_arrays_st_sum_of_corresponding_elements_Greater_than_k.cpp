#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// sort() -> TC = O (n log n) 
// n log n > n 


// given two arrays a and b , is it possible for each pair to folow -> a[i]+ b[i] >= k
// Logic - Yes , if 1 array sorted in Inc. order and Other sorrted in Dec. order and this relation if violated for any pair of its correspon
// nding elements , then No , otherwise Yes 

// as a[i]+b[i] in sorted >= sum of smallest and <= sum of largest elemnts in array . and still if condic=tion vioalted , then anyhow No 
// ONLY possible ans .

bool permut_possible ( vector<int> v1 , vector<int> v2 , int k){
    bool flag =1 ;

    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());

    int j=0;
    while(j<v1.size()){

        if(v1[j] + v2[j] < k) {flag =0 ; break;}
        j++;
    }

    return flag ;
}


int main(){
  vector<int> a = {1,4,6};
  vector<int> b = {5,1,7};
  
  bool ans = permut_possible( a, b , 1);
  
  if(ans) cout <<"yes , possible";
  else cout <<"no" << endl; 

    return  0;
}
