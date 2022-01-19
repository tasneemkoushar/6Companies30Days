/*
    Election
    Questions Link: https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/#
*/

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string,int>m;
        for(int i=0; i<n; i++){
            m[arr[i]]++;
            
        }
        vector<string>ans(2);
        int val = INT_MIN;
        string str = "";
        for(auto i:m)
        {
            if(i.second>val)
            {
                val = i.second;
                str = i.first;
            }
        }
        ans[0] = (str);
        ans[1] = to_string(val);
        return ans;
    }
};