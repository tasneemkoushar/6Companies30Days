/*
    Pots of Gold Game
    Question Link: https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/#
*/

class Solution {
public:
    int code(vector<int> &A, int left, int right, vector<vector<int>> &vec)
    {
        if(left>right){
            return 0;
        }
        if(vec[left][right]!=-1)
        {
            return vec[left][right];
        }
        int a = A[left] + min(code(A, left+1,right-1, vec), code(A, left+2, right, vec));
        int b = A[right] + min(code(A,left+1, right-1, vec), code(A, left, right-2, vec));
        vec[left][right] = max(a,b);
        return max(a,b);
    }
    int maxCoins(vector<int>&A,int n)
    {
        vector<vector<int>> vec(n,vector<int>(n,-1));
	    int sum = code(A,0,A.size()-1,vec);
	    return sum;
    }
};