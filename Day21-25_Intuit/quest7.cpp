/*
    Minimum Ship Capacity to ship all packages in D Days - Same as Minimum Page Allocation
    Question Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

*/

class Solution {
public:
    bool isValid(vector<int> weight, int barrier, int k)
    {
        int days = 1;
        int val=0;
        for(int i=0; i<weight.size(); i++){
            if(weight[i]>barrier) return false;
            
            else if(val+weight[i]>barrier){
                days++;
                val = weight[i];
            }
            else{
                val+=weight[i];
            }
        }
         
        if(days>k) return false;
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high = 0;
        for(int i=0; i<weights.size(); i++){
            high+=weights[i];
            low = max(low,weights[i]);
        }
        
        int mid;
        int ans = 0;
        while(low<=high){
            mid = (low+high)/2;
            
            if(isValid(weights, mid, days)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
        
    }
};