/*
    Possible Words from Phone Digit
    Question Link: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/#
*/

class Solution
{
    public:
    void findval(vector<string> code, int index, int i, string val, vector<string> &ans)
    {
        if(index == code.size())
        {
            ans.push_back(val);
            return;
        }
        
        for(int j=0; j<code[index].size();j++)
        {
            findval(code, index+1, j, val+code[index][j], ans);
        }
        
    }
    vector<string> possibleWords(int arr[], int N)
    {
        vector<string> code;
        for(int i=0; i<N; i++)
        {
            if(arr[i]==2)
            {
                code.push_back("abc");
            }
            else if(arr[i]==3)
            {
                code.push_back("def");
            }
            else if(arr[i]==4)
            {
                code.push_back("ghi");
            }
            else if(arr[i]==5)
            {
                code.push_back("jkl");
            }
            else if(arr[i]==6)
            {
                code.push_back("mno");
            }
            else if(arr[i]==7)
            {
                code.push_back("pqrs");
            }
            else if(arr[i]==8)
            {
                code.push_back("tuv");
            }
            else if(arr[i]==9)
            {
                code.push_back("wxyz");
            }
        }
        vector<string> ans;
        string val = "";
        findval(code, 0, 0, val, ans);
        return ans;
    }
};