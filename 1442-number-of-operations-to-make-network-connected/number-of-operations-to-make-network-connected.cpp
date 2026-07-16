class Solution {
public:
vector<int>parent ;
vector<int> rank ;

int findParent(int x){
    if(parent[x] == x){
        return x ;
    }
    return parent[x] = findParent(parent[x]);
}

void unionSet(int a , int b){
  int  parentA = findParent(a);
   int parentB = findParent(b);
    if(rank[parentA] == rank[parentB]){
        parent[parentB] = parentA;
        rank[parentA]++;

    }
    else if(rank[parentA] > rank[parentB]){
    parent[parentB] = parentA;
    }
    else{
        parent[parentA]=parentB;

    }

}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
    return -1;
        parent.resize(n);
        rank.resize(n , 0 );
        for(int i = 0 ;i < n ; i++){
            parent[i] = i ;

        }
        for(auto &it : connections){
            int u = it[0];

            int v = it[1];
            if(findParent(u) != findParent(v)){
                unionSet(u , v);
            }
           
            
            }
    
        int noOfOperation = 0 ;
        for(int i = 0 ; i < n ;i++){
                if(parent[i] == i ){
                 noOfOperation +=1 ;   
                }
                }
                return noOfOperation - 1 ;
    }

};