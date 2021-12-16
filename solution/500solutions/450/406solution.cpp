#include <vector>
#include <algorithm>
using namespace std;

// 根据身高重构队列
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people){
        // 首先根据身高进行排序
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        unsigned n = people.size();
        vector<vector<int>> res(n);
        vector<bool> flag(n, false);

        // [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
        // [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
        // 从第一个人开始，将其插入到指定位置
        for (int i = 0; i < n; i++) {
            vector<int>& curPeople = people[i];
            int curCount = curPeople[1];
            int curPos = 0;
            // 从头寻找n个空闲位置
            while(flag[curPos] || curCount){
                if(!flag[curPos] || res[curPos][0] >= curPeople[0]){
                    curCount--;
                }
                curPos++;
            }
            // 当前位置没有有人，直接插入或已经找到顺延插入的位置
            res[curPos] = curPeople;
            flag[curPos] = true;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    // [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    vector<vector<int>> people = {
        {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}
    };
    solution.reconstructQueue(people);
    return 0;
}
