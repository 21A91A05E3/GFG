//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void cal(int n,int zc,int oc,string s,vector<string>&res)
    {
        if(s.size()>n || zc>oc) return;
        if(s.size()==n)
        {
            res.push_back(s);
            return;
        }
        cal(n,zc,oc+1,s+'1',res);
        cal(n,zc+1,oc,s+'0',res);
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>res;
	    string s="";
	    int oc = 0,zc = 0;
	    cal(n,zc,oc,s,res);
	    return res;
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
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends