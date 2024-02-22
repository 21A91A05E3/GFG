//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod=1e9+7;
    int leela(int i,int j,int n,int m,string s,string t,vector<vector<int>>&dp){
        
        if(j==m) return 1;
        
        if(i==n )return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int p=0,np=0;
        if(s[i]==t[j]){
            p=leela(i+1,j+1,n,m,s,t,dp);
        }
        np=leela(i+1,j,n,m,s,t,dp);
        return dp[i][j]=(p%mod+np%mod)%mod;
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
    
      vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
      return leela(0,0,s.size(),t.size(),s,t,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends