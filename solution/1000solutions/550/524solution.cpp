#include <vector>
#include <string>
using namespace std;

// 通过删除字母匹配到字典里最长单词
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string max = "";
        int one, two;
        for(string cur: dictionary) {
            // 从头比较cur和s
            one = two = 0;
            while(one < s.length() && two < cur.length()) {
                if(s[one] == cur[two]) {
                    one++;
                    two++;
                }else {
                    one++;
                }
            }
            // 当已经判断到cur的最后一个元素时
            if(two == cur.length()) {
                if(cur.length() > max.length())
                    max = cur;
                else if(cur.length() == max.length()) {
                    for(int i = 0; i < cur.length(); i++) {
                        if(cur[i] < max[i]) {
                            max = cur;
                            break;
                        }else if(cur[i] > max[i]) {
                            break;
                        }
                    }
                }
            }
        }
        return max;
    }
};