//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int low = 1;
        int high = m;
        int mid , temp ;
        long long val;
        while(low <= high){
            mid = (low+high)/2;
            temp = n;
            val = 1;
       
            while(temp > 0){
                if(val > m)break;
                val*=mid;
                temp--;
            }
            if(val == m) return mid;
            else if(val > m){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends