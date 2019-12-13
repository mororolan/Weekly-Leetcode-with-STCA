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
    bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    int you_know = sum - root->val;
    if (!root->left && !root->right && you_know == 0) return true;
    return hasPathSum(root->right, you_know) ||hasPathSum(root->left, you_know) ;
    }
};


// 反推：
// 1 结果： 给出是或者否
//   - 是：一个树杈到底 减为0
//   - 否：所有树杈到底 减的不为0
  
  
//   需要有一个tmp记录每一层所减掉剩下的数字
//   每一次tmp需要和0去对比
  
  
// 1 判断 如果没有子树，而且数值不等于sum，则return false
// 2 设定中间值，开始递归
// 3 返回数值