class Solution {
public:
void dfs(int i , vector<vector<int>>& isConnected , vector <bool> &visited , int n  ){
    visited[i] = true ;
    for(int j = 0 ; j < n ; j++ ){
        if(isConnected[i][j] == 1  && !visited[j] ){
            dfs(j , isConnected , visited , n );
        }

    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int NoOfProviences = 0 ;
        int n = isConnected.size();

        vector <bool>visited(n , false );

        for(int i =0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i , isConnected , visited , n );
                NoOfProviences++ ;

            }
        }
        return NoOfProviences ;


    }
};