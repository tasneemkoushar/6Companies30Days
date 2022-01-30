/*  
    Largest Number in K swaps
    Question Link: https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1/
*/

class Solution
{
    public:
    string ans;
    void code(string s, int k, int index){
        int n = s.size();
        if(k == 0){
            return ;
        }
        for(int i = index; i<n-1; i++ ){
            for(int j = i+1; j<n; j++){
                if(s[j]>s[i]){
                    swap(s[i],s[j]);
                    if(ans<s){
                        ans = s;
                    }
                    code(s, k-1, i+1);
                    swap(s[i],s[j]);
                }
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
        ans = str;
       code(str, k, 0);
       return ans;
    }
};