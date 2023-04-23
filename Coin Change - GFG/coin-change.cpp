//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int amount) {

        // code here.
        vector<vector<long long int >>dp(n,vector<long long int>(amount+1,0));
        for(int amoun = 0; amoun<=amount;amoun++){
            if((amoun%coins[0])==0)dp[0][amoun]=1;
            else dp[0][amoun]=0;
        }
        for(int ind = 1;ind<n;ind++){
            for(int amoun = 0;amoun<=amount;amoun++){
                long long int notpick = dp[ind-1][amoun];
                long long int pick = 0;
                if(coins[ind]<=amoun) pick = dp[ind][amoun-coins[ind]];
                dp[ind][amoun]=pick+notpick;
            }
        }
        long long int ans = dp[n-1][amount];
        // int ans = solve(n-1,amount,coins,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends