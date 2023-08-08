#include <bits/stdc++.h>
using namespace std;


// iterative way , swapping i th element from start and i th element from end .
vector<int> reverse_the_array(vector<int> &v)
{

    int n = v.size();
    int s = 0, e = n - 1;

    while (s <= e)
    {

        swap(v[s], v[e]);
        s++;
        e--;
    }

    return v;
}

// recursive way 
void rec_Reverse_The_Array(vector <int> &v , int s , int e){

 if ( s>= e){
    return ;
 }

 swap (v[s] , v[e]);
 rec_Reverse_The_Array(v , s+1 , e-1);

}

int main()
{

    vector<int> v1 = {1, 2, 5, 3, 6};
    vector<int> v2 = {1, 2, 5, 3, 6};
    vector<int> ans = reverse_the_array(v1);
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    
  rec_Reverse_The_Array( v2, 0 , v2.size()-1);
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }

    return 0;
}