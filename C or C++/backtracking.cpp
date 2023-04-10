class Solution {
public:
    vector<string>ans;
    unordered_map<char,string>mp;
    void helper(int index,string s,string digits){
        if(s.length()==digits.length()){
            ans.push_back(s);
            return;
        }
        for(int i = index;i<digits.length();i++){
            char ch= digits[i];
            for(int j =0;j<mp[ch].size();j++){
                char cha = mp[ch][j];
                s.push_back(cha);
                helper(i+1,s,digits);
                s.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
       mp['2'] = "abc"; 
        mp['3'] = "def"; 
        mp['4'] = "ghi"; 
        mp['5'] = "jkl"; 
        mp['6'] = "mno"; 
        mp['7'] = "pqrs"; 
        mp['8'] = "tuv"; 
        mp['9'] = "wxyz"; 
        string s;
        if(digits.size()==0){
            return {};
        }
        helper(0,s,digits);
        return ans;
        
    }
};