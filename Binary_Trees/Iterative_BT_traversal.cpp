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

Iterative Pre-Order - keep a stack of nodes and keep pushing node , Right and left child in stack and pop in current itr. through
old state of stack .


*/
vector<int> iterative_preorder(struct node* Node){

    vector<int> v ;
    stack<node*> st ;

   st.push(Node) ;

    while(! st.empty() ) {
        struct node*curr = st.top() ;
        st.pop() ;

        v.push_back(curr->data) ;
       
       if (curr->right !=NULL) st.push(curr->right) ;
        if(curr->left != NULL) st.push(curr->left) ;
        


    }

    return v ;
}


// Iterative Inorder traversal 

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

vector<int> v = iterative_preorder(root) ;

for(int i=0 ; i<v.size() ; i++)cout << v[i] << " " ;



return 0;
}
