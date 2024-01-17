//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void up(int ind,vector<int>&l ,int n,vector<int>&r,vector<vector<int>>&a,int f[])
    {
        if(r.size()==n)
        {
            a.push_back(r);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                f[i]=1;
                r.push_back(l[i]);
                up(ind+1,l,n,r,a,f);
                f[i]=0;
                r.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int>l ,int n) {
        vector<int>r;
        vector<vector<int>>a;
        int f[9]={0};
        up(0,l,n,r,a,f);
        set<vector<int>>m;
        for(auto it:a)
        {
            m.insert(it);
        }
        vector<vector<int>>v;
        for(auto it:m)
        {
            v.push_back(it);
        }
        sort(v.begin(),v.end());
        return v;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends