class Solution {
public:
bool iscyclic(int src , vector<vector<int>> & prerequisites , vector<bool> & visited , vector<bool>& recpath) {
visited[src] = true ; 
recpath[src] = true ;
for(int v : prerequisites[src] ){
if(!visited[v]){
    if(iscyclic( v , prerequisites , visited , recpath)){
        return true ;
    }
    
     }else if(recpath[v]){
return true ;
   }

} 
recpath[src] = false ;
return false ;

}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses) ;
        for(auto&e : prerequisites ){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
    
        vector<bool> visited(numCourses , false );
        vector<bool> recpath(numCourses , false) ;
for(int i = 0 ; i <  numCourses ; i++){
    if(iscyclic(i , adj , visited , recpath)){
        return false ;
    }
}
return true ;
    }
};