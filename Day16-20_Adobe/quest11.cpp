/*
    String Amendment
    Question Link: https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1#
*/

class Solution{
    public:
    string amendSentence (string s)
    {
        string ans = "";
        ans+=tolower(s[0]);
        for(int i=1; s[i]; i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                ans+=' ';
                ans+=tolower(s[i]);
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};