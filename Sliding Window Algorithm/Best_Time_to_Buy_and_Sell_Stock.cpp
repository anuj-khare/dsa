/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/




#include<bits/stdc++.h>
using namespace std;


int maximumProfit(vector<int> &A){
    //Naive Approach : Using a double for loop 
    //O(n**2)
    int n = A.size();
    int ans = 0;
    for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(A[j]-A[i],ans);
            }
        }
        return ans;
}

int maxProfit(vector<int>& A) {
        int n = A.size();
        int l = 0;
        int r = 1;
        int sum = 0;
        while( r < n){
            if(A[r] - A[l] < 0){
                l = r; // This step ensures that l is your global minima : that is why we move r forward so
                //that whenever next maxima comes to the right of l,it becomes your maximum profit 
                //and whenever a new minima is found ,l gets updated
            }
            else{
                sum = max(sum,A[r]-A[l]);
            }
            r++;
        }
        return sum;
    }

int main(){
    int n;
    //vector<int> A{7,6,4,3,1};
    //vector<int> A{7,1,5,3,6,4};
    vector<int> A{2,1,4};
    cout<<maxProfit(A);
    return 0;
}