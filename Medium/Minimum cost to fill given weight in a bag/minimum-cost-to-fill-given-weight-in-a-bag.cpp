//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
int findmincost(int i, int n, int w, vector<int>& cost, vector<vector<int>>& dp) {
    if (w == 0) return 0; 
    if (i == n) return INT_MAX; 

    if (dp[i][w] != -1) return dp[i][w]; 

    int p = INT_MAX, np = INT_MAX;


    if (w - (i + 1) >= 0 && cost[i] != -1) {
        int res = findmincost(i, n, w - (i + 1), cost, dp); 
        if (res != INT_MAX) {
            p = res + cost[i];
        }
    }
    
   
    np = findmincost(i + 1, n, w, cost, dp);

    return dp[i][w] = min(p, np); 
}

int minimumCost(int n, int w, vector<int>& cost) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1)); 
    int ans = findmincost(0, n, w, cost, dp);
    return (ans != INT_MAX) ? ans : -1; 
}
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends