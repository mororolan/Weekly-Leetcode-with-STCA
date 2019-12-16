class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m <60; ++m) {
                //	b中置为1的二进制位的个数
                if(bitset<10>((h << 6) + m).count() == num ) {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }
};


// bitset这个类，可以将任意进制数转为二进制
