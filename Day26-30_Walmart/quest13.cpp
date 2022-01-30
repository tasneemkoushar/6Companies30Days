/*
    Find the Kth Largest Integer in an array
    Question Link: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
*/

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<priority_queue<string>> vec(101, priority_queue<string>());
        for(int i=0; i<nums.size(); i++)
        {
            
            vec[nums[i].size()].push(nums[i]);
        }
        string ans = "";
        for(int i=100; i>=0; i--)
        {
            if(vec[i].size()<k && vec[i].size()!=0)
            {
                k-=vec[i].size();
            }
            else if(vec[i].size()>=k)
            {
                while(!vec[i].empty())
                {
                    if(k==1) return vec[i].top();
                    vec[i].pop();
                    k--;
                }
            }
        }
        return ans;
    }
};