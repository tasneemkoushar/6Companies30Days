/*
    Spirally traversing a matrix
    Question Link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/#
*/

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int left = 0, right = c-1, down = r-1, top = 0;
        int dir = 0;
        vector<int> ans;
        while(left<=right && top<=down)
        {
            if(dir==0)
            {
                for(int i=left; i<=right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir == 1)
            {
                for(int i=top; i<=down; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir == 2)
            {
                for(int i=right; i>=left; i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            else if(dir ==3)
            {
                for(int i=down; i>=top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir+=1;
            dir = dir%4;
        }
        return ans;
    }
};