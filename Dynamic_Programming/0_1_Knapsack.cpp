#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// PS - in rec() , take (n) for doing induction =  no of elements in genral and (n-1) as ACTUAL last element .
// PS - In contest , if you want to do memoization but you have only access to object func. (outside main) , then make another function
// and copy all inputs from given (readymade funct) in this new one and declare a dp[][] with -1 and call new fiunction inside old one (
//   and write all your rec. code inside new func
//)



// Given a knapsack ( bag , max = W kg) and a list of items with wt[] and val[] array and we need to find maximum profit 
// we can make after choosing any item completely or NOT (0/1) .


// Solving Using DP approach (Dynamic Prog) since - CHOICES  given with item and optimal soln (MAX profit) asked .

/*

To  Solve any DP (Dynamic Programming ) Quesn - 
 1. Write Simple recursive code   2. Do memoization( make 2D matrix to counter overlapping subproblems or recalculation)
 3. OR do Top Down approach (iterative method to fill an empty 2D matrix)


1. Recursive code - Draw choice diag for some genral 'n' (based on diff. condition possible) and write its code

2. For Memoization , 
make a 2D matrix (of size n*m where n and m are arg. constantly changing in rec. calls-globally initialized with -1)
 and just after base condition add these 2 lines of code - if(dp[n][m]!=-1) return dp[n][m] else (put all rec calls values in dp[n][m])
  where n,m are given arg. of rec call


3. For Top Down approach ,  (IMPORTANT. replace n , m of memoiation with i,j in top-don)
- break into smaller sub-problems and solve .
 make a 2D EMPTY matrix of same size dp[n][m] and initialize using rec . code's base condition (i.e. if n==0 , all rows with i=0 will store 0)
- Here , just store values in respective cells of 2D matrix , no need to cross-checkif a cell is filled or not 

-and proof -  any cell i,j (n,m in dry run) dp[i][j] tells max. profit if we use (i) items and weight of knapsack is (j) kg.(sub-problem)
- hence for n items with weight of knapsack =W , find value in alst rightmost cell of amtrix - dp[n][W] (actual n and W) to get
required final answer = dp[n][W] in top -down approach .

- TRICK - replace (n,W with i,j and fill iteratively the matrix  and replace rec(n,W ) with dp[i][j] with same calcn. and condition)

*/


// Recursive Code (with memoization)

// 2D matrix of size n * W ( variable quantity)
int t[102][1002];

int knapsack(int wt[] , int val[] , int W , int n){

 // Base Condition(BC)

 if(n==0 || W==0){
    return 0;
 }

 // memoization
 if(t[n][W]!=-1){
    return t[n][W];
 }
 // Acc. to Choice Diagram - Under what conditions , what choices can be made .
  /*

  IMPORTANT - use arg. of rec function as current (any general val at any time)

    for last weight wt[n-1] we can include it in our knpsack or NOT (choice) and conditions (wt[n-1]<= W) i.e. weight of this item is less
    than current weight of knapsack

    choice diag . 

      wt[n-1]
    /        \
wt[n-1]<=W   wt[n-1> W]
/      \             \ 
include exclude       only exclude

so open the door , and call rec( ) function for both if val of (n-1) item included (val[n-1]+ rec(n-1 , W-wt[n-1]) or excluded rec(n-1 , W))
and return max. of these two. (under condition wt[n-1] <= W (curr. weight of knapsack))

or else always exclude it and open the door and return the max profit for rest (n-1) items without any weight change (since (n-1) item EXcluded)

 */


// Here , Do NOT think that max profit from (n-1) elements will return and adding val[n-1] is always profitable (WRONG CONCEPT)
// Since , it will defeat the purpose of choice diag , of choosing or not chossing an element for max. profit .

 if(wt[n-1] <= W){
    return t[n][W] = max(val[n-1] + knapsack(wt , val , W-wt[n-1] , n-1) , knapsack(wt , val , W , n-1));

 }

 else return t[n][W] = knapsack(wt , val , W , n-1);


}


// DP soln using 
// Top Down Approach( breaking big problem into sub-problems)

int dp[102][1002];

int Knapsack(int wt[] , int val[] , int W , int n){

   
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){

             // Initialization of 2D matrix (BC)

            if(i==0 || j==0) dp[i][j]= 0;
             

           
        }
    }


for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){

            // Choice Diag (replace rec(n,W) -> dp[n][W])


            if(wt[i-1]<= j){
       
          dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);

          }
    
            else dp[i][j] = dp[i-1][j];

        }
    }

    
    

    //Final Solution

    return dp[n][W];



}



int main(){

int W = 7 ;
memset(t , -1 , sizeof t);

int wt[5] = {1 , 3, 4 ,5 , 2};
int val[5] = { 1, 2 , 5 , 6, 2};
// Memoix=zation approach (DP)
int price = knapsack(wt , val ,W , 5);

// Top Down Approach (DP)
int Price = Knapsack(wt , val , W , 5);

cout << price << endl;

cout << Price << endl;

    return  0;
}

