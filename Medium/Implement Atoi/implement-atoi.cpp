//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans=0,h=1;
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i])) ans=ans*10+(s[i]-'0');
            else if(i==0 and s[i]=='-') continue;
            else return -1;
        }
        if(s[0]=='-')return ans*-1;
        else return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends