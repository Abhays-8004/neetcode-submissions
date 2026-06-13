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
    pair<bool,int> solve(TreeNode* root){
        if(!root){
            return {true,0};
        }

        pair<bool,int> left = solve(root->left);
        pair<bool,int>right = solve(root->right);
        bool check = (abs(left.second -right.second)<=1) && (left.first && right.first);
        return {check,max(left.second,right.second)+1};
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        return solve(root).first;
    }
};
