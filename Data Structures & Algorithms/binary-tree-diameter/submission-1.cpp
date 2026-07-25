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
    int solve(TreeNode* root,int &diameter ,int depth){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL&& root->right == NULL){
            return 1;
        }
        

        int left = solve(root->left,diameter,depth);
        int right = solve(root->right,diameter,depth);

        diameter = max(diameter,(left+right));

        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        int diameter = 0;
        int depth;
        solve(root,diameter,depth);

        return diameter;
    }
};
