//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int s1 = 0 ,  s2 = 0 ;
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++) s1+=a[i];
           
        for(int i = 0 ; i < m ; i++){
            s2+=b[i];
            mp[b[i]]++;
        }
        if(s1 == s2)return 1;
        int d = s1-s2;
        if(d%2)return -1;
        int r = d/2;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(a[i]-r)!=mp.end()) return 1;
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends