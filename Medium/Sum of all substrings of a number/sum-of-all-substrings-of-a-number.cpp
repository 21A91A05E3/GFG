//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long sumSubstrings(string s){
   

        int n = s.size() , mod = 1000000007;
        long long ans = 0 , ts = 0 , num = 0;
        for(int i = 0 ; i < n ; i++)
        {
           ts = (s[i]-'0')*(i+1);
           num = ((num*10)%mod+ts%mod)%mod;
           ans = (ans%mod+num%mod)%mod;
        }
        return ans;

        // your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends