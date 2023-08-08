#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// IMPORTANT - An actvity whos start time== end time , is NOT a VALID ACTVITY  , so DO NOT include such actvities in your answer .

// GREEDY ALGO. - select the approach that is best suited at that time .
// think naturally , in real life irresepctive of start time initially , if we end an actvity sooner (less end time) , we can do MORE actvities .
// given actvities with start and end time , find amax. no. pf activities that can be done by a person .

// Approach - (DO NOT take activities with smallest durations in ascending order . ITS WRONG because - if we do so, it will lead to 
// actvities being overlapped i.e. two activities might occur at same tiem which we could have done at different times and inc. our answr.)


// GREEDY ALGO. approach - Sort the ending time array in ascending order (so earlier actvities come initially .)
// Initially choose the actvity which has the least ending time (optimally best as ow , we can choose other actvity easily without any 
//overlapping). and now in every step , take the best step , to choose the actvvity whose start time is Greater than/ equal to previous 
// start time (remeber , all this time , the s,e yime are sorted based on ending time only)

// e.g.-  start[] = {2,4, 6}  , end[] = {11 , 5 , 7}

// after sorting based on end tiem , the net array = {(4,5) , (6,7) , (2,11)}
// Answer  - s1 = 4 , e1 = 5 (first actvity)

// in loop , check each time , if (curr_first >= old_end) {choos it and curr_first updated and curr_end updated} else continue ;

// satic bool functions() can ONLY be used when their classes / instances (objects) are called .


// to sort the actvities acc. to their ending time and if ending time same , sort based on start time .
static bool sort_end(pair<int,int> p1 , pair<int,int> p2){
        
       if(p1.second==p2.second) return p2.first > p1.first ;
         return p1.second < p2.second ;
    }


// select all valid activities ONLY .

    int activitySelection(vector<int> start, vector<int> end, int n)
    {
       vector<pair<int,int>> p;
       
       for(int j=0;j<n;j++){
           p.push_back({start[j] , end[j]});
           
       }
       
       sort( p.begin() , p.end() , sort_end) ;
       
       int s = p[0].first ;
       int e = p[0].second ;
       int ans =1 ;

       for(int j=1;j<n;j++){
           
           if(p[j].first>e){
               ans++;
              s= p[j].first;
               e = p[j].second;
           }
          
       }
       
       return ans ;
       
    }

// IMPORTANT - to sort any data structre

// sort(ds_start , ds_end , cmp);

// ds_start = iterator for starting of ds
// ds_end = iterator for ending of ds 
// cmp = comparison function.
int main(){

vector <int> start = {2,4, 6};
vector<int> end = {11,5,7} ;

int ans = activitySelection(start , end , 3);

cout << ans << endl;



    return  0;
}

