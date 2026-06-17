class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        int l = 0 ;
        int r  = n -1; 
        int lmax = 0 , rmax = 0;
        int ans = 0 ;
        while(l < r ){
            lmax = max(lmax , ht[l]);
            rmax = max(rmax , ht[r]);
            if(lmax < rmax ){
                ans = ans + (lmax - ht[l]);
                l++;
            }
            else{
                ans = ans + (rmax - ht[r]);
                r--;

            }
        }
         
return ans ;
    }
};