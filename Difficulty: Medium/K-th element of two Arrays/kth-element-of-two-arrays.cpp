//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        // code here
        int n1 = nums1.size() , n2 = nums2.size();
        if(n1 > n2) return kthElement(nums2,nums1,k);
        int n = n1+n2;
        int leftLen = k;  // 1 is added to cover the odd case also

        int low = max(0,k-n2) ;
        int high =min(k,n1); // Range is on how many elements from arr1 can be part of Leftpart

        while(low <= high){
            int mid1 = (low+high)/2;
            int mid2 = leftLen-mid1;
            int l1 = mid1-1 >=0 ? nums1[mid1-1] : INT_MIN;
            int l2 = mid2-1 >=0 ? nums2[mid2-1] : INT_MIN;
            int r1 = mid1 < n1 ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < n2 ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }
            else if(l1  > r2){
                high = mid1-1;
            }
            else low = mid1+1;
            
        }
        return 0;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends