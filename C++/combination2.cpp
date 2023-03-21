class Solution {
public:
    vector<vector<int>>ans;
    void helper(int ind,int target,vector<int>&temp,vector<int>& nums){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i = ind;i<nums.size();i++){
            if(i>ind&&nums[i]==nums[i-1])continue;
            if(nums[i]<=target){
                temp.push_back(nums[i]);
                helper(i+1,target-nums[i],temp,nums);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<int>temp;
        helper(0,target,temp,candidates);
        
        return ans;
    }
};