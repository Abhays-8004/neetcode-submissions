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
int maxsum ;
    int solve(TreeNode* root){
     if(root== NULL ){
        return 0;
     }

     int left = solve(root->left);
     int right =solve(root->right);

     int sum = max(left,right)+ root->val;
      int totalsum = left + right + root->val;

      maxsum = max(maxsum,max(sum,max(totalsum,root->val)));

      return max(sum,root->val);

     
    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
       solve(root);
       return maxsum;
    }
};
