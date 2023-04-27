//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]){
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy = 0; buy<=1;buy++){
                for(int allow = 1; allow<=k;allow++){
                     if(buy==1) dp[ind][buy][allow]= max(-prices[ind]+dp[ind+1][0][allow],dp[ind+1][1][allow]);
        else  dp[ind][buy][allow]=max(prices[ind]+dp[ind+1][1][allow-1],dp[ind+1][0][allow]);
                }
            }
        }
        return dp[0][1][k];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends