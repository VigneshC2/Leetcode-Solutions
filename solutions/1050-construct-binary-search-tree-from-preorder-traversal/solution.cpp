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
    TreeNode* helper(vector<int>& pre ,int& idx ,  int max_limit){
        if(idx >= pre.size() || pre[idx] > max_limit) return NULL ;

        TreeNode* curr = new TreeNode(pre[idx]) ;
        idx += 1 ;

        curr->left = helper(pre , idx  , curr->val) ;
        curr->right = helper(pre , idx , max_limit) ;

        return curr ;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0 ;
        return helper(preorder , idx , 1e9) ;
    }
};