class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&temp,vector<bool>&vis,vector<int>&nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i =0;i<nums.size();i++){
            if(vis[i]==false){
                temp.push_back(nums[i]);
                vis[i] = true;
                helper(temp,vis,nums);
                vis[i] = false;
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        int n = nums.size();
        vector<bool>vis(n,false);
        helper(temp,vis,nums);
        sort(ans.begin(),ans.end());
        return ans;
    }
};