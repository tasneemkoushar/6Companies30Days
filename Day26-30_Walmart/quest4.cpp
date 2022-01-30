/*
    Number of Unique paths
    Question Link: https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1/#
*/
class Solution
{
    public:
 
    int NumberOfPath(int a, int b)
    {
       vector<vector<int>> vec(a, vector<int>(b,0));
       
       vec[a-1][b-1] = 1;
       for(int i=a-1; i>=0; i--){
           for(int j=b-1; j>=0; j--){
               if(i+1<a) vec[i][j]+=vec[i+1][j];
               if(j+1<b) vec[i][j]+=vec[i][j+1];
           }
       }
       return vec[0][0];
    }
};