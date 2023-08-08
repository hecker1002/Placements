#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// mid eleemt of a  any string at index = (size -1)/2  [ 0 base indexing]

int main()
{

    string s = "A man, a plan, a canal: Panama";

    int n = s.size();
    string h = "";
    for (int j = 0; j < n; j++)
    {
        if (isalnum(s[j])) // isalnum(ch) return true if character is a digit(num) or alphabet 
        {
            h += (char)toupper(s[j]); // tolower() returns ascii value and takes only CHARACTERS (not string)
            // to convert into lower case .
        }
    }

    // EDGE CASE - if h.size() < 1 (=0) , empty string always a palindrome .
    int k = 0;
    if (h.size() > 0)
        k = h.size() - 1;

    bool check = true;
    for (int j = 0; j <= k / 2; j++)
    {
        if (h[j] != h[k - j])
        {
            check = false;
            break;
        }
    }

    if(check) cout << "Yes , a palindrome , same for and back .";
    else cout <<"No , not a palindrome .";

    return 0;
}
