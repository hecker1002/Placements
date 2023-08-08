

// Check if given string of brackets[,{,( are balanced or NOT .

#include <bits/stdc++.h>
using namespace std;
#define ll long long int


bool isValid(string s)
{
   // single bracket never balanced
    if (s.size() == 1)
    {
        return false;
    }

    bool check = true;
  // stack one for opening and stack 2 for closing bracket
    stack<char> st, st1;

    for (int j = 0; j < s.size(); j++)
    {
        st.push(s[j]);
    }


// now from back , if we get any opening bracket , in closing bracket stack  , the to pbracket should be 
// its corresponding bracket , so pop them both and continue till both stack become empty.
    while (!st.empty())
    {

        if (st.top() == ')' || st.top() == '}' || st.top() == ']')
        {
            st1.push(st.top());
            st.pop();
        }

        else
        {
            if (st1.empty())
            {
                check = false;
                break;
            }
            else
            {
                if (st.top() == '(' && st1.top() == ')')
                {
                    st.pop();
                    st1.pop();
                }
                else if (st.top() == '[' && st1.top() == ']')
                {
                    st.pop();
                    st1.pop();
                }
                else if (st.top() == '{' && st1.top() == '}')
                {
                    st.pop();
                    st1.pop();
                }
                else
                {
                    check = false;
                    break;
                }
            }
        }
    }

    if (!st.empty() || !st1.empty())
        check = false;

    return check;
}


int main(){

string s="{()[]}" ;

cout << isValid(s) ;


    return 0;
}