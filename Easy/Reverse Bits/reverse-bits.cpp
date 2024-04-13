//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long n) {
        long long r=0;
        int b[32]={0},j;
        for(int i=31;i>=0;i--)
        {
            if((n>>i)&1)b[i]=1;
            //cout<<b[i]<<" ";
        }
        //cout<<"\n";
        for(int i=31;i>=0;i--)
        {
            if(b[i]==1) 
            {
                j=32-i-1;
                r+=pow(2,j);
            }
            //cout<<"r="<<r<<"\n";
        }
        return r;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends