//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int,int>mp;
        int fl=0;
        for(int i=0;i<2*N;i+=2) mp[arr[i]]=arr[i+1];
            
        queue<pair<int,int>>q;
        q.push({1,0});
        vector<int>vis(31,0);
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            for(int i=1;i<=6;i++)
            {
                int node=t.first+i;
                if(node==30)return t.second+1;
                if(!vis[node])
                {
                    if(mp.find(node)!=mp.end())
                    {
                        
                        if(mp[node]>node) q.push({mp[node],t.second+1});
                        vis[mp[node]]=1;
                    }
                    else
                    {
                        q.push({node,t.second+1});
                    }
                    vis[node]=1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends