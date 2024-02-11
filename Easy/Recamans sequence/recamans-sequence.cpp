//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<int> recamanSequence(int n){
        // code here
        unordered_map<int,int>mp;
        vector<int>ans;
        ans.push_back(0);
        mp[0]=1;
        for(int i=1;i<n;i++)
        {
            int klh=ans[i-1]-i;
            if(klh<0 || mp[klh]==1)
            {
                klh=ans[i-1]+i;
            }
            mp[klh]=1;
            ans.push_back(klh);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends