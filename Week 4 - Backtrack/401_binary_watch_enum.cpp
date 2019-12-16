class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        vector<int> hour{8,4,2,1}, minute{32,16,8,4,2,1};
        for (int i = 0; i <= num; ++i) {
            vector<int> hours = generate(hour,i);
            vector<int> minutes = generate(minute, num - i);
            for (int h : hours) {
                if (h > 11) continue;
                for (int m : minutes) {
                    if (m > 59) continue;
                    res.push_back(to_string(h)+ (m < 10? ":0" : ":") + to_string(m));                
                }
            }
        }
        return res;
    }
    vector<int> generate(vector<int>& nums, int cnt) {
        vector<int> res;
        helper(nums, cnt, 0, 0, res);
        return res;
    }
    void helper(vector<int>& nums, int cnt, int pos, int out, vector<int>& res) {
        if(cnt == 0) {
            res.push_back(out);
            return;
        }
        for(int i = pos; i < nums.size(); ++i) {
            helper(nums, cnt - 1, i + 1, out+ nums[i], res);
        }
    }


};



// bitset这个类，可以将任意进制数转为二进制


// # thought path
// 1 边界条件 最少0 最大8
// 2 回溯方法 分层回溯 规则：时钟小于等于3个，时间点小于11点；分钟小于等于5个，时间小于59个
// 3 返回值 返回是一个vector，每个里面是时间

// 边界case： n=0， n=8 n= 10 n = -1