446. Arithmetic Slices II - Subsequence

Question Link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/?envType=daily-question&envId=2024-01-07

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long int n=nums.size(),d;
        vector<unordered_map<int,int>>v(n+1);
        long long int icnt=0,jcnt=0,ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                icnt=0,jcnt=0;
                d=(1LL*nums[i]-1LL*nums[j]);
                if(d<=INT_MIN or d>=INT_MAX)continue;
                if(v[i].count(d)) icnt=v[i][d];
                if(v[j].count(d)) jcnt=v[j][d];
                ans+=jcnt;
                v[i][d]=icnt+jcnt+1;
            }
        }
        return ans;
    }
};
