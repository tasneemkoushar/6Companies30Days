/*
    Minimum Size Subaary Sum
    Question Link: https://leetcode.com/problems/minimum-size-subarray-sum/
*/
int minSubArrayLen(int target, vector<int>& nums) {
        int ptr1=0, ptr2=0;
        int ans = INT_MAX;
        int sum = 0;
        
        while(ptr2<nums.size())
        {
            sum = sum + nums[ptr2] ;
            if(sum >= target){
                ans = min(ans,ptr2-ptr1+1);
                while(sum>=target){
                    ans = min(ans,ptr2-ptr1+1) ;
                    sum = sum-nums[ptr1];
                    ptr1++;
                }
            }
            ptr2++;    
        }
        if(ans==INT_MAX)
        {
            return 0;
        }
        return ans;
    }