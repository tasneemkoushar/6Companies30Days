/*
    Array Pair Sum Divisibility Problem
*/

bool canPair(vector<int> nums, int k) {
       int arr[k]={0};
      if(nums.size()&1)
      {
          return false;
      }
       for(int i=0; i<nums.size(); i++)
       {
           arr[nums[i]%k]++;
       }
       bool ans = true;
       
       for(int i=0; i<k; i++)
       {
           if(i==0)
          {
               if(arr[i]&1)
               {
                //   cout<<"hi";
                    ans = false;
                    break;
               }
              
           }
           else if(arr[i]!=arr[k-i])
               {
                //   cout<<"he";
                   ans = false;
                   break;
               }
           else if(arr[i]==arr[k-i])
               {
                   arr[k-i] = 0;
                   arr[i] = 0;
               }
           
       }
       return ans;
    }