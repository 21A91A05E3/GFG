//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
	int find(int n,int x,int y,vector<int> &dp){
	    if(n == 0) return dp[n] = 0;
	    else if(n == 1) return dp[n] = 1;
	    else if(dp[n] != -1) return dp[n];
	    
	    int a = 1 , b = 1 ,c = 1;
	    
	    if(n-x >= 0) a = find(n-x,x,y,dp);
	    
	    if(n-y >= 0) b = find(n-y,x,y,dp);
	    
	    if(n-1 >= 0) c = find(n-1,x,y,dp);
	    
	    if(!a or !b or !c) return dp[n] = 1;
	    return dp[n] = 0;
	}
	
	int findWinner(int N, int X, int Y){
	    vector<int> dp(N+1,-1);
		return find(N,X,Y,dp);
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends