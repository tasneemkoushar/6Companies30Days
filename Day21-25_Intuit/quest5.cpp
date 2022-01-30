/*
    Split array Largest Sum, Same as Allocate Minimum Number of Pages
    Question Link: https://leetcode.com/problems/split-array-largest-sum/
*/

class Solution {
public:
    
    //Function to Check is the mid value if valid barrier or not
    bool isvalid(vector<int> nums, int barrier, int k){
        int tot = 1, val = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>barrier) return false;
            if(val+nums[i]>barrier){
                tot+=1;
                val = nums[i];
            }
            else{
                val+=nums[i];
            }
        }
        
        if(tot>k) return false;
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low=INT_MAX, high=0;
        for(int i=0; i<nums.size(); i++){
            low = min(nums[i],low);
            high += nums[i];
        }
        
        //Binary Search
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            
            if(isvalid(nums, mid, m)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            
        }
        
        return low;
    }
};
