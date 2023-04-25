//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int lcs(string& text1, string& text2){
        vector<int>prev(text2.size()+1,0),curr(text2.size()+1,0);
        for(int j=0;j<=text2.size();j++)prev[j]=0;
     
        for(int ind1=1;ind1<=text1.size();ind1++){
            for(int ind2=1;ind2<=text2.size();ind2++){
                if(text1[ind1-1]==text2[ind2-1]) curr[ind2]= 1+prev[ind2-1];
                else curr[ind2]= max(prev[ind2],curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[text2.size()];

    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    return str1.size()+str2.size() - 2*lcs(str1,str2);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends