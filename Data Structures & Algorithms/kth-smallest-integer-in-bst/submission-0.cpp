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
    vector<int>arr;
    void totalnodes(TreeNode* root){
        if(root == NULL){
            return ;
        }

        totalnodes(root->left);
        arr.push_back(root->val);
        totalnodes(root->right);

        
    }
    int kthSmallest(TreeNode* root, int k) {
        totalnodes(root);
        return arr[k-1];


    }
};
