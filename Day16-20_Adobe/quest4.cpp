/*
    Partition Equal Subset sum
    Question Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#
*/

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++)
        {
            sum+=arr[i];
        }
        if(sum & 1)
        {
            return 0;
        }
        sum/=2;
        vector<int> vec(sum+1,0);
        vec[0] = 1;
        for(int i=0; i<N; i++)
        {
            for(int j=sum; j>=arr[i]; j--)
            {
                vec[j] = vec[j] | vec[j-arr[i]];
            }
        }
        return vec[sum];
    }
};