//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    vector<int> twoRepeated (int arr[], int N) {
        vector<int>v;
        int a[100000]={0};
        for(int i=0;i<N+2;i++)
        {
            if(a[arr[i]]==1)
            {
                v.push_back(arr[i]);
            }
            a[arr[i]]++;
        }
        
        return v;       
    }
};


//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends