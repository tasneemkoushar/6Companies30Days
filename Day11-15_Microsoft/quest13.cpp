/*
    Bridge Edge in a graph
    Question Link: https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1#
*/

class Solution
{
	public:
    void makeSet(vector<int> &parent, vector<int> &size, int v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    
    int findSet(vector<int> &parent, int v)
    {
        if(parent[v] == v)
        {
            return v;
        }
        return parent[v] = findSet(parent, parent[v]);
    }
    
    void makeUnion(int a, int b, vector<int> &parent, vector<int> &size)
    {
        a = findSet(parent,a);
        b = findSet(parent,b);
        if(a!=b)
        {
            if(size[a]<size[b])
            {
                swap(a,b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
        
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> parent(V);
        vector<int> size(V);
        int ans = 1;
        for(int i=0; i<V; i++)
        {
            makeSet(parent,size,i);
        }
        for(int i=0; i<V; i++)
        {
            int a = i;
            for(int j=0; j<adj[i].size(); j++)
            {
                int b = adj[i][j];
                if(!(a==c && b==d||a==d && b==c))
                {
                    makeUnion(a, b, parent, size);
                }
            }
        }
        if(findSet(parent, c) == findSet(parent, d))
        {
            ans = 0;
        }
        return ans;
        
    }
};