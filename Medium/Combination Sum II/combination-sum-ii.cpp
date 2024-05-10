//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void combsum(vector<int>&arr,int i,int n,int k,vector<int>res,set<vector<int>>&dp){
        if(k == 0){
            sort(res.begin(),res.end());
            dp.insert(res);
            return;
        }
  
        if(i >= n){
            return;
        }
        if(k-arr[i]>=0){
            res.push_back(arr[i]);
            combsum(arr,i+1,n,k-arr[i],res,dp);
            res.pop_back();
        }
        combsum(arr,i+1,n,k,res,dp);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        set<vector<int>>dp;
        vector<int>res;
        combsum(arr,0,n,k,res,dp);
        vector<vector<int>>ans;
        for(auto it:dp){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends