//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        int dp[100006][2][2];
        int profit(int ind,int len,int choice,int count,vector<int>&price)
        {
            if(ind >= len)return 0;
             if(count  == 2) return 0;
            if(ind == len-1)
            {
                if(choice == 0) return 0;
                return price[ind];

            }
           
            if(dp[ind][choice][count]!=-1)return dp[ind][choice][count];
            int pickcall = 0, nonpickcall = 0;
            
            if(choice == 0)
            {
                //buy 
                pickcall = profit(ind+1,len,1,count,price) - price[ind];
            }
            
            else
            {
                //sell  
               pickcall =  profit(ind+1,len,0,count+1,price) + price[ind];
            }
            
            nonpickcall = profit(ind+1,len,choice,count,price);
            
             return dp[ind][choice][count] = max(pickcall,nonpickcall);
        }
        int maxProfit(vector<int>&price){
            //Write your code here..
            int len = price.size();
            memset(dp,-1,sizeof(dp));
            return profit(0,len,0,0,price);
            
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends