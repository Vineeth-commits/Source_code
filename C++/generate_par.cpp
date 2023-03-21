class Solution {
public:
    vector<string>v;
    void helper(int open,int close,int n,string s){
        if(open==n&&close==n){
            v.push_back(s);
            return;
        }
        if(open<n){
            helper(open+1,close,n,s+"(");
        }
        if(close<open){
            helper(open,close+1,n,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return v;
    }
};