// Binary Tree Level Order Traversal II
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> res;
        queue<TreeNode *> q{{root}};
        while(!q.empty()) {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *t = q.front();
                q.pop();
                oneLevel.push_back(t -> val);
                if(t->left) q.push(t -> left);
                if(t -> right) q.push(t -> right);
            }
            res.insert(res.begin(), oneLevel);
        }
        return res;
    }
};

// thinking path
// 1 边界条件：置空返回
// 2 有一个存储输出结果的容器
// 3 主体： 输出本层，继续走左右
//     其中左右需要考虑模块函数调用
// 4 返回 输出结果
