//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
string binaryNextNumber(string s) {
        int n = s.size(),i = 0,r = 1,t;             
        while(i < n && s[i] == '0') {
            i++;
        }
        string res; 
        for(int j = n - 1; j >= i; j--) {
            t = r + (s[j] - '0'); 
            if(t == 2) {
                res += '0';  
                r = 1;
            } else if(t == 1) {
                res += '1';  
                r = 0;
            } else {
                res += '0';  
                r = 0;
            }
        }
        if(r == 1) {
            res += '1';
        }
        reverse(res.begin(), res.end());
    
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends