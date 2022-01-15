/*
    Alien Dictionary
    Question Link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1/#
*/

class Solution{
    public:
    void DFS_sort(map<char,vector<char>>& Adj, set<char>&visited, char v, string& order)
    {
        visited.insert(v);
        for(auto u: Adj[v])
        {
            if(!visited.count(u))
                DFS_sort(Adj, visited, u, order);
        }
        order = v + order;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        map<char,vector<char>> Adj;
        auto compare = [&Adj](string& s1, string& s2)
        {
          for(int i=0; i<s1.size()&&i<s2.size();i++)
          {
              if(s1[i]!=s2[i])
              {
                Adj[s1[i]].push_back(s2[i]);
                return;
              }
          }
        };
        
        for(int i=0;i<N-1;i++)
        {
            compare(dict[i], dict[i+1]);
        }
        
        string ans;
        set<char> visited;
        for(auto p: Adj)
        {
            if(!visited.count(p.first))
                DFS_sort(Adj, visited, p.first, ans);
        }
            
        return ans;
    }
};