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
    int ans = 0 ;
    class info{
        public :
        int max , min , sum ;
        info(int mi , int ma, int s){
min = mi ;
max = ma ;
sum = s ;

   }
    };
    info helper(TreeNode* root ){
        if(root == NULL){
            return info( INT_MAX, INT_MIN , 0 );
        }
        info left = helper(root->left);
        info right = helper(root->right) ;
        if(root->val > left.max && root->val < right.min){
            int currMin = min(root->val , left.min);
            int currMax = max(root->val , right.max);
            
            int currSum = left.sum +right.sum +root->val;
 ans = max(ans, currSum);
                   return info(currMin , currMax , currSum );
        }
        else{
            return info(INT_MIN , INT_MAX , 0 );

        }
    }

    int maxSumBST(TreeNode* root) {
       helper(root);
       return ans ;

    }
};