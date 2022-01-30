/*
    Remove Colored Pieces if Both Neighbor are of same colors
    Question Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
*/

//Counting no of options Alice has and no of Option Bob has and then Comparing them.
class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0;
        int b = 0;
        
        for(int i=0; i<colors.size(); i++){
            char ch = colors[i];
            int j = i+1;
            while(j<colors.size() && colors[j]==ch){
                j++;
            }
            j--;
            if(ch=='A')
                a+=max(0, (j-i+1) - 2);
            else
                b+=max(0, (j-i+1) -2);
            i=j;
        }
        return a>b;
    }
};