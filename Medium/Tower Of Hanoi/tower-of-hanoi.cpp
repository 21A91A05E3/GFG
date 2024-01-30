//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    void fun(int n,int src,int help,int dest,long long &c)
    {
        
        if(n>0)
        {
        
            fun(n-1,src,dest,help,c);
            cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<dest<<"\n";
            c+=1;
            fun(n-1,help,src,dest,c);
        }
    }
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        long long c=0;
        fun(N,from,aux,to,c);
        return c;
        
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends