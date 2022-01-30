/*
    Find in Mountain array
    Question Link: https://leetcode.com/problems/find-in-mountain-array/
*/


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0, high = n-1;
        int cnt = 1;
        int mid, index=-1;
        int mnt;
        while(low<=high){
            mid = (low+high)/2;
            if(mid>0 && mid<n-1){
                int prev = mountainArr.get(mid-1);
                int curr = mountainArr.get(mid);
                int next = mountainArr.get(mid+1);
                
                if(curr>prev && curr>next){
                    index = mid;
                    mnt = curr;
                    break;
                }
                else if(prev>curr)
                {
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            } 
            else{
                int curr = mountainArr.get(0);
                int next = mountainArr.get(1);
                cnt+=2;
                if(curr>next)
                {
                    mnt = curr;
                    index = 0;
                    break;
                }
                else{
                    index = 1;
                    mnt = next;
                    break;
                }
                next = mountainArr.get(n-1);
                curr = mountainArr.get(n-2);
                cnt+=2;
                if(next>curr)
                {
                    cnt+=2;
                    index = n-1;
                    mnt = next;
                    break;
                }
                else{
                    index = n-2;
                    mnt = curr;
                    break;
                }
            }
        }
        
        if(cnt>100 || target>mnt) return -1;
        if(target==mnt) return index;
        int low1 = 0;
        int high1 = index;
        int low2=index+1;
        int high2 = n-1;
        int mid1, mid2;
        while(low1<=high1)
        {
            mid1 = (low1+high1)/2;
            int val = mountainArr.get(mid1);
            cnt++;
            if(target==val)
            {
               if(cnt<=100) return mid1;
                return -1;
            }
            else if(target>val)
            {
                low1 = mid1+1;
            }
            else{
                high1 = mid1-1;
            }
        }
        
        while(low2<=high2)
        {
            mid2 = (low2+high2)/2;
            int val = mountainArr.get(mid2);
            cnt++;
            if(target==val)
            {
                if(cnt<=100) return mid2;
                return -1;
            }
            else if(target>val)
            {
               high2 = mid2-1;
            }
            else{
                low2 = mid2+1;
            }
        }
        
        return -1;
    }
};