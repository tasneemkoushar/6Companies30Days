/*
    Total No of Squares in N*N Chessboard
    Question Link: https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1
*/

long long squaresInChessBoard(long long N) {
        long long a[N];
        
        a[0] = 1;
        for(long long i=1; i<N; i++)
        {
            a[i] = pow(i+1,2) + a[i-1];
        }
        return a[N-1];
    }