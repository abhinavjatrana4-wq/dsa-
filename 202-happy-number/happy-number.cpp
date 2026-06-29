class Solution {
public:
int getnumber(int n ){
    int output = 0 ;
    while(n > 0 ){
        int digit = n % 10 ;
        output = output + (digit * digit);
        n = n / 10 ;
    }
    return output ;
}
    bool isHappy(int n) {
         unordered_set<int> visit ;
         while(visit.find(n)== visit.end()){
            visit.insert(n);
            n = getnumber(n);
            if(n == 1 ){
                return true ;
            }
         }
         return false ;
    }
};