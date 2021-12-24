#include <vector>
using namespace std;

// 有序数组中的唯一元素
class Solution {
public:
    // 方法1
    int singleNonDuplicate1(vector<int>& nums) {
        int lp = 0, rp = nums.size() - 1, mid, k;
        while(lp <= rp) {
            mid = (lp + rp) / 2;
            k = (rp - lp) / 2;
            if(k <= 1) break;
            if(k % 2){// 两侧是奇数个
                if(nums[mid - 1] == nums[mid]) {
                    // 唯一数在右侧
                    lp = mid + 1;
                }else {
                    // 唯一数在左侧
                    rp = mid - 1;
                }
            }else {// 两侧是偶数个
                if(nums[mid - 1] == nums[mid]) {
                    // 唯一数在左侧
                    rp = mid - 2;
                }else {
                    lp = mid;
                }
            }
        }
        if(k == 0){
            return nums[lp];
        } else {
            if(nums[lp] == nums[lp + 1]) {
                return nums[rp];
            }else {
                return nums[lp];
            }
        }
    }

    // 方法2：二分搜索偶数索引
    int singleNonDuplicate(vector<int>& nums) {
        int lp = 0, rp = nums.size() - 1, mid;
        while(lp < rp) {// 当lp == rp时退出来
            mid = (lp + rp) / 2;
            if(mid % 2) mid--;
            // 判断偶数索引mid与后面一个数是否相等，进入循环至少三个元素，mid+1/mid+2总是有效索引
            if(nums[mid] == nums[mid + 1]) {
                // 唯一元素在右侧
                lp = mid + 2;
            }else {
                // 唯一元素在左侧，包括mid
                rp = mid;
            }
        }
        return nums[lp];
    }
};