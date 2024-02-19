//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
       priority_queue<int>pq;
       map<char,int>mp;
       for(auto it:s)
       {
           mp[it]++;
       }
       for(auto it:mp){
           pq.push(it.second);

       }
       while(k--)
       {
           int t=pq.top();
           t-=1;
           pq.pop();
           pq.push(t);
       }
       int ans=0;
       while(!pq.empty())
       {
           int t=pq.top();
           pq.pop();
           ans+=t*t;
       }
       return ans;


    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends