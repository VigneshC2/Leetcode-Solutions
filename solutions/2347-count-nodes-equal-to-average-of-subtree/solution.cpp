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
    unordered_map<TreeNode*,int> sums ;
    unordered_map<TreeNode*,int> total ;

    int giveSum(TreeNode* root){
        if(root == NULL) return 0 ;
        if(sums.find(root) != sums.end()) return sums[root] ;
        return sums[root] = root->val + giveSum(root->left) + giveSum(root->right) ;
    }
    int giveNumberOfNodes(TreeNode* root){
        if(root == NULL) return 0 ;
        if(total.find(root) != total.end()) return total[root] ;
        return total[root] = 1 + giveNumberOfNodes(root->left) + giveNumberOfNodes(root->right) ;
    }
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL) return 0 ;
        int sum = giveSum(root) ;
        int nodes = giveNumberOfNodes(root) ;
        int avg = sum / nodes ;
        int ans = averageOfSubtree(root->left) + averageOfSubtree(root->right) ;
        
        if(avg == root->val) ans += 1 ;

        return ans ;
    }
};