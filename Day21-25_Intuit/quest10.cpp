/*
    Number of Provinces
    Question Link: https://leetcode.com/problems/number-of-provinces/submissions/
*/

class Solution {
public:
    void dfs(int curr,vector<bool> &visited,vector<vector<int>> &adj){
        visited[curr]=true;
        
        for(auto it:adj[curr]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                count++;
            }
        }
        
        return count;
    }
};