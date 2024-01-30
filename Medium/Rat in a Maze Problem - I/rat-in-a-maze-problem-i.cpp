//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    vector<string>res;
    public:
void trav(int r,int c,int n,int m,vector<vector<int>>&grid,string s)
{
    
    if(r<0 or c<0 or r>n or c>m or grid[r][c]==0 or grid[r][c]==-1){
        s.pop_back();
        return ;
    }
    if(r==n and c==m){
        res.push_back(s);
        return;
    }
    grid[r][c]=-1;
    trav(r-1,c,n,m,grid,s+='U');
    s.pop_back();
     trav(r,c-1,n,m,grid,s+='L');
    s.pop_back();
    trav(r,c+1,n,m,grid,s+='R');
    s.pop_back();
    trav(r+1,c,n,m,grid,s+='D');
    s.pop_back();
    grid[r][c]=1;
    
}
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s="";
        trav(0,0,n-1,n-1,m,s);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends