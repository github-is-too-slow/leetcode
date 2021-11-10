#include <vector>
using namespace std;

// 发放糖果
class Solution {
public:
    int candy(vector<int>& ratings) {
        // 糖果数容器
        vector<int> res;
        // 默认每个人的糖果数为1
        for(int i = 0; i < ratings.size(); i++){
            res.push_back(1);
        }
        // 先从左往右遍历一次,遍历完成，可以保证每个人的评分如果比左边人高，糖果数也是比他多
        for(int i = 0; i < ratings.size() - 1; i++) {
            if(ratings[i + 1] > ratings[i]) {
                res[i + 1] = res[i] + 1;
            }
        }
        int count = res[ratings.size() -1];
        // 从右往左遍历一次，遍历完成，可以保证每个人的评分如果比右边人高，糖果数也是比他多
        for(int i = ratings.size() - 1; i > 0; i--) {
            if(ratings[i - 1] > ratings[i] && res[i - 1] <= res[i]) {
                res[i - 1] = res[i] + 1;
            }
            count += res[i - 1];
        }
        return count;
    }

    // 优化
    int candy2(vector<int>& ratings) {
        int size = ratings.size();
        if(size < 2) {
            return 1;
        }
        // 糖果数容器,默认每个人的糖果数为1
        vector<int> res(size, 1);
        
        // 先从左往右遍历一次,遍历完成，可以保证每个人的评分如果比左边人高，糖果数也是比他多
        for(int i = 0; i < size - 1; i++) {
            if(ratings[i + 1] > ratings[i]) {
                res[i + 1] = res[i] + 1;
            }
        }
        int count = res[size -1];
        // 从右往左遍历一次，遍历完成，可以保证每个人的评分如果比右边人高，糖果数也是比他多
        for(int i = size - 1; i > 0; i--) {
            if(ratings[i - 1] > ratings[i] && res[i - 1] <= res[i]) {
                res[i - 1] = res[i] + 1;
            }
            count += res[i - 1];
        }
        return count;
    }
};
