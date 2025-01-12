//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int MaxPrice(int index,vector<int>&price,int total_len,vector<vector<int>>&dp){
        
        
        if(index == price.size() || total_len <=0 ) return 0;
        
        if(dp[index][total_len] != -1) return dp[index][total_len];
        
        //pick
        
        int pick = index+1 <= total_len ? price[index]+MaxPrice(index,price,total_len-(index+1),dp) : 0;
        
        //non-pick
        
        int nonpick = MaxPrice(index+1,price,total_len,dp);
        
        return dp[index][total_len] = max(pick,nonpick);
        
    }
    int cutRod(vector<int> &price) {
        // code here
        
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return MaxPrice(0,price,n,dp);
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends