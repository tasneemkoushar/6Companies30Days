/*
    Leaders in an array
    Question Link: https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/#
*/

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
       vector<int> vec;
       int mx = a[n-1];
       vec.push_back(mx);
       for(int i=n-2; i>=0; i--){
           if(a[i]>=mx)
           {
               vec.push_back(a[i]);
           }
           mx = max(a[i],mx);
       }
       int i=0;
       int j = vec.size()-1;
       while(i<j)
       {
           swap(vec[i],vec[j]);
           i++;
           j--;
       }
       return vec;
    }
};