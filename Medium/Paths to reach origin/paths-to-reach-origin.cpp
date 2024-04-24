//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int paths(int x,int y,vector<vector<int>>&dp){
        if(x == 0  and y == 0)return 1;
        if(x<0 || y<0)return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        int left = paths(x-1,y,dp);
        int right = paths(x,y-1,dp);
        return dp[x][y] = (left%1000000007+right%1000000007)%1000000007;
    }
    int ways(int x, int y)
    {
        //code here.
        vector<vector<int>>dp(501,vector<int>(501,-1));
        return paths(x,y,dp);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends