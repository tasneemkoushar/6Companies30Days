/*
    Is Sudoku Valid
    Question Link: https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/
*/

class Solution{
public:
   
bool isvalid(int row,int col,int num,vector<vector<int>>mat){
    for(int i = 0;i<9;i++){
        if(mat[row][i] == num){
            return false;
        }
        if(mat[i][col] == num){
            return false;
        }
        if(mat[3*(row/3)+i/3][3*(col/3)+i%3] == num){
            return false;
        }
    }
    return true;
}
int isValid(vector<vector<int>> mat){
        vector<vector<int>> dup(9,vector<int>(9,0)) ;

        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(mat[i][j] == 0){
                    continue ;
                }
                if(isvalid(i,j,mat[i][j],dup)){
                    dup[i][j] = mat[i][j] ;
                }
                else{
                    return 0;
                }
            }
        }
        return 1;
    }
int isvalid_2(vector<vector<int>> mat){
    bool row[9][9] = {false},col[9][9] = {false},box[9][9] = {false} ;
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(mat[i][j] == 0){
                continue ;
            }
            int num = mat[i][j] ;
            int idx = 3*(i/3) +j/3 ;
            if(row[i][num-1] || col[j][num-1] || box[idx][num-1]){
                return 0;
            }
            row[i][num-1] = col[j][num-1] = box[idx][num-1] = true;
        }

    }
    return 1;
    }
};