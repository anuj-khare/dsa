#include<bits/stdc++.h>
using namespace std;

int slidingWindowTemplate(string A,int k){
    int l = 0;
    int r = 0;
    int n = A.size();
    int ans = 0;
    while(r < n){
        //invalid window
        //while(invalidWindow){
            //do something : in most cases l++;
            //and some other operations
        }
        //now window becomes valid 
        ans = max(ans,r-l+1);
        r++;
    }
    return ans;
}

int main(){
    string A = "anuj";
    int k =2;
    cout<<slidingWindowTemplate(A,k);
}