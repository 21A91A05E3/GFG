//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<long long,int>>q;
        q.push({start,0});
        vector<int>vis(100001,0);
        while(!q.empty())
        {
            auto t=q.front();
            long long n=t.first;
            q.pop();
            if(n==end)return t.second;
            for(auto it:arr)
            {
                long long num=(n*it)%100000;
                if(num==end)return t.second+1;
                if(!vis[num])
                {
                    q.push({num,t.second+1});
                    vis[num]=1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends