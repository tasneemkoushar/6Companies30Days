/*
    Path with Maximum Probability - used Dijkstra's Algorithm using Max Priority Queue
    Question Link: https://leetcode.com/problems/path-with-maximum-probability/submissions/
*/

class Solution {
public:
    
    double code(vector<vector<pair<int, double>>> &adj, int V, int S, int end){
        priority_queue<pair<double,int>, vector<pair<double,int>>> pq;
        vector<double> disTo(V, INT_MIN);
        disTo[S] = 1.0;
        pq.push({0,S});
        
        while(!pq.empty()){
            double dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            
            for(auto it: adj[prev]){
                
                int next = it.first;
                double dist = it.second;

                if(disTo[next] < dist*disTo[prev]){
                    disTo[next] = dist*disTo[prev];
                    pq.push({disTo[next], next});
                }
            }
        }
        return disTo[end];
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        double ans = code(adj, n, start, end);
        return (ans != INT_MIN) ? ans : 0;
    }
};