// recursion
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
        vector<vector<int>> res;
        levelorder(root, 0, res);
        return  vector<vector<int>> (res.rbegin(), res.rend());
    }
    void levelorder(TreeNode* node, int level, vector<vector<int>>& res) {
        if (!node) return;
        if (res.size() == level) res.push_back({});
        res[level].push_back(node->val);
        if(node->left) levelorder(node->left,level + 1, res);
        if(node -> right) levelorder(node -> right, level + 1, res);
    }
};

// thinking path
// 1 边界条件：置空返回
// 2 有一个存储输出结果的容器
// 3 主体： 输出本层，继续走左右
//     其中左右需要考虑模块函数调用
// 4 返回 输出结果
