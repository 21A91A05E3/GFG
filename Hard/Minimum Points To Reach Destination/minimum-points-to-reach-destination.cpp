//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    int fun(int i, int j, int m, int n, vector<vector<int>>& points,vector<vector<int>>&dp)
    {
        if (i >= m || j >= n) return INT_MAX; 
        
        if (i == m - 1 && j == n - 1) return max(1, 1 - points[i][j]); 
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int right = fun(i, j + 1, m, n, points , dp); 
        
        int down = fun(i + 1, j, m, n, points , dp);
        
        int req = min(right, down) - points[i][j];
        
        return dp[i][j] = max(1, req); 
    }
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(m, vector<int>(n, -1));
	    return fun(0, 0, m, n, points,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends