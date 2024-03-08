//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    vector<int>frq(27,0);
	    for(auto it:s){
	        frq[it-'a']++;
	    }
	    unordered_map<int,int>mp;
	    for(auto it:frq)
	    {
	        if(it) mp[it]++;
	        if(mp.size() > 2) return false;
	    }

	   if(mp.size() == 1)return true;
	   else{
	       int me = 0 , se = 1000001;
	       for(auto it: mp)
	       {
	            me = max(me,it.first);
	            se = min(se, it.first);
	       }

	       if(mp[me]==1 and me-se == 1)return true;
	       else if(mp[se] == 1 and se == 1)return true;
	       
	   }
	  
	   return false;
	    
	  
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends