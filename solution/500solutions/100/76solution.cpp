#include <vector>
#include <string>
using namespace std;


// 最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128, 0);
        vector<bool> flags(128, false);
        // 统计子串中字符是否存在以及个数
        for(char c: t) {
            chars[c]++;
            flags[c] = true;
        }
        // 当前包含的子串字符个数
        int cnt = 0; 
        // 当前最短长度
        int minCnt = 100000, minleft = 0;
        int left = 0, right = 0;
        char cur;
        while(right < s.size()) {
            // 目前[left, right)还没有完全包含子串
            if(cnt < t.size()) {
                cur = s[right];
                // 存在于子串中
                if(flags[cur]) {
                    if(chars[cur] > 0){
                        cnt++;
                    }
                    chars[cur]--;
                }
                right++;
            }else {
                // 目前[left, right)已经完全包含子串
                // 因为left可能并不在子串中，因此可能不是最短长度，因此，移动left指针
                while(cnt == t.size()) {
                    cur = s[left];
                    if(flags[cur]){
                        if(chars[cur] == 0) {
                            // left在子串中，可以直接计算最小长度
                            int curCnt = right - left;
                            if(curCnt < minCnt) {
                                minCnt = curCnt;
                                minleft = left;
                            }
                            // 更新cnt
                            cnt--;
                        }
                        // 更新chars
                        chars[cur]++;   
                    }
                    // left指针右移
                    left++;
                }
            }
        }
        // 当right==s.size(),此时也可能完全包含子串
        while(cnt == t.size()) {
            cur = s[left];
            if(flags[cur]){
                if(chars[cur] == 0) {
                    // left在子串中，可以直接计算最小长度
                    int curCnt = right - left;
                    if(curCnt < minCnt) {
                        minCnt = curCnt;
                        minleft = left;
                    }
                    // 更新cnt
                    cnt--;
                }
                // 更新chars
                chars[cur]++;   
            }
            // left指针右移
            left++;
        }
        return minCnt == 100000? "": s.substr(minleft, minCnt);
    }
};

int main(int argc, char const *argv[])
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution solution;
    solution.minWindow(s, t);
    return 0;
}
