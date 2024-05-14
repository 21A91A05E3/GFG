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
//     int maxdif(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &vis) {
    
//     vis[i][j] = true;
//     int left = 0, right = 0, up = 0, down = 0 , ans = INT_MAX;

//     if (j > 0) {
//         left = max(abs(heights[i][j] - heights[i][j - 1]),maxdif(i, j - 1, heights, vis)); 
//         ans = min(ans,left);
//     }
//     if (j < heights[0].size() - 1) {
//         right =max(abs(heights[i][j] - heights[i][j + 1]),maxdif(i, j + 1, heights, vis));  
//         ans = min(ans,right);
//     }
//     if (i > 0) {
//         up = max(abs(heights[i][j] - heights[i - 1][j]), maxdif(i - 1, j, heights, vis)); 
//         ans = min(ans,up);
//     }
//     if (i < heights.size() - 1) {
//         down = max(abs(heights[i][j] - heights[i + 1][j]),maxdif(i + 1, j, heights, vis));  
//         ans = min(ans,down);
//     }

//     vis[i][j] = false;
//     if(i == heights.size()-1 && j == heights[0].size()-1)return ans;
//     return 0;

   
// }
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        //vector<vector<bool>>vis(rows,vector<bool>(columns,false));
        //return maxdif(0,0,heights,vis);
        
        vector<vector<int>>dp(rows,vector<int>(columns,INT_MAX));
        dp[0][0] = 0;
        queue<pair<int,int>>q;
        q.push({0,0});
        int dist;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i = top.first;
            int j= top.second;
            if(i > 0){
                dist = max(abs(heights[i][j]-heights[i-1][j]),dp[i][j]);
                if(dp[i-1][j] > dist){
                    dp[i-1][j] = dist;
                    q.push({i-1,j});
                }
            }
            if(j > 0){
                dist = max(abs(heights[i][j]-heights[i][j-1]),dp[i][j]);
                if(dp[i][j-1] > dist){
                    dp[i][j-1] = dist;
                    q.push({i,j-1});
                }
            }
            if(i < rows-1){
               dist = max(abs(heights[i][j]-heights[i+1][j]),dp[i][j]);
                if(dp[i+1][j] > dist){
                    dp[i+1][j] = dist;
                    q.push({i+1,j});
                }
            }
            if(j < columns-1){
                dist = max(abs(heights[i][j]-heights[i][j+1]),dp[i][j]);
                if(dp[i][j+1] > dist){
                    dp[i][j+1] = dist;
                    q.push({i,j+1});
                }
            }
        }
        return dp[rows-1][columns-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends