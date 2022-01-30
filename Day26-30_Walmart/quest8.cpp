/*
    Maximum Height Tree
    Question Link: https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart#
*/
class Solution{
public:
    int height(int N){
        return (-1+pow(1+8*N,0.5))/2;
    }
};