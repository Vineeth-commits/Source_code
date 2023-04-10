class Solution {
public:
    //int n=9,m=9;
    bool check(int row,int col,char dig,vector<vector<char>>& board){
        //horizontal
        for(int j =0;j<9;j++){
            if(board[row][j]==dig){
                return false;
            }
        }
        //vertical
        for(int i =0;i<9;i++){
            if(board[i][col]==dig){
                return false;
            }
        }
        int x = (row/3)*3;
        int y = (col/3)*3;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(board[x+i][y+j]==dig){
                    return false;
                }
            }
        }
         return true;
    }
    bool helper(int row,int col,vector<vector<char>>& board){
        
        if(row>=9){
            return true;
        }
        if(col==9){
            return helper(row+1,0,board);
        }
        if(board[row][col]!='.'){
            return helper(row,col+1,board);
        }
        for(char c ='1';c<='9';c++){
            if(check(row,col,c,board)){
                board[row][col] = c;
                if(helper(row,col+1,board)){
                    return true;
                }
                board[row][col] ='.';
            }
        }
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        //int n = board.size();
        //int m = board[0].size();
        helper(0,0,board);
    }
};