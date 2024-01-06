//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int pfsum(int n)
    {
        if(n==1)return 0;
        int ans=0;
        map<int,int>mp;
        while(n%2==0)
        {
            n=n/2;
            mp[2]++;
        }
        for(int i=3;i<=sqrt(n);i+=2)
        {
            while(n%i==0)
            {
                n=n/i;
                mp[i]++;
            }
        }
        if(n>2)mp[2]++;
        for(auto it:mp)
        {
            ans+=it.second;
        }
        return ans;
    }
	int sumOfPowers(int a, int b){
	    // Code here
	    int ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        ans+=pfsum(i);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends