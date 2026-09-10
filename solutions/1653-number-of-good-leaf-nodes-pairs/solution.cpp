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
    void FindAllLeafNodes(TreeNode* root , vector<TreeNode*>& allLeafNodes){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL) allLeafNodes.push_back(root) ;
        FindAllLeafNodes(root->left ,allLeafNodes ) ;
        FindAllLeafNodes(root->right , allLeafNodes) ;
        return ;
    } 

    void findAllParent(TreeNode* curr , TreeNode* p , unordered_map<TreeNode* , TreeNode*>& parent){
        if(curr == NULL) return ;
        parent[curr] = p ;
        findAllParent(curr->left , curr , parent) ;
        findAllParent(curr->right , curr , parent) ;
        return ;
    }

    void helper(TreeNode* curr , TreeNode* prev , unordered_map<TreeNode* , TreeNode*>& parent , int& count , int distance){
        if(curr == NULL) return ;
        if(curr->left == NULL && curr->right == NULL) {
            count += 1 ;
            return ;
        }
        if(distance == 0) return ;
        
        if(parent[curr] != prev) helper(parent[curr] , curr , parent , count , distance - 1) ;
        if(curr->left != prev) helper(curr->left , curr , parent , count , distance - 1) ;
        if(curr->right != prev) helper(curr->right , curr , parent , count , distance - 1) ;

        return ;
    }

    int countPairs(TreeNode* root, int distance) {
        vector<TreeNode*> leafNodes ;
        FindAllLeafNodes(root , leafNodes) ;

        unordered_map<TreeNode* , TreeNode*> parent ;
        findAllParent(root , NULL , parent) ;

        int ans = 0 ;

        for(auto node : leafNodes){
            helper(parent[node] , node , parent , ans , distance - 1) ;
        }

        ans >>= 1 ;

        return ans ;
    }
};