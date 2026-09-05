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
    void helper(TreeNode* root , unordered_set<int>& st , vector<int>& ans , int level){
        if(root == NULL) return ;

        if(st.find(level) == st.end()){
            ans.push_back(root->val) ;
            st.insert(level) ;
        }

        helper(root->right , st , ans , level + 1) ;
        helper(root->left , st , ans , level + 1) ;

        return ;
    }
    void helper(TreeNode* root , vector<bool>& isVisited , vector<int>& ans , int level){
        if(root == NULL) return ;

        if(!isVisited[level]){
            ans.push_back(root->val) ;
            isVisited[level] = true ;
        }

        helper(root->right , isVisited , ans , level + 1) ;
        helper(root->left , isVisited , ans , level + 1) ;

        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans ;
        unordered_set<int> st ;
        vector<bool> isVisited(101 , false) ;
        helper(root , isVisited , ans , 0) ;
        return ans ;
    }
};