//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

 int solve(int ind, int  n,int buy, vector<int>& prices,int allow,vector<vector<vector<int>>>& dp){
        if(ind==n || allow ==0)return 0;
        if(dp[ind][buy][allow]!=-1)return dp[ind][buy][allow];
        if(buy) return dp[ind][buy][allow]= max(-prices[ind]+solve(ind+1,n,0,prices,allow,dp),solve(ind+1,n,1,prices,allow,dp));
        else  return dp[ind][buy][allow]=max(prices[ind]+solve(ind+1,n,1,prices,allow-1,dp),solve(ind+1,n,0,prices,allow,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,n,1,prices,2,dp);
    }



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends