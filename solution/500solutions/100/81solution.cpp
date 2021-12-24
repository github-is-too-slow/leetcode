#include <vector>
using namespace std;

// 搜索旋转排序数组 II
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // 左闭右闭
        int lp = 0, rp = nums.size() - 1, mid;
        while(lp <= rp) {
            mid = (lp + rp) / 2;
            if(nums[mid] == target) return true;
            if(nums[lp] == nums[mid]) {
                lp++;
            }else {
                if(nums[mid] <= nums[rp]) {
                    // 右半部分有序
                    if(nums[mid] < target && target <= nums[rp]) {
                        lp = mid + 1;
                    }else {
                        rp = mid - 1;
                    }
                }else {
                    // 左半部分有序
                    if(nums[lp] <= target && target < nums[mid]) {
                        rp = mid - 1;
                    }else {
                        lp = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};