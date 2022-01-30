/*
    Word Search
    Question Link: https://practice.geeksforgeeks.org/problems/word-search/1/
*/

class Solution {
public:
    bool code(vector<vector<char>> board, vector<vector<int>> &vis, string wrd, int index, int i, int j){
        
        if(index==wrd.size()-1){
            return true;
        }
        
        // if(board[i][j]==wrd[index]){
            vis[i][j] = 1;
            if(i+1<board.size() && !vis[i+1][j] && board[i+1][j] == wrd[index+1] && code(board, vis, wrd, index+1, i+1, j)){
                return true;
            }
            if(j+1<board[0].size() && !vis[i][j+1] && board[i][j+1] == wrd[index+1] && code(board, vis, wrd, index+1, i, j+1)){
                return true;
            }
            if(i-1>=0 && !vis[i-1][j] && board[i-1][j] == wrd[index+1] && code(board, vis, wrd, index+1, i-1, j)){
                return true;
            }
            if(j-1>=0 && !vis[i][j-1] && board[i][j-1] == wrd[index+1] && code(board, vis, wrd, index+1, i, j-1)){
                return true;
            }
            vis[i][j] = 0;
        // }
        return false;
        
        
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0] && code(board, vis, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
};