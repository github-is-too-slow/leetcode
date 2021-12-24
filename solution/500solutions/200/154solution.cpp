#include <vector>
using namespace std;


// 寻找旋转排序数组中的最小值 II
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lp = 0, rp = nums.size() - 1, mid, min = 10000;
        while(lp <= rp) {
            mid =  (lp + rp) / 2;
            if(nums[lp] == nums[mid]) {
                if(nums[lp] < min) {
                    min = nums[lp];
                }
                lp++;
            }else {// 左边不全是重复元素
                // 右边有序
                if(nums[mid] <= nums[rp]) {
                    // 先更新最小值
                    if(nums[mid] < min) {
                        min = nums[mid];
                    }
                    // 接着判断左边
                    rp = mid - 1;
                }else {
                    // 左边有序
                    if(nums[lp] < min) {
                        min = nums[lp];
                    }
                    lp = mid + 1;
                }
            }
        }
        return min;
    }
};