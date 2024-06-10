//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        unordered_map<char,int>mp;
        unordered_map<int,char>mp1;
        mp['!'] = 1;
        mp['#'] = 2;
        mp['$'] = 3;
        mp['%'] = 4;
        mp['&'] = 5;
        mp['*'] = 6;
        mp['?'] = 7;
        mp['@'] = 8;
        mp['^'] = 9;
        
        mp1[1] = '!';
        mp1[2] = '#';
        mp1[3] = '$';
        mp1[4] = '%';
        mp1[5] = '&';
        mp1[6] = '*';
        mp1[7] = '?';
        mp1[8] = '@';
        mp1[9] = '^';
        vector<int>temp;
        for(int i = 0 ; i < n ; i++){
            temp.push_back(mp[nuts[i]]);
        }
        
        sort(temp.begin(),temp.end());
        
        for(int i = 0 ; i < n ; i++)
        {
            nuts[i] = mp1[temp[i]];
            bolts[i] = nuts[i];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends