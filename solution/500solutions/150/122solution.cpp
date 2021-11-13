#include <vector>
using namespace std;

// 买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int earnings = 0;
        // 最低点
        int min;
        // 表明一个趋势，默认为下降趋势
        bool flag = false;
        int n = prices.size();
        for(int i = 0; i < n - 1; i++) {
            // 上升趋势
            if(flag) {
                // 只关心当明天比今天低
                if(prices[i] > prices[i + 1]) {
                    // 上升趋势，则可以立即抛售
                    earnings += prices[i] - min;
                    // 重置
                    flag = false;
                }
            } else {
                // 下降趋势，
                if(prices[i] < prices[i + 1]) {
                    // 只关心明天比今天高，记录最低点
                    min =  prices[i];
                    flag = true;
                }
            }            
        }
        // 最后一天
        if(flag) {
            earnings += prices[n - 1] - min;
        }
        return earnings;
    }
};
