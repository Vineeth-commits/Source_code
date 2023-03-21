class Solution {
public:
    int size ; 
    vector<vector<string>>ans;
    bool check(int row,int col,vector<string>&board){
        //vertical upward check
        for(int i =0;i<=row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //main diagonal
        int i = row,j = col;
        while(i>=0&&j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;j--;
        }
        i = row,j = col;
        while(i>=0&&j<size){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;j++;
        }
        return true;
    }
    void helper(int row,vector<string>&board){
        if(row==size){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<size;j++){
            if(check(row,j,board)){
                board[row][j] = 'Q';
                helper(row+1,board);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        string temp="";
        for(int i =0;i<n;i++){
            temp+=".";
        }
        vector<string>board(n,temp);
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        helper(0,board);
        return ans;
    }
};