/*
    Rotate Matrix by 90
    QuestionLink: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/
*/

void rotate(vector<vector<int> >& matrix)
{
    for(auto &i: matrix)
    {
        reverse(i.begin(),i.end());
    }
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=i; j<matrix[i].size(); j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}