/*
    Longest Arithmetic Progression
    Question Link: https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/#
*/

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2) return n;
        
        
        vector<unordered_map<int,int>> vec(n);
        int ans = 2;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dif = A[j]-A[i];
                if(vec[i].find(dif)!=vec[i].end()){
                    vec[j][dif] = vec[i][dif]+1;
                }
                else{
                    vec[j][dif] = 2;
                }
                ans = max(ans, vec[j][dif]);
            }
        }
        
        return ans;
    }
};