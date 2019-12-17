class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> out;
        vector<int> visited(nums.size(),0);
        helper(nums, 0, visited, out, res);
        return res;
    }
    
    void helper(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (level == nums.size()) {res.push_back(out); return;}
        for (int i = 0; i< nums.size(); ++i) {
            if(visited[i] == 1) continue;
            // 收
            visited[i] = 1;
            out.push_back(nums[i]);
            // 递归
            helper(nums, level+1, visited, out, res);
            // 放
            out.pop_back();
            visited[i] = 0;
        }
    }
};




