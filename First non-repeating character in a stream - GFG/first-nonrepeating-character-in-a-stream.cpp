//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>count(26,0);
		    string res = "";
		    int j=0;
		    for(int i=0;i<A.size();i++){
		        count[A[i]-'a']++;
		        if(count[A[i]-'a']==1)res+=A[j];
		        else{
		            while(j<=i and count[A[j]-'a']!=1){
		                j++;
		            }
		            if(j>i)res+='#';
		            else res+=A[j];
		        }
		    }
		    return res;
		}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends