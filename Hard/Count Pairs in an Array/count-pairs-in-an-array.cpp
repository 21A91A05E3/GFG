//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int Merge(int low , int mid, int high , int arr[]){
        int i = low , j =mid+1 , k = 0 , cnt = 0;
        int temp[high-low+1];
        while(i <= mid && j <=high)
        {
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else {
                cnt += mid-i+1;
                temp[k++] = arr[j++];
            }
        }
        while(i <= mid) temp[k++] = arr[i++];
        while(j <= high) temp[k++] = arr[j++];
        for(int it = low ; it <=high ; it++){
            arr[it] = temp[it-low];
        }
        return cnt;
    }
    int MergeSort(int low , int high , int arr[])
    {
        int ans = 0;
        if(low >= high)return ans;
        int mid = (low + high)/2;
        ans+=MergeSort(low,mid,arr);
        ans+=MergeSort(mid+1,high,arr);
        ans+=Merge(low,mid,high,arr);
        return ans;
    }
    int countPairs(int arr[] , int n ) 
    {
        for(int i = 0  ; i  < n ;  i++) arr[i] = arr[i] * i;
        return MergeSort(0,n-1,arr);
        
     }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends