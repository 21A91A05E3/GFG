//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
        stack<char>st;
        vector<char>ans;
        int c=0;
        for(int i=0;i<S.size();i++){
            if(st.empty())st.push(S[i]);
            else
            {
                while(!st.empty() and S[i]<st.top() and c<k)
                {
                    c+=1;
                    st.pop();
                }
                st.push(S[i]);
            }
        }
        while(c<k)
        {
           st.pop();
           c+=1;
        }
        while(!st.empty())
        {
            char t=st.top();
            st.pop();
            ans.push_back(t);
        }

        string res="";
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(res.size()==0 and ans[i]=='0')continue;
            else res+=ans[i];
        }
        if(res.size())return res;
        return "0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends