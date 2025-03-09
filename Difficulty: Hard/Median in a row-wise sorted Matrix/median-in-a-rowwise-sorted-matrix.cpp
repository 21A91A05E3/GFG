//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findSmallEleCount(int val,vector<vector<int>> &mat){
        int rowSize = mat.size();
        int colSize = mat[0].size();
        int cnt = 0;
        for(int i = 0 ; i< rowSize ; i++){
            int low = 0 , high = colSize , mid,ans = high;
            while(low <= high){
                mid = (low+high)/2;
                if(mat[i][mid] > val){
                    ans = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;   
                }
            }
            cnt+=ans;
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int rowSize = mat.size();
        int colSize = mat[0].size();
        int low = INT_MAX , high = INT_MIN;
        for(int i = 0 ; i < rowSize ; i++){
            low = min(low,mat[i][0]);
            high = max(high,mat[i][colSize-1]);
        }
        int mid , ans;
        while(low <= high){
            mid = (low+high)/2;
            int actualCnt = (rowSize*colSize)/2;
            if(findSmallEleCount(mid,mat) <= actualCnt){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends