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
    void func(TreeNode *root, priority_queue<int> &pq, int k) {
        if(root == NULL)
            return;
        
        func(root->left, pq, k);

        if(pq.size() < k)
            pq.push(root->val);
        else if(pq.top() > root->val) {
            pq.pop();
            pq.push(root->val);
        }

        func(root->right, pq, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;

        func(root, pq, k);

        return pq.top();
    }
};