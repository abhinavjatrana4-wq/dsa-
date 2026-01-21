class Solution {
    private:
    void getperm(vector<int>& nums , vector<vector<int>>& ans , int index ){
        // base case 
        if(index >= nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i = index ; i < nums.size() ; i++){
            // swap the g
            swap(nums[index] , nums[i]);
            getperm(nums , ans , index+ 1);
            // backtracking
swap(nums[index] , nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        int index = 0 ;
        getperm(nums  , ans  , index);
return ans ;
    }
};