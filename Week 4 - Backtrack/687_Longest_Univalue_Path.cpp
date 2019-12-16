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
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
        }
    int helper(TreeNode* node, int& res) {
        if(!node) return 0;
        int left = helper(node->left, res);
        int right = helper(node->right, res);
        left = (node->left && node->val == node->left->val) ? left + 1: 0;
        right = (node->right && node->val == node->right->val) ? right + 1: 0;
        res = max(res, left + right);
        return max(left, right);
        
    }
    
    
};


// 1 边缘条件： root空，返回null
// 2 主题 递归
// 考虑：每个节点都需要向下走一遍。
// 递：考虑当前节点，左子树右子树往下走，有2个存储器（左边一个右边一个），如果一样，值就+1，如果不一样，就返回上一层
// 归： 左边最大值+右边最大值。

// 3 return res;