class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result ;
        if(nums.empty()){
            return result;
        }
        for(int i = 0 ; i < nums.size() ;){
            int j = i ;
            int start =nums[i] ;
            // expand the range 
            while(j+1 < nums.size() && nums[j+1] == nums[j]+1){
                j++;
            }
            // push the string to the result 
            if(nums[j]== start){
                result.push_back(to_string(nums[j]));
            }
            else{
                result.push_back(to_string(start) + "->" + to_string(nums[j]));
            }
i = j+1;
        }
        return result ;
    }
};