/*
    Minium swaps to make binary grid
    Question Link: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/submissions/
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int j;
        vector<int> vec(n,0);
        for(int i=0; i<n; i++){
            for(j=n-1; j>=0; j--){
                if(grid[i][j]==1) break;
                vec[i]++;
            }
        }
        
        int ans = 0;
        int req;
        int val;
        
        for(int i=0; i<n; i++){
            req = n-i-1;
            for(j=i; j<n; j++){
                if(vec[j]>=req){
                    ans+=(j-i);
                    swap(vec[i],vec[j]);
                    break;
                }
                else{
                    swap(vec[i],vec[j]);
                }
            }
            if(j==n) return -1;
            
        }
        return ans;
        
    }
};