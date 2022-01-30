/*
    Stone Game - similar to Gold Pot in Adobe Sheet
    Question Link: https://leetcode.com/problems/stone-game/submissions/
*/

class Solution {
public:
    int code(vector<int> &piles, int left, int right, vector<vector<int>> &vec)
    {
        if(left>right){
            return 0;
        }
        if(vec[left][right]!=-1) return vec[left][right];
        int a = piles[left] + min(code(piles, left+1, right-1, vec), code(piles, left+2, right, vec));
        int b = piles[right] + min(code(piles, left+1, right-1, vec), code(piles, left, right-2, vec));
        vec[left][right] = max(a,b);
        return max(a,b);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>>vec(piles.size(), vector<int>(piles.size(),-1));
        return code(piles, 0, piles.size()-1, vec);
    }
};