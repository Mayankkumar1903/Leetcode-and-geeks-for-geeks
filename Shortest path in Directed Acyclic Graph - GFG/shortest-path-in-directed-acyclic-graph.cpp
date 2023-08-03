//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(auto it : edges)
            adj[it[0]].push_back( {it[1], it[2]} );
        vector<int> distance(N, INT_MAX);
        distance[0]=0;
        queue<int>q;
        q.push(0);
        while(q.size()>0){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                int newnode = it.first;
                int dist = it.second;
                if(distance[node] + dist < distance[newnode]){
                    distance[newnode] = dist + distance[node];
                    q.push(newnode);
                }
            }
        }
        for(auto &t:distance){
            if(t==INT_MAX) t = -1;
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends