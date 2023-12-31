#include <bits/stdc++.h>
using namespace std ;


// node - data sapce in memory - 1 unit of BT 
struct node {

int data ; 
struct node* left , *right ;

// constructor - when  [new node()] is initialized .
 
node (int val ){
    data = val ;
   left = NULL ; right = NULL ; // simply access it inside declaration of class as left , right 
}


};

/*

BFS (Breadth First Search) - Level Order Traversal 
-  travel each level of a BT from Left to Right and advance to Next Level .

// Code - 

make a Queue (FIFO)  that stores curr level nodes . Store its size and travel through each of nodes in curr. state of queue 
and push its children at top and when that old size based traversal is complete , means , 
we have travel ONE level of BT and now , push this ( vector<node>level )  into ANOTHER vector , responsible for STORING
ALL THE LEVELS .

*/

vector<vector<int>>  BFS( struct node* root){
   
   
    queue< node*> q ;

    vector<vector<int>> v ;

    // by default , root is ALWAYS present in queue for BFS 
    q.push(root) ;

    while(!q.empty()){
        int sz = q.size() ; // current size of queue 
        vector<int> level ;
        for(int i=0 ; i<q.size() ; i++){
            // push all children of nodes in curr state of queue 
            struct node* curr = q.front() ;
            q.pop() ;

            if(curr->left != NULL) q.push(curr->left) ;
            if(curr->right != NULL) q.push(curr->right) ;

            level.push_back(curr->data) ; 

            // for 1 node , all its child is pushed in queue 
        }
        v.push_back(level) ;

        // after q.size() number of itr. , we have traversed 1 full level 

    }
    return v ;
}




int main() {

// new node(1) = initlaizes a node in memory ar random position but BT structre automatically gives its a storage a heirrachivhal fashion .
struct node * root = new node(1) ;

root->left = new node(2) ;
root->right = new node(3) ;

root->left->right = new node(4) ;

root->right->left = new node(5) ;
root->right->right = new node(6);


/*
Our Tree above 

     1
   /   \
 2      3
 \     / \
  4   5   6
*/

vector<vector<int>>  ans = BFS(root) ;

for(int i=0;i<ans.size() ; i++){
    for(int j=0;j<ans[0].size() ; j++) cout << ans[i][j] <<" " ;
    cout << endl ;  // solution  (1) (2 3) (4 5 6)
}
return 0;
}
