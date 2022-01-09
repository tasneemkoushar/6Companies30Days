/*
    Rotten Organges
    Quedtion Link: https://leetcode.com/problems/rotting-oranges/
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]!=0)
                {
                    total++;
                }
            }
        }
        int time = 0, cnt=0, k, i,j;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty())
        {
            k = q.size();
            cnt+=k;
            while(k--)
            {
                i = q.front().first;
                j = q.front().second;
                q.pop();
                for(int z=0; z<4; z++)
                {
                    int nx = i + dx[z];
                    int ny = j + dy[z];
                    
                    if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});   
                }
                
            }
            if(!q.empty()) time++;
        }
        return total == cnt ? time : -1;
    }
};