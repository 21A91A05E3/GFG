//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int myfun(int n)
        {
           
           if(n<=1)return n;
           int a=myfun(n/2);
           int b= myfun(n/3);
           int c= myfun(n/4);
          // cout<<a<<" "<<b<<" "<<c<<" ";
           if(a+b+c<n)return n;
           else return a+b+c;
            
        }
        int maxSum(int n)
        {
            //code here.
            return myfun(n);
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
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends