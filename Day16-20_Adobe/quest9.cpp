/*
    Next greater Palindrome number.
    Question Link: https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/#
*/

class Solution{
  public:
    string nextPalin(string N) { 
        int len = N.size();
       
            int last = len/2;
            bool val = next_permutation(N.begin(),N.begin()+last);
           
            if(val==false)
            {
                return "-1";
            }
            for(int i=0; i<last; i++)
            {
                N[N.size()-1-i] = N[i];
            }
        
        return N;
    }
};