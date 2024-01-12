//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool isprime(int n)
    {
        if(n<=1)return 0;
 
            for(int i=2;i*i<=n;i++)
            {
                if(n%i==0)return 0;
            }
            return 1;
    }
    int minNumber(int arr[],int N)
    {

        int s=0,c=0;
        for(int i=0;i<N;i++)
        {
            s+=arr[i];
        }
        while(!isprime(s))
        {
            s+=1;
            c+=1;
            
        }
        return c;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends