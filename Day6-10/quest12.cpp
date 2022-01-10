/*
    Column name for a given Column Number
    Question Link: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/
*/

class Solution{
    public:
    string colName (long long int n)
    {
        string s="";
        char sam = 'A';
        long long int rem = 0;
        while(n>0)
        {
            rem = n%26;
            if(rem == 0){
               s+='Z';
               n = n/26 -1;
            }
            else{
                rem-=1;
                sam = 'A';
               sam+=rem; 
               n/=26;
               s+=sam;
            }
            
        }
        reverse(s.begin(),s.end());
        return s;
    }
};