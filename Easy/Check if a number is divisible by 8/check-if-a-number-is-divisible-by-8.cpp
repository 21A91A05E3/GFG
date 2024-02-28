//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int DivisibleByEight(string s){
        int n=s.size();
        if(s.size()==1)
        {
            if((s[0]-'0')%8==0)return 1;
            return -1;
            
        }
        else if(s.size()==2)
        {
            if((((s[n-2]-'0')*10)+(s[n-1]-'0'))%8==0)return 1;
            return -1;
        }
        else
        {
            int a=(s[n-3]-'0')*100;
            int b=(s[n-2]-'0')*10;
            int c=(s[n-1]-'0');
            if((a+b+c)%8==0)return 1;
            return -1;
        }
        //code here
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends