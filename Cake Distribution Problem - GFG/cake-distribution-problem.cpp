//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
       int tosum = 0;
       for(auto it:sweetness)tosum+=it;
       int start=1,end=tosum,ans = 0;
       while(start<=end){
           int mid = start+(end-start)/2;
           int currsum = 0;
           int pieces = 0;
           for(int i=0;i<N;i++){
               currsum+=sweetness[i];
               if(currsum>=mid){
                   currsum = 0;
                   pieces++;
               }
           }
           if(pieces>=(K+1)){
               ans = mid;
               start = mid+1;
           }
           else end = mid-1;
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends