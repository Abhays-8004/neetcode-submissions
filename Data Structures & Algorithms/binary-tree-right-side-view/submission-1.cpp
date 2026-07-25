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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)return {};
        vector<int>ans;
        queue<TreeNode*>pq;
        pq.push(root);
        while(!pq.empty()){
            int count = pq.size();
            vector<int>result;
            for(int i = 0;i<count;i++){
                TreeNode* temp = pq.front();
                pq.pop();
                result.push_back(temp->val);
                if(temp->left != NULL){
                    pq.push(temp->left);
                }
                if(temp->right != NULL){
                    pq.push(temp->right);
                }
            }

            ans.push_back(result[result.size() -1]);
        }

        return ans;
    }
};
