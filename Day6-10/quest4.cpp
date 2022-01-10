/*
    Brackets in Matrix Chain Multiplication
    Question Link: https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/#
*/

class Solution{
public:
    unordered_map<string,pair<int,string>> dp;
    pair<int,string> MCM(int arr[],int i,int j){
        if(i>j){
            return {0,""};
        }
        if(i == j){
            return {0,""+string(1,'A'+(i-1))};
        }
        string key = to_string(i)+"#"+to_string(j);
        if(dp.find(key)!=dp.end()){
            return dp[key] ;
        }
        int ans = INT_MAX ;
        string str;
        for(int k = i;k<=j-1;k++){
            auto t1 = MCM(arr,i,k);
            auto t2 = MCM(arr,k+1,j);
            int temp = t1.first + t2.first + arr[i-1]*arr[j]*arr[k];
            if(ans>temp){
                ans = temp;
                str = t1.second + t2.second ;
            }
        }
        return dp[key] =  {ans,"("+str+")"} ;
    }
    
    string matrixChainOrder(int A[], int n) {
            return MCM(A, 1, n - 1).second;
    }
};