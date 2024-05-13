//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&res){
        vis[node] = 1;
        res.push_back(node);
        for(auto it : adj[node]){
            if(vis[it] == 0){
                dfs(it,adj,vis,res);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[v+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(v+1,0);
        int ans = 0;
        for(int i = 1 ; i <= v ; i++){
            if(vis[i] == 0){
                vector<int>res;
                dfs(i,adj,vis,res);
                int connected = 1;
                for(int i = 0 ; i < res.size() ; i++){
                    if(adj[res[i]].size() < res.size()-1){
                        connected = 0;
                        break;
                    }
                }
                ans+=connected;
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends