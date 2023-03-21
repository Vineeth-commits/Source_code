class Solution {
public:
    vector<vector<int>>ans;
    void helper(int ind,int target,vector<int>&temp,vector<int>&nums){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(ind==nums.size()){
            return;
        }
        if(nums[ind]<=target){
            temp.push_back(nums[ind]);
            helper(ind,target-nums[ind],temp,nums);
            temp.pop_back();
        }
        helper(ind+1,target,temp,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        helper(0,target,temp,candidates);
        return ans;
    }
};