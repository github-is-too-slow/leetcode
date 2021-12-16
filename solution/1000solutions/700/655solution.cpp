#include <vector>
using namespace std;

// 非递减数列
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        // 只允许改变一次
        bool flag = true;
        // 判断第一个数是否满足
        if(nums[0] > nums[1]) {
            flag = false;
        }
        for(int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if(!flag) return false;
                // 使用更改的一次机会
                flag = false;
                // 更改元素
                // 优先更改nums[i],可以时nums[i-1]<= nums[i] = nums[i+1]
                if(nums[i + 1] >= nums[i - 1]){
                    continue;
                }
                // 否则更改nums[i+1]=nums[i]
                nums[i + 1] = nums[i];
            }
        }
        return true;
    }
};