//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod = 1000000007;
    int findsubseq(int i , int  j ,string s1,string s2, vector<vector<int>>&dp){
        
        if(j > s2.size()) return 1;
        
        if(i > s1.size()) return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int p = 0 ,  np = 0;
        
        if(s1[i] == s2[j]) p = findsubseq(i+1,j+1,s1,s2,dp);
        
        np = findsubseq(i+1,j,s1,s2,dp);
        
        return dp[i][j] = (p%mod+np%mod)%mod;
        
    }
    
    int countWays(string s1, string s2) {
        
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        
        int ans = findsubseq(0,0,s1,s2,dp);
        
        return ans%mod;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends