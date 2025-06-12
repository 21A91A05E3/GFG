/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n = arr.size();
        map<int,int>mp;
        int curSum = 0 , maxlen = 0;
        for(int i = 0 ; i < n ; i++){
            curSum+=arr[i];
            if(curSum == 0) maxlen = max(maxlen,i+1);
            if(mp.find(curSum) != mp.end()){
                maxlen = max(maxlen,i-mp[curSum]);
            }else{
                mp[curSum] = i;
            }
        }
        return maxlen;
        
    }
};