//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int dfs(int ind, vector<int>& arr, int n, vector<int>& vis){
        if( ind<0 || ind >= n)return 2;
        if(vis[ind]==1)return 1;
        vis[ind]=1;
        vis[ind]=dfs(ind+arr[ind],arr,n,vis);
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int>vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==0) vis[i]= dfs(i,arr,n,vis);
        }
        for(auto i:vis){
            if(i==2) cnt++;
        }
        return cnt;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends