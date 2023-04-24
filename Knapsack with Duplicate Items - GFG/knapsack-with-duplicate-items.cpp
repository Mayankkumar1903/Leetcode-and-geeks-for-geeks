//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// memeoization 
    // int solve(int ind,int W,int val[],int wt[],vector<vector<int>>& dp){
    //     if(ind == 0)return ((int)(W/wt[0]))*val[0];
    //     if(dp[ind][W]!=-1)return dp[ind][W];
    //     int nottake = 0 + solve(ind-1,W,val,wt,dp);
    //     int take = 0;
    //     if(wt[ind]<=W)take = val[ind]+solve(ind,W-wt[ind],val,wt,dp);
    //     return dp[ind][W]=max(take,nottake);
    // }
    // int knapSack(int N, int W, int val[], int wt[])
    // {
    //     // tabulation approach 
    //     vector<vector<int>> dp(N,vector<int>(W+1,0));
    //     // return solve(N-1,W,val,wt,dp
    //     for(int w = 0;w<=W;w++){
    //         dp[0][w]=((int)(w/wt[0]))*val[0];
    //     }
    //     for(int ind = 1;ind<N;ind++){
    //         for(int w = 0;w<=W;w++){
    //             int nottake = 0 + dp[ind-1][w];
    //             int take = 0;
    //             if(wt[ind]<=w) take = val[ind]+dp[ind][w-wt[ind]];
    //             dp[ind][w]=max(take,nottake);
    //         }
    //     }
    //     return dp[N-1][W];
        
    // }
    
    //space optimisation using two array prev and curr 
    // int knapSack(int N, int W, int val[], int wt[])
    // {
    //     // code here
    //     vector<int>prev(W+1,0),curr(W+1,0);
    //     for(int w = 0;w<=W;w++){
    //         prev[w]=((int)(w/wt[0]))*val[0];
    //     }
    //     for(int ind = 1;ind<N;ind++){
    //         for(int w = 0;w<=W;w++){
    //             int nottake = 0 + prev[w];
    //             int take = 0;
    //             if(wt[ind]<=w) take = val[ind]+curr[w-wt[ind]];
    //             curr[w]=max(take,nottake);
    //         }
    //         prev=curr;
    //     }
    //     return prev[W];
        
    // }
     
     
     int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int>prev(W+1,0);
        for(int w = 0;w<=W;w++){
            prev[w]=((int)(w/wt[0]))*val[0];
        }
        for(int ind = 1;ind<N;ind++){
            for(int w = 0;w<=W;w++){
                int nottake = 0 + prev[w];
                int take = 0;
                if(wt[ind]<=w) take = val[ind]+prev[w-wt[ind]];
                prev[w]=max(take,nottake);
            }
        }
        return prev[W];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends