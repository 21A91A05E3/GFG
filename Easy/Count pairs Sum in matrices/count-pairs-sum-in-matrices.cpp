//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    map<int,int>mp;
	    for(int i = 0; i < n; i++)
	    {
	        int h = 1;
	        for(int j = 0; j < n; j++)
	        {
	            if(mat1[i][j] > x){
	                h = 0;
	                break;
	            }
	            else mp[x - mat1[i][j]]++;
	            
	        }
	        if(h == 0) break;
	    }
	    int c = 0;
	    for(int i = 0; i < n; i++)
	    {
	        int h = 1;
	        for(int j = 0; j < n; j++)
	        {
                if(mat2[i][j] > x){
                    h = 0;
                    break;
                }
	            else if(mp.find(mat2[i][j])!=mp.end()) c+=1;
	        }
	        if(h == 0)break;
	    }
	   
	    return c;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends