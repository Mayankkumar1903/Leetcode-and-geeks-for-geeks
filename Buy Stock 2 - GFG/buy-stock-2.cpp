//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
           
        long long  aheadnotbuy, aheadbuy, currnotbuy, currbuy;
         aheadnotbuy = aheadbuy = 0;
         for(int ind = n-1;ind>=0;ind--){
             currnotbuy = max(prices[ind] + aheadbuy,aheadnotbuy);
             currbuy = max(-prices[ind]+aheadnotbuy,aheadbuy);
             aheadnotbuy = currnotbuy;
             aheadbuy = currbuy;
         }
         return aheadbuy;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends