//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int>ans;
            int n=txt.size();
            int m=pat.size();
            vector<int>lps(m+1);
            lps[0]=0;
            int k=0,i=1;
            while(i<m)
            {
                if(pat[i]==pat[k])
                {
                    k+=1;
                    lps[i]=k;
                    i+=1;
                }
                else
                {
                    if(k==0)
                    {
                        lps[i]=0;
                        i+=1;
                    }
                    else
                    {
                        k=lps[k-1];
                    }
                }
        
            }
            i=0;
            int j=0;
            while(i<n)
            {
                while(i<n and j<m and txt[i]==pat[j])
                {
                     i++;
                     j++;

                }
                
                if(j==m)
                {
                        ans.push_back(i-m+1);
                        j=lps[j-1];
                }
                else if(txt[i]!=pat[j])
                {
                    if(j==0)i++;
                    else j=lps[j-1];
                    
                }
            }
            if(ans.size())return ans;
            return {-1};
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends