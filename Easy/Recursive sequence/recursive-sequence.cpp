//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long s=1,i=1,res=1,ans=0;
        long long mod=1e9+7;
        while(s<=n)
        {
            res=1;
          //  cout<<"i= "<<i;
            for(int k=1;k<=s;k++)
            {
                res=(res%mod*i%mod)%mod;
                i+=1;
            }
         //   cout<<"res= "<<res<<"  ans= "<<ans<<" ";
            ans=(ans%mod+res%mod)%mod;
            s+=1;
           // cout<<" ** ";
            
        }
       // cout<<"i= "<<i<<" ";
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends