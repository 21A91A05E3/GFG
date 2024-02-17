//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfsfin_time(int node,vector<vector<int>>& adj,vector<int>&vis,vector<int>&ft)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            dfsfin_time(it,adj,vis,ft);
	        }
	    }
	    ft.push_back(node);
	}
	void rev_graph(vector<vector<int>>adj,vector<int>radj[])
	{
	    for(int i=0;i<adj.size();i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            radj[adj[i][j]].push_back(i);
	        }
	    }
	}
	void dfs(int node,vector<int>radj[],vector<int>&rvis)
	{
	    rvis[node]=1;
	    for(auto it:radj[node])
	    {
	        if(!rvis[it])
	        {
	            dfs(it,radj,rvis);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>vis(V+1,0);
        vector<int>ft;
        for(int i=0;i<V;i++)
        {
            
             if(!vis[i])dfsfin_time(i,adj,vis,ft);
        }
        vector<int>radj[V+1];
        rev_graph(adj,radj);
      
        int c=0;
        vector<int>rvis(V+1,0);
        for(int i=ft.size()-1;i>=0;i--)
        {
            if(!rvis[ft[i]])
            {
              //  cout<<ft[i]<<" ";
                c+=1;
                dfs(ft[i],radj,rvis);
            }
        }
        return c;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends