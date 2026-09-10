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
    void findSumOfAllLevels(TreeNode* root , int level , unordered_map<int,int>& sum){
        if(root == NULL ) return ;

        sum[level] += root->val ;

        findSumOfAllLevels(root->left , level + 1 , sum) ;
        findSumOfAllLevels(root->right , level + 1 , sum) ;

        return ;
    }

    void findSumOfAllLevels(TreeNode* root , int level , int* sum){
        if(root == NULL ) return ;

        sum[level] += root->val ;

        findSumOfAllLevels(root->left , level + 1 , sum) ;
        findSumOfAllLevels(root->right , level + 1 , sum) ;

        return ;
    }

    void replace(TreeNode* root , int sibling , unordered_map<int,int>& sum , int level){
        if(root == NULL) return ;

        root->val = sum[level] - root->val - sibling ;

        int l = 0 ;
        int r = 0 ;

        if(root->left) l = root->left->val ;
        if(root->right) r = root->right->val ;

        replace(root->left , r , sum , level + 1) ;
        replace(root->right , l , sum , level + 1) ;

        return ;
    }

    void replace(TreeNode* root , int sibling , int* sum , int level){
        if(root == NULL) return ;

        root->val = sum[level] - root->val - sibling ;

        int l = 0 ;
        int r = 0 ;

        if(root->left) l = root->left->val ;
        if(root->right) r = root->right->val ;

        replace(root->left , r , sum , level + 1) ;
        replace(root->right , l , sum , level + 1) ;

        return ;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        // unordered_map<int,int> sum ;
        int size = 1e5 + 1 ;
        int sum[size] ;
        for(int i = 0 ; i < size ; i++){
            sum[i] = 0 ;
        }
        findSumOfAllLevels(root , 0 , sum) ;
        replace(root , 0 , sum , 0) ;
        return root ;
    }
};