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
int maxi = INT_MIN ;
int maxPathSum(TreeNode* root ){
maxPath(root);
    return maxi ;
}
    int maxPath(TreeNode* root) {
        if(root == NULL){
            return 0 ;

        }
        int leftsum = max(maxPath(root->left) , 0 ) ;
        int rightsum = max(maxPath(root->right) , 0 );
         maxi = max(maxi , (root->val + rightsum + leftsum )) ;

        return root->val + max(leftsum , rightsum ) ;


    }
};