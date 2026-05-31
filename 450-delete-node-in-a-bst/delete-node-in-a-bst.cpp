
class Solution {
public:
TreeNode* helper(TreeNode* root ){
    if(root->left == NULL) {
        return root->right ;
    }
    if(root->right == NULL){
        return root->left ; 
        }
    
    TreeNode* rightchild = root->right ;
    TreeNode* lastrightchild = Findlast(root->left);
    lastrightchild->right = rightchild ;
    return root->left ;
}

TreeNode* Findlast(TreeNode* root){
    if(root->right == NULL){
        return root ;
    }
    return Findlast(root->right ) ;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL ;
        }
        if(root->val == key){
            return helper(root);
        }
        TreeNode* dummy  = root ;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root ->left -> val == key ){
                    root->left =  helper(root->left);
                }
            else{
                root = root->left ;
                }
            }
           else{
            if(root->right != NULL && root ->right->val == key){
                root->right =  helper(root->right) ;


            }
            else{
                root = root->right;

            }

           }
        }
        return dummy ;
    }
};