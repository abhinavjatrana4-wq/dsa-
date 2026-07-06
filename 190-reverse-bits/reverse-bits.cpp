class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans = 0 ;
        unsigned int num = (unsigned int) n ;
        for(int i = 0 ; i < 32 ; i++){
            ans = ans<<1 ;
            ans|= (num&1);
            num = num >> 1 ;

        }
        return (int ) ans ;
    }
};