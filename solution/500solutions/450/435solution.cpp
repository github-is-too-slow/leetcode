#include <vector>
#include <algorithm>
using namespace std;

// 消除重复边界
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 先按结尾值进行排序
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });

        // 贪心策略：每次选择与当前选择区间不冲突并且结尾值最小的区间
        vector<int>& cur = intervals[0];
        int count = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if (cur[1] > intervals[i][0]) { // 冲突
                count++;
            } else {
                cur = intervals[i];
            }
        }
        return count;
    }
};