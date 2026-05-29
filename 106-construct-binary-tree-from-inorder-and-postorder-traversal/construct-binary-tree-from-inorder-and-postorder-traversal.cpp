/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void create(vector<int>& inorder , map<int , int >& nodetoindex , int n ){
    for(int i = 0 ; i < n ; i++ ){
        nodetoindex[inorder[i]] = i ;
    }
}
TreeNode* solve(vector<int>&inorder , vector<int>& postorder , int &postorderindex , map<int , int >& nodetoindex , int n , int inorderstart , int inorderend ){
    if(postorderindex < 0 || inorderstart > inorderend  ){
        return NULL;
    }
    int element = postorder[postorderindex--];
    TreeNode* root = new TreeNode(element );
    int position =  nodetoindex[ element ];
    root->right = solve(inorder , postorder , postorderindex , nodetoindex , n , position + 1 , inorderend ) ;
    root->left = solve(inorder ,postorder , postorderindex , nodetoindex , n  , inorderstart,  position -1  );
    return root ;

}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postorderindex = n-1 ; 

        map<int, int > nodetoindex ;
        // create the node 
        create(inorder , nodetoindex , n );

        TreeNode* ans = solve(inorder , postorder , postorderindex , nodetoindex , n ,  0 , n - 1 );

return ans ;

    }
};