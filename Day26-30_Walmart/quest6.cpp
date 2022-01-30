/*
    Power of Numbers
    Question Link: https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart
*/
class Solution{
    public:
    //You need to complete this fucntion
    long long power(int N,int R)
    {
        long long ans = 1;
        long long n = N;
        while(R>0)
        {
            if(R & 1)
            {
                ans = ans*n;
                ans%=mod;
                R = R-1;
            }    
            else{
               
                 n = n*n;
                 n%=mod;
                 R/=2;
            }
            
        }
        return ans;
    }

};