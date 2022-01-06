/*
    Longest Mountain
    Question Link: https://leetcode.com/problems/longest-mountain-in-array/
*/

int longestMountain(vector<int>& arr) {
        int ans = 0;
        int len1 = 0;
        int len2 = 0;
        for(int i=0; i<arr.size()-1; i++)
        {
                int j = i;
                if(arr[i+1]>arr[i])
                {
                    len1++;
                }
                else if(arr[i+1]<arr[i] && len1!=0)
                {
                    len1+=1;
                    int j = i;
                    while(j+1<arr.size() && arr[j+1]<arr[j])
                    {
                        j++;
                        len2++;
                    }
                    if(len2!=0)
                    {
                        ans = max(ans,len1+len2);
                    }
                    len1 = 0;
                    len2 = 0;
                    i = j-1;
                    
                }
            else if(arr[i+1]==arr[i] && len1!=0)
            {
                len1 = 0;
            }
        }
        return ans;
    }