//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function

    long long int count(long long int n)
    {
    	// Your code here
    	vector<long long int>dp(n+1);
    	dp[0]=1;
    	int coins[]={3,5,10};
    	for(auto it:coins)
    	{
    	    for(int i=it;i<=n;i++)
    	    {
    	        dp[i]+=dp[i-it];
    	    }
    	}
    	return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends