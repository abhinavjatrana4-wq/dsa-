class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0 ;
        int n = height.size();
        int lp = 0 ;
        int rp = n - 1 ; 

        while(lp < rp){
            int w = rp - lp  ;
            int minht = min(height[lp] , height[rp] );
            int currwater = minht * w  ;

            maxwater = max(maxwater , currwater ) ;

            height[lp] < height[rp] ? lp++ : rp-- ;



        }
        return maxwater ;
    }
};