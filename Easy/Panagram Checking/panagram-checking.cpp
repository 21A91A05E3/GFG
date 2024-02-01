//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
      bool checkPangram (string s) {
        // your code here
      
        bitset<26>frq;
        for(auto it:s)
        {
            char it1=(char)tolower(it);
           // cout<<it1<<" ";
           if(it1>='a' and it1<='z') frq[it1-'a']=1;
        }
        for(int i=0;i<26;i++)
        {
            if(frq[i]==0)return false;
        }
       
        return true;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends