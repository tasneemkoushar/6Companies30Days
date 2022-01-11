/*
    Count ways to Nth Stair
    Question Link: https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/
*/

class Solution
{
    public:
    long long countWays(int n)
    {
        if(n<=2)
        {
            return n;
        }
        return 1 + countWays(n-2);
    }
};
