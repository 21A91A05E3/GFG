//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int dir[3] = {1,-1,0};
    int findMax(int row1,int col1,int col2,int row,int col,vector<vector<int>>& grid, vector<vector<vector<int>>>&dp){
       
        if((row1 >= row || col1 >= col ||  col1 < 0 ) || col2 >= col || col2 < 0) return 0;

        if(dp[row1][col1][col2] != -1) return dp[row1][col1][col2];
        int ans = 0;
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                int val = 0;
                if(col1 == col2)val = grid[row1][col1];
                else val = grid[row1][col1]+grid[row1][col2];
                
                ans = max(ans,val+findMax(row1+1,col1+dir[i],col2+dir[j],row,col,grid,dp));
            }
        }
       
        return dp[row1][col1][col2] = ans;
        
    }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return findMax(0,0,m-1,n,m,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends