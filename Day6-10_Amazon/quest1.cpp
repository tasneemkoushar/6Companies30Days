/*
    Maximum Profit
    Question Link: https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#
*/

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        int ans = 0;
        if(K>N/2)
        {
            for(int i=1; i<N; i++)
            {
                if(A[i]>A[i-1])
                {
                    ans+=(A[i]-A[i-1]);
                }
            }
        }
        else{
            vector<vector<int>> vec(K+1, vector<int>(N,0));
            int mx_dif = -A[0];
            for(int i=1; i<K+1; i++)
            {
                mx_dif = -A[0];
                for(int j=1; j<N; j++)
                {
                    vec[i][j] = max(vec[i][j-1], A[j] + mx_dif);
                    mx_dif = max(mx_dif,vec[i-1][j]-A[j]);
                }
            }
            ans = vec[K][N-1];
        }
        return ans;
    }
};