//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        map<char,int>mp;
        for(auto it:s) mp[it]++;
        int c = 0;
        for(auto it : mp)
        {
            char ch = it.first;
            int frq = it.second;
            
            if((ch-'a')%2 != frq%2) c++;
        }
        if(c%2) return "ODD";
        return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends