/*
    Number of Distinct words with atmost K contiguous vowels
    Question Link: https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/
*/

class Solution
{
  public:
    long long dp[1001][1001], MOD = 1000000007;
    
    long long code(int n, int cnt, int k){
        if(n == 0) return 1;
        
       if(dp[n][cnt] != -1) return dp[n][cnt]%MOD; 
        
        if(cnt == k) return dp[n][cnt] = ((21%MOD)*(code(n-1, 0, k))%MOD)%MOD;
        
        
        return dp[n][cnt] = (((21%MOD)*(code(n-1, 0, k))%MOD)%MOD + (5*(code(n-1, cnt+1, k))%MOD)%MOD)%MOD;
    }
    int kvowelwords(int N, int K) {
        
        memset(dp,-1,sizeof(dp)) ;
        
        return code(N,0,K);
        
    }
};