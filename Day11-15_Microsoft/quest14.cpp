/*
    Minimum number of steps to reach destination
    Question Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/#
*/

// My Recursive Code giving TLE
    vector<vector<int>> dp{2001,vector<int> (2001,-1)};
    int solve(int src, int ctr, int dest){
        if(abs(src) > abs(dest)){
            return INT_MAX;
        }
        if(src == dest){
            return ctr-1;
        }
        
        if(src < 0){
            if(dp[abs(src - 1001)][ctr] != -1)  return dp[abs(src - 1001)][ctr];
        }
        else{
            if(dp[src][ctr] != -1)  return dp[src][ctr];
        }
            
        
        int l = solve(src+ctr,ctr+1,dest);
        int r = solve(src-ctr,ctr+1,dest);
        
        if(src < 0){
            dp[abs(src - 1001)][ctr] = min(l,r);      
        }
        else{
            dp[src][ctr] = min(l,r); 
        }
        
        return min(l,r);
    }
    int minSteps(int D){
        int x = solve(0,1,D);
        return x;
    }    

//Solution without recursion
class Solution{
public:
    int minSteps(int D){
        int steps = 0, sum = 0;
        while(true){
            sum = sum + steps;
            steps++;
            if(sum == D){
                return steps-1;
                break;
            }
            if(sum > D and (sum-D)%2 == 0){
                return steps-1;
                break;
            }
        }
        return 0;
    }
};