class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int > ms ;
        unordered_map<char , int > mt ;
        for(char ch: s ){
            ms[ch]++;
        }
        for(char ch : t){
            mt[ch]++;
        }
        return ms==mt ;
    }
};