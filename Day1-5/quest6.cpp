/*
    Greatest Common Divisor of Strings
    Question Link : https://leetcode.com/problems/greatest-common-divisor-of-strings/
*/

string gcdOfStrings(string str1, string str2) {
       
        string ans = "";
        for(int i=0; i<str1.size() && i<str2.size(); i++)
        {
            if(str1[i]==str2[i])
            {
                ans+=str1[i];
            }
            else{
                break;
            }
        }
        if(ans=="")
        {
            return ans;
        }
        while(str1.size()%ans.size()!=0 || str2.size()%ans.size()!=0)
        {
            ans.pop_back();
        }
        int i=0;
        for(i=0; i<str1.size() && i<str2.size(); i+=ans.size())
        {
            if(ans!=str1.substr(i,ans.size()) || ans!=str2.substr(i,ans.size()))
            {
                ans = "";
                break;
            }
        }
        while(ans!="" && i<str1.size())
        {
            if(ans!=str1.substr(i,ans.size()))
            {
                ans = "";
                break;
            }
            i+=ans.size();
        }
        while(ans!="" && i<str2.size())
        {
            if(ans!=str2.substr(i,ans.size()))
            {
                ans = "";
                break;
            }
            i+=ans.size();
        }
         return ans;
    }