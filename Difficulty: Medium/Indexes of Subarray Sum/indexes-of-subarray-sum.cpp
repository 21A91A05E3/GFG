//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size(), i = 0, s = 0;
        vector<int> result;
        
        for (int j = 0; j < n; j++) {
            s += arr[j];
            while (s > target && i < j) 
            {
                s -= arr[i];
                i++;
            }
            if (s == target)
            {
                result.push_back(i + 1); 
                result.push_back(j + 1); 
                return result;
            }
        }
        result.push_back(-1);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends