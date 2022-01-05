/*
    Find the Kid which gets the damaged toy
    Question Link: https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1/
*/

int findPosition(int N , int M , int K) {
        int n = (K+M-1<=N)?K+M-1:((K+M-1)%N);
        if(n==0)
        {
            return N;
        }
        return n;
    }