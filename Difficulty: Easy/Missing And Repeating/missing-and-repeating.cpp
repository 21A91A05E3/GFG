//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n = arr.size();
        long long actSqSum = 0 , arrSqSum = 0 , actSum = 0 , arrSum = 0;
        actSqSum = (n*(n+1)*(2*n+1))/6;
        actSum = (n*(n+1))/2;
        for(int  i = 0 ; i < arr.size() ; i++){
            arrSum+=arr[i];
            arrSqSum += arr[i]*arr[i];
        }
        
        int sqDiff = actSqSum - arrSqSum; //x2-y2
        int diff = actSum - arrSum; //x-y = diff
        int val =   sqDiff/diff;    //x+y
        int x = (val+diff)/2; //missing
        int y = x - diff; //rep
        
        return {y,x};
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends