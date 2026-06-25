class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans ;
        int row = matrix.size();
        int col = matrix[0].size();
    int count= 0;
    int total = row*col;
    
    int startingrow = 0;
    int startingcolumn = 0 ;
    int endingcolumn = col - 1;
    int endingrow = row - 1;

while(count < total ){
    // for printing the starting  row 
    for(int index = startingcolumn ;count < total && index <= endingcolumn ; index++ ){
       ans.push_back(matrix[startingrow][index]);
       count++;
    }
    startingrow++;
    //for printing ending column 
    for(int index = startingrow ; count < total && index <= endingrow ; index++){
        ans.push_back(matrix[index] [endingcolumn]);
        count++;
    }
    endingcolumn--;
    //for printing the last column 
    for(int index = endingcolumn ; count < total && index >= startingcolumn ; index-- ){
        ans.push_back(matrix[endingrow] [index]);
        count++;
    }
    endingrow--;
    //form printing the starting column 
    for(int index = endingrow ; count < total && index >= startingrow ; index--){
        ans.push_back( matrix[index] [startingcolumn]);
        count++;
    }
    startingcolumn++;

   
}


return ans;
    }
};