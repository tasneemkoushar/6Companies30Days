/*
    Prerequisite Task
    Question Link: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/#
*/


class Solution {
public:
    bool isCyclic(vector<int> adj[], vector<int> &vis, int curr)
    {
        if(vis[curr]==2)
        {
            return true;
        }
        vis[curr] = 2;
        for(int i=0; i<adj[curr].size(); i++)
        {
            if(vis[adj[curr][i]]!=1)
            {
                if(isCyclic(adj,vis,adj[curr][i])) return true;
            }
        }
        vis[curr] = 1;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    
	    vector<int> adj[N];
	    for(int i=0; i<prerequisites.size(); i++)
	    {
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    vector<int> vis(N,0);
	    
	    for(int i=0; i<N; i++)
	    {
	        if(vis[i]==0)
	        {
	            if(isCyclic(adj,vis,i)) return false;
	        }
	    }
	    return true;
	}
};