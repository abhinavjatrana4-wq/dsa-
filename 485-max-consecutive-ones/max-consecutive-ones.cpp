class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = -1;
        int j = 0;
        int count = 0;
        
        while (j < n) {
            if (nums[j] != 0) {
                j++;
                continue;
            }
            
            count = max(count, j - i - 1);
            i = j;
            j++;
        }
        
        count = max(count, j - i - 1);
        return count;
    }
};