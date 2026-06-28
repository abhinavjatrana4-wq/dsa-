class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , int > charIndexS;
        unordered_map<char , int > charIndexT;
       
        for(int i = 0 ; i < s.size() ; i++){
            if(charIndexS.find(s[i]) == charIndexS.end()){
                charIndexS[s[i]] = i ;
            }
            if(charIndexT.find(t[i]) == charIndexT.end()){
                charIndexT[t[i]] = i ;
            }
            if(charIndexT[t[i]] != charIndexS[s[i]]){
                return false ;
            }
        }

 return true ;
    }
};