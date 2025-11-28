/*
Given a string s, find the length of the longest substring without duplicate characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/


#include<bits/stdc++.h>
#include<string>
using namespace std;

int longestSubstringWithoutRepeatingCharacter(string A){
    unordered_set<char> s;
    int l = 0;
    int r = 0;
    int n = A.size();
    int ans = 0;
    while( r < n){

        while(s.find(A[r]) != s.end()){
            //A[r] exists in the set
            s.erase(A[l]);
            l++;
        }
        //A[r] is unique now
        s.insert(A[r]);
        ans = max(ans,r-l+1);
        r++;
        
    }
    return ans;
}


int main(){
    string s = "bbbbbb";
    // cin>>s;
    cout<<longestSubstringWithoutRepeatingCharacter(s);
    return 0;
}