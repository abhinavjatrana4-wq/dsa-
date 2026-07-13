class Solution {
public:
    int candy(vector<int>& rating) {
        int sum = 1 ;
        int i = 1 , n = rating.size() ;


        while(i < n ){
            if(rating[i] == rating[i-1]){
                sum += 1 ;
                i++;

                continue ;
            }
            int peak = 1 ;
            while(i < n && rating[i] > rating[i-1]){
                peak+=1;
                sum+= peak ; ;
                i++;
               
            }
            int dwon = 1 ;
            while(i < n && rating[i] < rating[i-1]){
                sum += dwon ;
                i++;
                dwon++;
            }
            if(dwon > peak){
                sum += dwon - peak ;
            }

            
        }
        return sum ;
    }
};