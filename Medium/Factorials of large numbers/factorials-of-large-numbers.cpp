//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
    vector<int>v;
	v.push_back(1);
	long long int s;
	for(long long int num=1;num<=N;num++)
	{

		s=v.size();
		long long int i=0,d,c=0;
		long long int p;
		while(s--)
		{
			p=((1LL*v[i])*(1LL*num))+c;
			d=p%10;
			v[i]=d;
			c=p/10;
			i+=1;
		}
		while(c){
			d=c%10;
		    v.push_back(d);
		    c=c/10;
	    }
		
	}
	reverse(v.begin(),v.end());
	return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends