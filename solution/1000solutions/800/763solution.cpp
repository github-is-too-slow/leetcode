#include <vector>
#include <string>
using namespace std;

// 划分字母区间
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 保存每个区间的长度信息
        vector<int> res;
        // 保存每个字母最后一次出现的位置，初始化为npos
        vector<int> charPos(26, s.npos);
        
        int n = s.length();
        // 当前串区间的最后一个位置
        int curPos = -1;
        // 当前串区间的长度
        int curLen = 0;
        // 从第一个字母开始，查询最后一次出现的位置
        for(int i = 0; i < n; i++) {
            char cur = s[i];
            curLen++;
            int pos;
            if(charPos[cur - 'a'] != s.npos) {// 已经查询到当前字母出现的最后一次位置
                pos = charPos[cur - 'a'];
            } else {
                pos = s.find_last_of(cur);
                charPos[cur - 'a'] = pos;
            }
            // 判断当前字母是否在当前串区间中
            if(pos > curPos) {// 不在当前区间，第一个字母同样满足该条件
                // 更新当前区间最后一个位置
                curPos = pos;
            }
            if(i == curPos) {
                // 当前区间内的所有字母已经判断完毕了
                res.push_back(curLen);
                // 重置
                curPos = -1;
                curLen = 0;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "ababcbacadefegdehijhklij";
    solution.partitionLabels(s);
    return 0;
}
