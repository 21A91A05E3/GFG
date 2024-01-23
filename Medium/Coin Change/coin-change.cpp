//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int fun(int i,int n,int s,int coins[],vector<vector<long long int>>&dp)
    {
        //base case
        if(s==0)return 1;
        if(s<0)return 0;
        if(i>=n)return 0;
        if(dp[i][s]!=-1)return dp[i][s];
        long long int pc=0,npc=0;
        
        //pc
        if(coins[i]<=s) pc=fun(i,n,s-coins[i],coins,dp);

        //npc
        npc=fun(i+1,n,s,coins,dp);
        
        return dp[i][s]=pc+npc;
    }
    long long int count(int coins[], int n, int sum) {
      vector<vector<long long int>>dp(n,vector<long long int>(1001,-1));
       return fun(0,n,sum,coins,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends