//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int fun(int ind,int prev_ind,int n,int arr[],vector<vector<int>>& dp){
        if(ind==n)return 0;
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        int length = 0+ fun(ind+1,prev_ind,n,arr,dp);//not take 
        if( prev_ind == -1||arr[ind]> arr[prev_ind]) 
         length = max(length,  1+fun(ind+1,ind,n,arr,dp));
         return dp[ind][prev_ind+1]=length;
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fun(0,-1,n,a,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends