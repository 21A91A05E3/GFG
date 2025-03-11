//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int firstLarge = -1 , secondLarge = -1;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] > firstLarge){
                secondLarge = firstLarge; 
                firstLarge = arr[i];
            }
            else if(arr[i] > secondLarge && arr[i] != firstLarge){
                 secondLarge = arr[i];  
            }
        }
        return secondLarge;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends