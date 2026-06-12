class Solution {
public:
bool iscyclic(int src , vector<vector<int>> & adj , vector<bool>& visited , vector<bool>& recpath ){
visited[src] = true ;
recpath[src] = true ;
for(int v : adj[src]){
    if(!visited[v]){
        if(iscyclic(v , adj , visited , recpath )){
            return true ;
        }
    }
    else if(recpath[v]){
        return true ;
    }
  }
recpath[src] = false ;
return false ;
}

void toporder(int src , vector<vector<int>> & adj , vector<bool> &visited , stack<int> &s ){
    visited[src] = true;
    for(int v : adj[src]){
        if(!visited[v]){
            toporder(v , adj , visited ,s);
        }
    }
    s.push(src);
}
    vector<int> findOrder(int n, vector<vector<int>>& edges ){
        vector<vector<int>> adj(n) ;
        for(auto &e : edges ){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u) ;
        }
        vector<int> ans ;
         vector<bool> recpath(n , false );
         stack<int>s ; 
       vector<bool>visited(n ,false); 
       for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            if(iscyclic(i , adj , visited , recpath  )){
                return ans ;
            }
        }
       }
    // top order 
visited.assign(n, false) ;
for(int i = 0 ; i< n ; i++){
if(!visited[i]){
        toporder(i , adj , visited , s);
    }
}
while(!s.empty()){
    ans.push_back(s.top());
    s.pop();
}
return ans ;
    }
};