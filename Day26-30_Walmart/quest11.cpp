/*  
    Maximum Performance of a Team
    Question Link: https://leetcode.com/problems/maximum-performance-of-a-team/
*/
class Solution {
public:    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = 1000000007;
        vector<pair<int,int>> vec;
        for(int i=0; i<speed.size(); i++){
            vec.push_back({efficiency[i],speed[i]});
        }
        
        sort(vec.rbegin(),vec.rend());
        priority_queue<int> q;
        long ans = 0, sum=0;
        for(int i=0; i<vec.size(); i++){     
            sum+=vec[i].second;
            if(q.size()==k){
                sum+=q.top();
                q.pop();
            }
            q.push(-vec[i].second);
            
            long pro = (long)sum*vec[i].first;
            ans = max(ans,pro);
        }
        return ans%=mod;
    }
};