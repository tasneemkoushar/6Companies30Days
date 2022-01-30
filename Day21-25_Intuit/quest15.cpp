/*
    Koko Eating Banana - Same as Minimum Page Allocation
    Question Link: https://leetcode.com/problems/koko-eating-bananas/submissions/
*/

class Solution {
public:
    bool isValid(vector<int> piles, int barrier, int h)
    {
        int val=0, time=0;
        
        for(int i=0; i<piles.size(); i++){
            time+=(piles[i]/barrier);
            if(piles[i]%barrier) time++;
        }
        
        if(time>h) return false;
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            high=max(high,piles[i]);
        }
        
        int mid;
        int ans;
        while(low<=high){
            mid = (low+high)/2;
            
            if(isValid(piles, mid, h)){
                // cout<<ans<<" ";
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};