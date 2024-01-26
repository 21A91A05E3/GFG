//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<int>w,v;
        vector<pair<double,pair<int,int>>>u;
        
        for(int i=0;i<n;i++)
        {
            double p=(double)arr[i].value/arr[i].weight;
            //cout<<"p= "<<p<<"   ";
           u.push_back({p,{arr[i].value,arr[i].weight}});
        }
        
        double ans=0;
        sort(u.rbegin(),u.rend());
        for(auto it:u)
        {
           // cout<<ans<<" ";
            
            double r=it.first;

            double v=it.second.first;
        
            double w=it.second.second;
            if(W==0)break;
            
            if(w<=W)
            {
                ans+=v;
                W-=w;
            }
            
            else
            {
                ans+=(v/w)*W;
                W=0;
            }
        }
        return ans;
        
        
      
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends