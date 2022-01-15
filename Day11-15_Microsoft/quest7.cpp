/*
    Unit area of largest regions of 1's
    Question Link: https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/#
*/

void bfs(int i,int j,vector<vector<int>>& grid,int &count,int n,int m){
       queue<pair<int,int>>q;
       q.push({i,j});
       vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
       
       while(!q.empty()){
           pair<int,int> node=q.front();
           q.pop();
           count++;
           for(int i=0;i<dir.size();i++){
               int x=node.first + dir[i].first;
               int y=node.second + dir[i].second;
               
               if(x>=n || x<0 || y>=m || y<0 || grid[x][y]!=1)continue;
               grid[x][y]=0;
               q.push({x,y});
           }
       }
   }
   
   int findMaxArea(vector<vector<int>>& grid) {
       // Code here
       
       int maxcount=1;
       int n=grid.size();
       int m=grid[0].size();
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==1){
                   int count=-1;
                   bfs(i,j,grid,count,n,m);
                   maxcount=max(maxcount,count);
               }
           }
       }
       return maxcount;
   }