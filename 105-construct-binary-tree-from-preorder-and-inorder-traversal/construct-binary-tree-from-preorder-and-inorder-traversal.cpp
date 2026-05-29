
class Solution {
public:
void  create(vector<int>& inorder , map<int , int > &nodeToIndex   , int n  ){
    for(int i = 0 ; i < n ; i++){
        nodeToIndex[inorder[i]] = i ; 
    }

}
TreeNode* solve(vector<int>& preorder , vector<int>& inorder , int &index , int inorderstart , int inorderend , int n , map<int , int > &nodeToIndex  ){
if(index >= n || inorderstart > inorderend ){
    return NULL;
}
int element = preorder[index++];
TreeNode* root = new TreeNode(element);
int position  = nodeToIndex[element ];
root->left = solve(preorder , inorder , index , inorderstart  , position - 1 , n  , nodeToIndex);
root->right = solve(preorder , inorder , index , position + 1 , inorderend , n , nodeToIndex );
return root ;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex =  0 ; 
        int n = inorder.size();
        map<int, int> nodeToIndex ;
        // create the map 
create(inorder , nodeToIndex , n);
        TreeNode* ans = solve(preorder , inorder , preorderindex , 0 , n-1, n  , nodeToIndex);



     return ans ;
    }
};