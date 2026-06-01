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
void inorder(TreeNode* root , vector<int> &inorderval ){
    if(root == NULL){
        return  ;
    }

    inorder(root->left ,inorderval);
    inorderval.push_back(root->val);
    inorder(root->right , inorderval );


}
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderval ;
        inorder(root , inorderval ) ;
        int i = 0 ;
        int j = inorderval.size() - 1 ;
        while(i < j ){
            int sum = inorderval[i] + inorderval[j];
            if(sum == k){
                return true ;

            }
            if(sum > k ){
                j-- ;
            }
            if(sum < k ){
                i++ ;

            }
        }
return false ;
    }
};