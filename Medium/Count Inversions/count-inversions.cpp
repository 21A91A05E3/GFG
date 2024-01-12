//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long c=0;
    int merge(long long  l,long long  m,long long  h,long long  arr[])
    {
        long long i=l,j=m+1,k=l;
        long long temp[h+1];
        while(i<=m and j<=h)
        {
            if(arr[i]<=arr[j]) {
                temp[k]=arr[i];
                i+=1;
            }

            else 
            {
                c+=m-i+1;
                temp[k]=arr[j];
                j+=1;
            }
            k++;
        }
        while(i<=m)
        {
            temp[k]=arr[i];
            i++;
            k++;                    
        }
        while(j<=h)
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
        
        for(int i=l;i<=h;i++)
        {
            arr[i]=temp[i];
        }
    }
    void  ms(long long l,long long h,long long arr[])
    {
       
        if(l<h)
        {
           int m=(l+h)/2;
            ms(l,m,arr);
            ms(m+1,h,arr);
            merge(l,m,h,arr);
        }
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        ms(0,N-1,arr);
        return c;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends