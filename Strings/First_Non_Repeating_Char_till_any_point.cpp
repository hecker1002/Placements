#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// Question - given any sting , find an output string where each char shows the first Non-repeating char till that point in original string
// and if NO such char exists till current point , then add '#' to the answer .

// e.g. - aabc => (ANSWER) a#bb

	// Idea - traverse the whole string and wrt each char of string , traverse the queue containing all the POSSIBLE
	// single repeating char of string.
	// now wrt each element od=f string , traverse the queue (from front) till you get a cg=har whose frquency till now is ==1
	// if any char you encounter has frequency > 1 after updating freq. og=f current element in string loop , is freq>1 , then pop()
	// that elemnt from string
	
	// and even after traversing , you cant find a sibgle repeating char , then add "#" to answer string .
		string FirstNonRepeating(string A){ // max = n times
		    
		   string ans = "";
		   // queue to store all single repeating ellemnts till now
		   queue<char> q ;
		   
		   // frequency of each char
		   map<char , int> mp ;
		   for(int j=0;j<A.size();j++){
		       q.push(A[j]);
		       mp[A[j]]++;
		       
		       while(!q.empty()){ // max = 26 times
		           if(mp[q.front()] > 1){q.pop();} // find any char whose frquency =1 (from front)
		           else {ans+=q.front(); break;} // if not , then pop it .
		       }
		       
		       if(q.empty())ans+='#';
		   }
		    // so , TC = 26 * n 
		   return ans ;
		}

 


int main(){



string a = "aabc";
cout << FirstNonRepeating(a);



    return  0;
}

