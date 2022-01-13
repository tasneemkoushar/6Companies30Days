/*
    Stock Span Problem
    Question Link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#
*/

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> ans;
       int cnt = 1;
       ans.push_back(1);
       for(int i=1; i<n; i++)
       {
           cnt = 1;
           if(price[i]>price[i-1])
           {
               cnt = ans[ans.size()-1];
               for(int j=i-cnt-1; j>=0; j--)
               {
                   if(price[j]<=price[i])
                   {
                       cnt++;
                   }
                   else{
                       break;
                   }
               }
               cnt++;
               ans.push_back(cnt);
           }
           else if(price[i]==price[i-1])
           {
               ans.push_back(ans[ans.size()-1]+1);
           }
           else{
               ans.push_back(cnt);
           }
           
       }
       return ans;
    }
};