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

    void solve(int& count,TreeNode* root,int maxval){
        if(root == NULL){
            return;
        }

        if(root->val>=maxval){
            count++;
        }
         maxval = max(maxval,root->val);
        solve(count,root->left,maxval);
        solve(count,root->right,maxval);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;

        solve(count,root,INT_MIN);
        return count;
    }
};
