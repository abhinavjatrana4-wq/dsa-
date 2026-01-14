class Solution {
public:
    int fib(int n) {
        
        if(n <= 1){
            return n;
        }
        int a = 0 ;
        int b = 1 ;
        for(int i = 1 ; i < n ; i++){
            int ans = a + b;
            a = b ;
            b = ans ;
        }
        return b ;
    
    }
};