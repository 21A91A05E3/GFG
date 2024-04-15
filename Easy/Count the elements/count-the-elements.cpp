//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,int q) {
        // Your code goes here;
        vector<int>ans;
        sort(b.begin(),b.end());
        int klh=*max_element(a.begin(),a.end());
        int i=0,j=0,c=0;
        vector<int>m(klh+1,n);
        while(i<=min(klh,b[b.size()-1]))
        {
            if(b[j]==i)
            {
                while(b[j]==i)
                {
                    c++;
                    j++;
                }
            }
            m[i]=c;
            i++;
        }
        for(int i=0;i<query.size();i++)
        {
            ans.push_back(m[a[query[i]]]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends