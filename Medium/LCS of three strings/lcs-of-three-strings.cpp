//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int leela(int i,int j,int k,string a,string b,string c,int n1,int n2,int n3, vector<vector<vector<int>>>&dp)
        {
            if(i>=n1 or j>=n2 or k>=n3)return 0;
            if(dp[i][j][k]!=-1)return dp[i][j][k];
            int s1=0,s2=0,s3=0,s4=0;
            if(a[i]==b[j] and b[j]==c[k])
            {
                s1=1+leela(i+1,j+1,k+1,a,b,c,n1,n2,n3,dp);
            }
            else
            {
                s2=leela(i+1,j,k,a,b,c,n1,n2,n3,dp);
                s3=leela(i,j+1,k,a,b,c,n1,n2,n3,dp);
                s4=leela(i,j,k+1,a,b,c,n1,n2,n3,dp);
            }
            return dp[i][j][k]=max(s1,max(s2,max(s3,s4)));
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            vector<vector<vector<int>>>dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
            return leela(0,0,0,A,B,C,n1,n2,n3,dp);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends