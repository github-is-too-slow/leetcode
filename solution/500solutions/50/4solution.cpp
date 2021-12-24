#include <vector>
using namespace std;

// 寻找两个正序数组的中位数
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 判断是否为奇数还是偶数
        int len = nums1.size() + nums2.size();
        if(len % 2) {
            // 有奇数个
            return getKthElement(nums1, nums2, (len + 1) / 2);
        }else {
            int k1 = getKthElement(nums1, nums2, len / 2);
            int k2 = getKthElement(nums1, nums2, len / 2 + 1);
            return (k1 + k2) / 2.0;
        }

    }

    // 求出两个数组中的第k个位置的元素，从1开始计数
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int base;
        int ptr1 = 0, ptr2 = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        // 当k=1时，返回两个数组首元素中的较小者
        while(k > 1) {
            // 首先判断数组是否为空,两者不可能同时为空
            if(!len1) {
                // 返回nums2中的第k个元素
                return nums2[ptr2 + k - 1];
            }else if(!len2) {
                return nums1[ptr1 + k - 1];
            }

            // nums[base] 左侧有k/2-2个元素
            // 当k=2时，base=0,即：nums[base]中的较小者最多是第1个元素
            // 注意base是基于当前删除的起始位置ptr的偏移量，不能超过当前数组的长度-1
            base = k / 2 - 1;
            // 首先判断base是否越界了，两者不可能同时越界
            // 如果越界，选择数组的最后一个元素相比
            if(base >= len1) {
                if(nums1[nums1.size() - 1] <= nums2[ptr2 + base]) {
                    // 删除nums1中的所有元素
                    k -= len1;
                    len1 = 0;
                }else {
                    // 删除nums2中base以及左侧的所有元素
                    ptr2 += k / 2;
                    len2 -= k / 2;
                    k -= k / 2;
                }
                continue;
            }else if (base >= len2) {
                if(nums1[ptr1 + base] <= nums2[nums2.size() - 1]) {
                    ptr1 += k / 2;
                    len1 -= k / 2;
                    k -= k / 2;
                }else {
                    k -= len2;
                    len2 = 0;
                }
                continue;
            }

            // 正常情况下，比较两个数组中base处的元素大小
            if(nums1[ptr1 + base] <= nums2[ptr2 + base]) {
                // 删除nums1中base以及左侧的所有元素
                ptr1 += k / 2;
                len1 -= k / 2;
                k -= k / 2;
            }else {
                // 删除nums2中base以及左侧的所有元素
                ptr2 += k / 2;
                len2 -= k / 2;
                k -= k / 2;
            }
        }
        // 此时k = 1
        if(!len1) {
            // 返回nums2中的第k个元素
            return nums2[ptr2];
        }else if(!len2) {
            return nums1[ptr1];
        }else {
            return nums1[ptr1] <= nums2[ptr2]? nums1[ptr1]: nums2[ptr2];
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num1{3};
    vector<int> num2{1, 2, 4, 5, 6, 7, 8};
    Solution solution;
    double d = solution.findMedianSortedArrays(num1, num2);
    return 0;
}
