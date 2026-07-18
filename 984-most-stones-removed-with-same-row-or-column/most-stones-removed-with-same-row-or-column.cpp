class Solution {
public:
 vector<int> parent;
 vector<int> rank ;

 int findparent(int x ){
    if(parent[x] == x ){
        return x ;
    }
    return parent[x] = findparent(parent[x]);
 }

void unionSet(int a , int b ){
    int parentA = findparent(a);
    int parentB = findparent(b);
if(rank[parentA] == rank[parentB]){
    parent[parentB] = parentA;
    rank[parentA]++;
}
else if(rank[parentA]  > rank[parentB]){
    parent[parentB] = parentA;

}
else {
    parent[parentA] = parentB;
}
}
    int removeStones(vector<vector<int>>& stones) {
       int Offset = 10001 ;
       parent.resize( 20002);
       rank.resize(20002 , 0 );

       for(int i = 0 ; i < 20002 ; i++){
        parent[i] = i ;

       }
       unordered_set<int> nodes;
       for(auto &stone : stones ){
        int row = stone[0];
        int column = stone[1] + Offset ;

        unionSet(row , column);
        nodes.insert(row);
        nodes.insert(column);


       }
       int component = 0 ;

       for(int node : nodes ){
        if(findparent(node) == node ){
            component++;
        }
       }
       return stones.size() - component ;





    }
};