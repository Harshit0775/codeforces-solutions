/*                                                                    C. Fixing Typos

Many modern text editors automatically check the spelling of the user's text. Some editors even suggest how to correct typos.

In this problem your task to implement a small functionality to correct two types of typos in a word. We will assume that three identical letters together is a typo (for example, word "helllo" contains a typo). Besides, a couple of identical letters immediately followed by another couple of identical letters is a typo too (for example, words "helloo" and "wwaatt" contain typos).
Write a code that deletes the minimum number of letters from a word, correcting described typos in the word. You are allowed to delete letters from both ends and from the middle of the word.

INPUT
The single line of the input contains word s, its length is from 1 to 200000 characters. The given word s consists of lowercase English letters.
OUTPUT
Print such word t that it doesn't contain any typos described in the problem statement and is obtained from s by deleting the least number of letters.
If there are multiple solutions, print any of them

I/P -> helllloo
O/P -> hello

*/



/* Conditions
    
    1. No 3 consecutive element -> aaa
    2. No 2 consecutive pair of couples -> aabb

*/

#include <iostream>
using namespace std; 



int main() {
	
	string s;
	cin>>s;
	
	string temp="";    // make temp string
	
	if(s.size()<3){    // if length is less then 3 there can only be 3 diff elements or 2 same and 1 diff
	    cout<<s;
	    return 0;
	}
	
	temp+=s[0];    // add 1st two elements of string  For eg s-> "helllloo"
	temp+=s[1];    // temp = he;
	
	for(int i=2; i<s.length(); i++){        // running a loop from first l to last
	    if(s[i]==s[i-1] and s[i]==s[i-2]){
	        ;
	    }
	    else temp+=s[i];  // temp = helloo
	}
	
	string ans = "";
	
	for(int i=0; i<temp.length(); i++){
	    if(i<temp.length()-1 and temp[i]==temp[i+1]){  // if i is less then last element and temp[i] = temp[i+1]
	        if(i<temp.length()-3){      // to check 3rd consecutive element i should be less then 3 elements from last
	            if(temp[i+2]==temp[i+3]){   // couples exsist like lloo
	                ans+=temp[i];     //ans = hel
	                ans+=temp[i];     // ans = hell
	                ans+=temp[i+2];   // ans = hello
	                i+=3;     
	            }
	            else ans+=temp[i];  // else add temp[i]
	        }else ans+=temp[i];
	    }else ans += temp[i];
	}
	
	
	cout<<ans;
	
	return 0;
}
