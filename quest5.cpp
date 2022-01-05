/*
    Find Nth Ugly number
	Question Link: https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
*/

ull getNthUglyNo(int n) {
	    ull arr[n];
	    arr[0] = 1;
	    int i2 = 0, i3 = 0, i5 = 0;
	    ull minNum = 1;
	    ull next_2 = 2;
	    ull next_3 = 3;
	    ull next_5 = 5;
	    
	    for(int i=1;i<n;i++)
	    {
	        minNum = min(next_2,next_3);
	        minNum = min(minNum, next_5);
	        arr[i] = minNum;
	        if(arr[i] == arr[i2]*2)
	        {
	            i2++;
	            next_2 = arr[i2]*2;
	        }
	        if(arr[i] == arr[i3]*3)
	        {
	            i3++;
	            next_3 = arr[i3]*3;
	        }
	        if(arr[i] == arr[i5]*5)
	        {
	            i5++;
	            next_5 = arr[i5]*5;
	        }
	    }
	    return minNum;
	}