/*
    Generate all combinations of Parenthesis
    Question Link: https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/
*/

class Solution
{
    public:
    void code(int open,int close,string op,vector<string>&ans){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }
        if(open!=0){
            string op1 = op;
            op1.push_back('(');
            code(open-1,close,op1,ans);
        }
        if(open<close){
            string op2 = op;
            op2.push_back(')');
            code(open,close-1,op2,ans);
        }
        return;
    }
    
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        string op ;
        code(n,n,op,ans);
        return ans;
    }
};