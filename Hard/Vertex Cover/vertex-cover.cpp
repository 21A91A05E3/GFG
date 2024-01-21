//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int vc(vector<vector<int>>&adj,vector<int>&indeg,int n,int e,int i)
        {
            if(i>n)
            {
                if(e==0)
                {
                    return 0;
                }
                return 24;
            }
            for(auto it:adj[i])
            {
                indeg[it]--;
            }
            int pick=1+vc(adj,indeg,n,e-indeg[i],i+1);
            for(auto it:adj[i])
            {
                indeg[it]++;
            }
            int nonpick=0+vc(adj,indeg,n,e,i+1);
            return min(pick,nonpick);
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                int m=edges.size();
                vector<vector<int>>adj(n+1);
                for(auto it:edges)
                {
                    int u=it.first;
                    int v=it.second;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
                vector<int>indeg(n+1,0);
                for(int i=0;i<=n;i++)
                {
                    indeg[i]=adj[i].size();
                }
                
                return vc(adj,indeg,n,m,1);
            }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends