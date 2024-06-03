//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        if(n==1 || n==0) return 0;
        if(n==2) return 1;
        int mod=1000000007;
        int a=0l,b=1,ans=1,c;
        for(int i=3;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c%mod;
            ans=((ans*2%mod)+c%mod)%mod;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends