/*
    IPL2021  MatchDay-2
    Question Link: https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/
*/

vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
       priority_queue<pair<int,int>> q;
       vector<int> vec;
       for(int i=0; i<k; i++)
       {
           q.push({arr[i],i});
       }
       vec.push_back(q.top().first);
       for(int i=k; i<n; i++)
       {
           if(i-k==q.top().second)
           {
               int index = q.top().second;
               while(!q.empty())
               {
                   if(q.top().second<=index)
                   {
                       q.pop();
                   }
                   else{
                       break;
                   }
               }
               q.push({arr[i],i});
               vec.push_back(q.top().first);
           }
           else{
               q.push({arr[i],i});
               vec.push_back(q.top().first);
           }
       }
       return vec;
    }