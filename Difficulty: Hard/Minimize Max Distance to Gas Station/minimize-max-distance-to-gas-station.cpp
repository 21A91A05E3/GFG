//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findStationCnt(long double dist,vector<int>&stations){
        
        int totalStaCnt = 0;
        for(int i = 1 ; i < stations.size() ; i++){
            int diff = stations[i] - stations[i-1];
            int curStaCnt = diff/dist;
            
            if(stations[i]-stations[i-1] == dist*curStaCnt) curStaCnt--;
            
            totalStaCnt+=curStaCnt;
        }
        return totalStaCnt;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        long double  low = 0;
        long double high = 0;
        
        for(int i = 1 ; i < stations.size() ; i++){
            high = max(high,(long double)(stations[i]-stations[i-1]));
        }
        
        
        long double diff = 1e-6;
        while(high - low > diff){
            long double mid = (low+high)/2.0;
            
            int staCnt = findStationCnt(mid,stations);
            if(staCnt > k){
               
                low = mid;
            }
            else high = mid;
        }
        return high;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends