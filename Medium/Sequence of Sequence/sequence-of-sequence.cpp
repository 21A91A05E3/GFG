//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int ans=0;
    void fun(int i,int m,int n,vector<int>&v){
        if(v.size()==n){
            ans++;
            return;
        }
        for(int j=i*2;j<=m;j++)
        {
            v.push_back(j);
            fun(j,m,n,v);
            v.pop_back();
        }
       
    }
    int numberSequence(int m, int n){
        // code here
        if(m<n)return 0;
        vector<int>v;
        for(int i=1;i<=m/n;i++)
        {
            v.push_back(i);
            fun(i,m,n,v);
            v.pop_back();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends