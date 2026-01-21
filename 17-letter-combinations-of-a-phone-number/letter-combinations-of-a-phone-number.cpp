class Solution {
    private: 
    void solve(int index , string output , vector<string>& ans , string digit , string mapping[]){
// base case 
if(index >= digit.length()){
    ans.push_back(output);
    return ; 
}
int number = digit[index] - '0';
string value = mapping[number];

for(int i = 0 ; i < value.size() ; i++){
    output.push_back(value[i]);
    solve(index + 1 , output , ans , digit , mapping);
    output.pop_back();

}


    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans ;
        if(digits.length()== 0){
            return ans;
        }
        int index = 0 ;
        string output = "" ;

        string  mapping[10] = { "" , "" , "abc" , "def" , "ghi" ,"jkl", "mno" , "pqrs" , "tuv" , "wxyz"};

        solve(index , output , ans , digits , mapping );
        return ans ;


    }
};