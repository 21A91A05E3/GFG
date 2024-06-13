//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
        int mod = 1000000007;
        int a =1, b = 1,c = 1 ,d ,t;
        for(int i = 3 ; i <=n ; i++)
        {
            d = (a%mod+b%mod)%mod;
            a = b;
            b = c;
            c = d;
           
        }
        return c;
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends