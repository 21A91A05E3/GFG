//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long findcount(int i,int j,int ind,int n,vector<vector<vector<long long>>>&dp)
    {
        
        long long ans = 0;
        
        
        if(i < 0 || j < 0 || i > 3 || j > 2 || (i == 3 && (j == 0 || j == 2))) return 0;
        
        if(dp[i][j][ind]!=-1) return dp[i][j][ind];

        if(ind == n) return 1;
            
            ans += findcount(i,j,ind+1,n,dp);
            ans += findcount(i+1,j,ind+1,n,dp);
            ans += findcount(i-1,j,ind+1,n,dp);
            ans += findcount(i,j-1,ind+1,n,dp);
            ans += findcount(i,j+1,ind+1,n,dp);
        
        return dp[i][j][ind] = ans;
        
        
    }
    long long getCount(int n) {
        // Your code goes here
        
        vector<vector<vector<long long>>>dp(4,vector<vector<long long>>(3,vector<long long>(26,-1)));
        map<int,pair<int,int>>mp;
        
        mp[0] = {3,1};
        mp[1] = {0,0};
        mp[2] = {0,1};
        mp[3] = {0,2};
        mp[4] = {1,0};
        mp[5] = {1,1};
        mp[6] = {1,2};
        mp[7] = {2,0};
        mp[8] = {2,1};
        mp[9] = {2,2};
        long long res = 0;
        for(int i = 0 ; i <= 9 ; i++)
        {
            
            res+=findcount(mp[i].first,mp[i].second,1,n,dp);
           //cout<<res<<" ";
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends