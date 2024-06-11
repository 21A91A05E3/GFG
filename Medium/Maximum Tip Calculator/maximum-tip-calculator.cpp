//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
        static bool comp(pair<int, int> a, pair<int, int> b) {
        return abs(a.first) > abs(b.first);
    }
    
    long long maxTip(int n, int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        vector<pair<int, int>> mp;
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
            mp.push_back({a[i]-b[i], i});
            
        sort(mp.begin(), mp.end(), comp);
        
        for(int i=0;i<n;i++) {
            auto ele = mp[i];
            if(ele.first == 0)
                break;
                
            if(ele.first > 0 && x > 0 || y <= 0 && x > 0) {
                v[ele.second] = 1;
                x--;
            } else {
                v[ele.second] = 0;
                y--;
            }
        }
        
        long long s = 0;
        for(int i=0;i<n;i++) {
            if(v[i]) s+=a[i];
            else s+=b[i];
        }
        return s;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends