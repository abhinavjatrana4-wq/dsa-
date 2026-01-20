class Solution {
    private:
    void solve(vector<int> output , vector<int> nums , int index , vector<vector<int>>& ans){
// base case 
if(index >= nums.size()){
    ans.push_back(output);
    return ;
}

solve(output , nums , index + 1 , ans  ) ;
int element = nums[index] ;
output.push_back(element);
solve(output , nums  , index + 1 , ans  );
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> output ;
        int index =0 ;

     solve(output , nums  , index , ans  );
return ans;
    }
};