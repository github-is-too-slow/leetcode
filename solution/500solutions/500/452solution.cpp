#include <vector>
#include <algorithm>
using namespace std;

// 射箭问题
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 1) {
            return n;
        }

        // 先将区间按照结束位置增量排序
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        // 需要的箭数量，射爆第一个气球至少需要一个
        int count = 1;
        // 该支箭可以射击的右边界
        int bound = points[0][1];
        // 从第二个气球开始尽可能射爆更多的气球即可
        for(int i = 1; i < n; i++) {
            // 超出当前边界就需要另外一支箭
            if(points[i][0] > bound) {
                count++;
                // 更新当前边界
                bound = points[i][1];
            }
        }
        return count;
    }
};