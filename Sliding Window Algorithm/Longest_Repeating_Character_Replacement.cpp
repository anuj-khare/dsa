#include<bits/stdc++.h>
using namespace std;

int findMaxFrequency(unordered_map<char,int> &m){
    int count = 0;
    for(auto item : m){
        count = max(count,item.second);
    }
    return count;
}

int longestRepeatinCharacterReplacementString(string A,int k){
    unordered_map<char,int> m;
        int l = 0;
        int r = 0;
        int n = A.size();
        int ans = 0;
        while(r < n){
            m[A[r]]++;
            //while invalid window
            while(r-l+1 - findMaxFrequency(m) > k){
                m[A[l]]--;
                l++;
            }
            //valid window
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
}

int main(){
    string s = "ABABBA";
    int k = 1;
    // cin>>k;
    cout<<longestRepeatinCharacterReplacementString(s,k);
}