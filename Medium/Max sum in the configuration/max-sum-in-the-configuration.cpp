//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        
        long long totalsum = 0 , condsum = 0 , reqsum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            totalsum += a[i];
            condsum += (long)a[i]*i;
        }
        reqsum = condsum;
        for(int i = 0 ; i < n ; i++)
        {
            condsum += totalsum-(long)a[n-i-1]*n;
            reqsum = max(reqsum,condsum);
        }
        return reqsum;
 
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends