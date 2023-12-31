#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*

Postfix expresion - operators  occur after the operands . e.g. -  [   a b +] =>  [ a + b  ]
SOmetimes , to give a sense of parenthesis , we use sequence of operators instead of individually putting them infornt of elements 
like -  a b c + * => a * ( b + c) -> last operator goes to first 2 operands
   but  a b + c* => a+b * c 

Here , use stacks to change postfix expresion to infix exprs - operator b/w operand s and evaluate it 

Logic  - go from lleft to right and keep on pushing the NUMBERS in the stack  in expresion and whenever you encounter an operation ( since first from left) pick top 2 elemnt s elaute it 
based on operator you got and push the result in same stack

The end number in the stack - is answer .
*/

int postfix_eval ( string exp) {

    int n = exp.size() ;
   
   // initialize the stack (lifo) 
    stack <int> s ;
   
   // push only the numbers 

   for(int i =0 ; i<n ;i++){

    if(isdigit(exp[i])){
        s.push(exp[i]-'0') ;
    }
    else {
        
  // in stack , currently therea re actually numbers ( NOT numbers in char form but actual no.s) . mno need to again typecast it as top - '0'
        int top1 = s.top();
        s.pop();

        int top2 = s.top() ;
        s.pop() ;

        int ans = 0  ;
        // add
        if(exp[i]=='+'){
            
        ans = top2 + top1 ;
         s.push(ans) ;

        }
        // subtract 
        else if(exp[i]=='-'){

        ans = top2 - top1 ;  // Use top2 - top1 , NOT the other way round since first operand willhave occured  occur more early in stack
         s.push(ans) ;
        }
        // divide
        
        else if(exp[i]=='/'){
            
        ans = top2 / top1 ;
         s.push(ans) ;
        }

         // multiply 
        else if(exp[i]=='*'){
            
        ans = top2 * top1 ;
         s.push(ans) ;
        }
    
    }
   }
  
  // for numbers ( postfix to infix then eval.)  .  we use isdigit(exp[i]) till another space char comes as num+= num*10 + exp[i]
 
   return s.top() ;

}
int main()
{

string exp = "231*+9-" ; 

cout << postfix_eval(exp) << endl ;



  return 0;
}
