493
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

  =================================================================================================================================================================================================

class Solution {
public:
    int ans=0;
    void merge(int l,int m,int h,vector<int>& nums)
    {
        int i=l,j=m+1,k=l,ti,tj;
        int temp[h+1];
        ti=l,tj=m+1;

        while(ti<=m and tj<=h)
        {
            if(nums[ti]<=1LL*2*nums[tj]) ti+=1;
            else
            {
                ans+=m+1-ti;
                tj+=1;
            }
        }
        
        while(i<=m and j<=h)
        {
            if(nums[i]<nums[j])temp[k++]=nums[i++];
            else temp[k++]=nums[j++];
        }

        while (i <= m) {
            temp[k++] = nums[i++];
        }

        while(j<=h){
             temp[k++]=nums[j++];
        }

        for(int i=l;i<=h;i++)
        {
            nums[i]=temp[i];
        }
    }
    void mergesort(int l,int h,vector<int>& nums)
    {
        int m=l+(h-l)/2;
        if(l>=h)return;
        mergesort(l,m,nums);
        mergesort(m+1,h,nums);
        merge(l,m,h,nums);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergesort(0,n-1,nums);
        return ans;
        
    }
};
