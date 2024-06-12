//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int c = 0 , d , x;
        for(int i = 1 ; i <= n ; i++)
        {
            x = i;
            while(x != 0){
                d = x%10;
                if(d == 4){
                    c+=1;
                    break;
                }
                else x = x/10;
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends