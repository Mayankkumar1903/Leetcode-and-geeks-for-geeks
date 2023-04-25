//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

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
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
    int countMin(string str){
    //complete the function here
      return str.size()-longestPalindromeSubseq(str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends