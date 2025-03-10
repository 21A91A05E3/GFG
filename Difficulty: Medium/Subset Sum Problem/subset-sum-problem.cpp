//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    int fun(int i,vector<int>& arr, int target, vector<vector<int>>&dp){
        
        if(target == 0) return  1;
        
        if(i == 0){
            return arr[0] == target;
        }
        
        if(target < 0) return 0;
        
        
        if(dp[i][target] != -1) return dp[i][target];
        
        return dp[i][target] = fun(i-1,arr,target-arr[i],dp) |fun(i-1,arr,target,dp) ;
    }
    
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        // vector<vector<int>>dp(arr.size(),vector<int>(target+1,-1));
        // return fun(arr.size()-1,arr,target,dp) == 1;
        
        int n = arr.size();
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i = 0 ; i < n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        for(int  i = 1 ; i < n  ; i++){
            for(int t = 1 ; t <= target ; t++){
                
                bool pick = false;
                if(arr[i] <= t) pick = dp[i-1][t-arr[i]];
                bool nonpick = dp[i-1][t];
                dp[i][t] = pick | nonpick;
            }
        }
        return dp[n-1][target];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends