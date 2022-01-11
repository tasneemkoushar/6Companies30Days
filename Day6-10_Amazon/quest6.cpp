/*
    Maximum of all subarrays of size K - same as question 3 (IPL2021)
    Question Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#
*/

vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> d;
        int start = 0;
        for(int i=0; i<n; i++)
        {
            if(!d.empty() && d.front() < start)
            {
                d.pop_front();
            }
            while(!d.empty() && arr[d.back()]<arr[i])
            {
                d.pop_back();
            }
            d.push_back(i);
            if(i == start + k -1)
            {
                ans.push_back(arr[d.front()]);
                start++;
            }
        }
        return ans;
    }