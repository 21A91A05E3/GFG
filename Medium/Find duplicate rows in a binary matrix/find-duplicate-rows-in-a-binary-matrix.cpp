//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
public:
vector<int> repeatedRows(vector<vector<int>> matrix, int r, int c) 
{ 
    vector<int>res;
    map<int,int>mp;
    long long m=1e9+7;
    for(int i=0;i<r;i++)
    {
        long long s=0;
        for(int j=0;j<c;j++)
        {
            if(matrix[i][j])
            {
                s+=(1<<j);
                s=s%m;
            }
        }
        if(mp.find(s)==mp.end())
        {
            mp[s]++;
        }
        else
        {
            res.push_back(i);
        }
    }
    return res;
} 
};




//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends