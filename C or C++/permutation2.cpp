class Solution {
public:
    void helper(int index,int n,vector<int>&nums,set<vector<int>>&ans){
        if(index>n)return;
        if(index==n){
            ans.insert(nums);
            return;
        }
        for(int i = index;i<n;i++){
            swap(nums[i],nums[index]);
            helper(index+1,n,nums,ans);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       set<vector<int>>ans;
        int n = nums.size();
        helper(0,n,nums,ans);
        vector<vector<int>>res;
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};