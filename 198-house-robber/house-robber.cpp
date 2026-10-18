class Solution {
public:
int solve(int index , vector<int>& nums , vector<int>&  dp){
 if(index < 0 ){
    return 0 ;
 }
 if(index == 0 ){
    return nums[index];
 }
 if(dp[index] != -1 ){
    return dp[index];
 }
 int take = nums[index] + solve(index - 2 , nums , dp );
 int notTake = solve(index-1 , nums , dp);
 dp[index] = max(take , notTake);
 return dp[index];
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1 );
        return solve(n-1 , nums , dp );
    }
};