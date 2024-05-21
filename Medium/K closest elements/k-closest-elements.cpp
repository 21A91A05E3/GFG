//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        map<int,vector<int>>mp;
        vector<int>res,t;
        for(auto it:arr)
        {
            if(it!=x)
           mp[abs(x-it)].push_back(it);
        }
        for(auto it : mp)
        {
            if(k <= 0) return res;
            
            t = it.second;
            int l = t.size();
            if(l>1)sort(t.begin(),t.end());
            
            while(k>0  && l){
                res.push_back(t[l-1]);
                k--;
                l--;
            }
            
            
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends