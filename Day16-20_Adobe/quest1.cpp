/*
    Subarray with given sum
    Question Link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#
*/

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
       int start = 0;
       int end = 0;
       long long int sum = 0;
       vector<int> ans;
       for(int i=0; i<n; i++)
       {
           sum+=arr[i];
           end = i;
           if(sum==s)
           {
               ans.push_back(start+1);
               ans.push_back(end+1);
               break;
           }
           else if(sum>s)
           {
               sum-=arr[start];
               sum-=arr[end];
               start++;
               i--;
           }
       }
       if(ans.size()==0)
       {
           ans.push_back(-1);
       }
       return ans;
    }
};