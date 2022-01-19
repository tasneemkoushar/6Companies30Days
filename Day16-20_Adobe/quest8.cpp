/*
    ATOI
    Question Link: https://practice.geeksforgeeks.org/problems/implement-atoi/1/#
*/

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        
        int num = 0;
        int sgn = 1;
        for(int i=0; str[i]; i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                num*=10;
                num+=(str[i]-'0');
            }
            else if(str[i]=='-' && i==0)
            {
                sgn = -1;
            }
            else{
                num = -1;
                break;
            }
        }
        return (num==-1)?-1:num*sgn;
    }
};