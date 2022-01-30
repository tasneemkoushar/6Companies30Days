/*  
    As far from Land As Possible
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        vector<int> offsets={1,0,-1,0,1};
        int n=grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<pair<int,int>,pair<int,int>>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    vis[i][j]=true;
                    q.push({{i,j},{i,j}});
                }
            }
        }
        int maxi=-1;
        while(!q.empty())
        {
            int l=q.size();
            for(int k=0;k<l;k++)
            {
                auto [s,t]=q.front();
                auto [i,j]=s;
                auto [landX,landY]=t;
                q.pop();
                for(int p=0;p<4;p++)
                {
                    int x=i+offsets[p];
                    int y=j+offsets[p+1];
                    if(x<0 || y<0 || x>=n || y>=n || vis[x][y])
                        continue;
                    vis[x][y]=true;
                    maxi=max(maxi,abs(x-landX)+abs(y-landY));
                    q.push({{x,y},{landX,landY}});
                }
            }
        }
        return maxi;
        
    }
};