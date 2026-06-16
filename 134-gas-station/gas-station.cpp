class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalcost = 0 , totalgas = 0 ;
        for(int x : gas ){
            totalgas = totalgas + x;
        }
        for(int x : cost){
            totalcost =  totalcost + x ;
        }
        if(totalgas < totalcost ){
            return -1 ;
        }
        int n = gas.size();
        int start = 0 ;
int currgas = 0 ;
        for(int i =0 ; i < n ; i++){
            
             currgas = currgas +(gas[i] - cost[i]);
            if(currgas < 0 ){
                currgas = 0 ;
                start = i + 1 ;
            }
        }
        return start ;
    }
};