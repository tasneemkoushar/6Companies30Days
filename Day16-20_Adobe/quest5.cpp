/*
    Express as sum of power of natural numbers
    Question Link: https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1#
*/

class Solution{
    public:
    int mod = 1000000007;
    vector<vector<int>> dp;

    int code(int n, int x, int curr) {
        if(n == 0) 
        return 1;
        else if(curr == 0) 
        return 0;
        int &ans = dp[n][curr];
        if(ans != -1) 
        return ans;
        int power = pow(curr, x);
        return ans = ((n - power >= 0 ? code(n - power, x, curr - 1): 0)%mod + code(n, x, curr - 1)%mod)%mod;
    }
    
    int numOfWays(int n, int x) {
        int num = pow(n, 1.0 / x);
        dp.resize(n + 1, vector<int>(num + 1, -1));
        return code(n, x, num);
    }
    
    
};