/*
    Minimum Sum Partition
    Question Link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#
*/

class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	   int val = 0;
	   for(int i=0; i<n; i++)
	   {
	       val+=arr[i];
	   }
	   int sum=val/2;
	   vector<vector<bool>> vec(n+1,vector<bool>(sum+1,false));
       vec[0][0] = true;
       for(int i=1; i<=n; i++)
       {
            for(int j=0; j<=sum; j++)
            {
                if(j==0)
                {
                    vec[i][j] = true;
                }
                else if(arr[i-1]<=j)
                {
                    vec[i][j] = vec[i-1][j] || vec[i-1][j-arr[i-1]];
                }
                else{
                    vec[i][j] = vec[i-1][j];
                }
            }
        }
	   int sum1=0,sum2=0;
	   for(int i=sum; i>=0; i--)
	   {
	       if(vec[n][i]==true)
	       {
	           sum1 = i;
	           break;
	       }
	   }
	   sum2 = val-sum1;
	   
	   return abs(sum2-sum1);
	   
	} 
};