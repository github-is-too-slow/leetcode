#include <vector>
using namespace std;

// 在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return vector<int>{-1, -1};
        // 假设不存在的情况下，lower的值可能是：
        // 介于两个元素之间，0 <= lower < size
        // 大于所有元素：lower = size
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target);
        if(lower == nums.size() || nums[lower] != target) {
            return vector<int>{-1, -1};
        }
        return vector<int>{lower, upper - 1};
    }


    // 自实现low_bound,寻找第一个大于或等于目标值的元素位置
    int lower_bound(vector<int>& nums, int target) {
        int lp = 0, rp = nums.size(), mid;
        while(lp < rp) {
            mid = (lp + rp) / 2;
            if(nums[mid] >= target) {
                rp = mid;
            }else {
                lp = mid + 1;
            }
        }
        return lp;
    }

    // 自实现upper_bound,寻找第一个大于目标值的元素位置
    int upper_bound(vector<int>& nums, int target) {
        int lp = 0, rp = nums.size(), mid;
        while(lp < rp) {
            mid = (lp + rp) / 2;
            if(nums[mid] > target) {
                rp = mid;
            }else {
                lp = mid + 1;
            }
        }
        return lp;
    }
};