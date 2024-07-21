//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long int nc = 0 ,res = 1 , zc = 0 , n = arr.size();
        int m = INT_MIN ,mod = 1000000007;;
        for(auto it : arr)
        {
          //  cout<<"res = "<<res<<" ";
            if(it > 0) res=(res%mod*it%mod)%mod;
            else if(it < 0){
                m = max(m,it);
                nc++;
                res = (res%mod*it%mod)%mod;
            }
            else zc++;
        }
      //  cout<<"zc = "<<zc<<" nc = "<<nc<<" m = "<<m<<"res = "<<res<<"\n" ;
        if(nc%2 && zc != n-1 && res < 0){
            res = res/m;
        }
        if(res < 0 ) res = 0;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends