/*
    Total Decoding Messages
	Question Link: https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/
*/

class Solution {
	public:
		int CountWays(string str){
		   int mod = 1000000007;
		   if(str.size()==0 || str[0]=='0')
		   {
		       return 0;
		   }
		   if(str.size()==1)
		   {
		       return 1;
		   }
		   
		   int cnt1 = 1;
		   int cnt2 = 1;
		   
		   for(int i=1; i<str.size(); i++)
		   {
		       string s1 = "";
		       s1+=str[i];
		       string s2 = "";
		       s2+=str[i-1];
		       s2+=str[i];
		       int cnt = 0;
		       if(s1>"0")
		       {
		           (cnt += cnt2)%=mod;
		       }
		       if(s2>="10" && s2<="26")
		       {
		           (cnt += cnt1)%=mod;
		       }
		       cnt1 = cnt2;
		       cnt2 = cnt;
		   }
		   return cnt2;
		}

};