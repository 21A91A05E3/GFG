//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int n) 
    { 
        int a[n],b[n];
        a[0]=A[0];
        b[n-1]=A[n-1];
        int i,j;
        for(i=1;i<n;i++)
        {
            j=n-i-1;
            a[i]=min(a[i-1],A[i]);
            b[j]=max(b[j+1],A[j]);
        }
        i=0,j=0;
        int res=0;
        while(j<n)
        {
            if(a[i]<=b[j])
            {
                res=max(res,j-i);
                j++;
            }
            else i++;
        }
        return res;
    }
};


//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends