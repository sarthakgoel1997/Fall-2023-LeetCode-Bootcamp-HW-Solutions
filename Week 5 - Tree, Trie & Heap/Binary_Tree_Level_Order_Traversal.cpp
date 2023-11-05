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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};

        vector<vector<int> > ans;

        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        int hmax = 0;

        ans.push_back({});
        pair<TreeNode*, int> temp;

        while(!q.empty()) {
            temp = q.front();
            q.pop();

            ans[temp.second].push_back(temp.first->val);

            if(temp.first -> left) {
                q.push({temp.first -> left, temp.second + 1});
            }

            if(temp.first -> right) {
                q.push({temp.first -> right, temp.second + 1});
            }

            if((temp.first -> left || temp.first -> right) && (temp.second + 1 > hmax)) {
                hmax++;
                ans.push_back({});
            }
        }

        return ans;
    }
};