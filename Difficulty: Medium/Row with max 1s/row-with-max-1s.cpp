//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findOnePos(int row,vector<vector<int>> &arr){
        
        int l = 0 , h = arr[row].size() , mid , ans = -1;
        while(l <= h){
            mid = (l+h)/2;
            if(arr[row][mid] == 1){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int rowSize = arr.size();
        int colSize = arr[0].size();
        int maxOneCount = 0 , ans = -1;
        for(int i = 0 ; i < rowSize ; i++){
            int ind = findOnePos(i,arr);
            int currOneCount = ind >=0 ? colSize-ind : maxOneCount;
            if(currOneCount > maxOneCount){
                maxOneCount = currOneCount;
                ans = i;
            }
        }
        return ans;
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends