#include <string>
using namespace std;

// 验证回文串
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        int tmpleft, tmpright;
        // bool flag = true;
        while(left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }else {
                // 优先删除left元素
                tmpleft = left;
                tmpright = right;
                left++;
                while(left < right) {
                    if (s[left] == s[right]) {
                        left++;
                        right--;
                    }else {
                        break;
                    }
                }
                if(left < right) {
                    // 其次在删除右边元素
                    left = tmpleft;
                    right = tmpright - 1;
                    while(left < right) {
                        if (s[left] == s[right]) {
                            left++;
                            right--;
                        }else {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};