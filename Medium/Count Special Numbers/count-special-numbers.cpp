//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    vector<int> sieve(vector<int>&arr)
    {
        int m=*max_element(arr.begin(),arr.end());
        vector<int>v(m+1,0);
        for(int i=0;i<arr.size();i++)
        {
            if(v[arr[i]]<2)
            {
                for(int j=arr[i];j<=m;j+=arr[i])
                {
                    v[j]++;      
                }
            }
        }
        return v;
    }

    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        vector<int>res;
        res=sieve(arr);
        int c=0;
        for(auto it:arr)
        {
            if(res[it]>1)c+=1;
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends