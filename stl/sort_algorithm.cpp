#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 各种排序算法
class SortSolution {
public:
    // 快速排序，给定的指针：[left, right)
    void quick_sort(vector<int>& nums, int lp, int rp) {
        // 只有一个元素
        if(lp + 1 >= rp) return;
        // 选定中轴元素
        int start = lp, end = rp - 1, povit = nums[start];
        // 当start=end时退出，即为中轴元素的最终位置
        while(start < end) {
            // 先移动end指针
            while(start < end && nums[end] >= povit) {
                end--;
            }
            // 此时end元素小于povit
            nums[start] = nums[end];
            while(start < end && nums[start] <= povit) {
                start++;
            }
            nums[end] = nums[start];
        }
        // 此时start指向中轴元素的最终位置，并且该位置的元素已经被移动走了
        nums[start] = povit;
        quick_sort(nums, lp, end);
        quick_sort(nums, start + 1, rp);
    }

    // 归并排序，给定的指针：[left, right)
    void merge_sort(vector<int>& nums, int lp, int rp, vector<int>& tmp){
        if(lp + 1 >= rp) return;
        int mid = (lp + rp) / 2;
        // 分别对左右两个子数组进行归并排序
        merge_sort(nums, lp, mid, tmp);
        merge_sort(nums, mid, rp, tmp);
        // 此时左右两个数组已经有序了，可以归并了
        int lstart = lp, rstart = mid, tmpstart = lp;
        while(lstart < mid || rstart < rp) {
            // 首先将左边元素赋值给辅助数组的情况有两种
            // 第一种：右边数组已经到头了
            // 第二种：在左边数组没有到头的情况下，左边数组的当前元素值不大于右边元素
            if(rstart >= rp || (lstart < mid && nums[lstart] <= nums[rstart])) {
                tmp[tmpstart++] = nums[lstart++];
            }else {
                // 其余情况将右边元素赋值给辅助数组
                tmp[tmpstart++] = nums[rstart++];
            }
        }
        // 将辅助数组中的元素重新赋值给原数组
        for(int i = lp; i < rp; i++) {
            nums[i] = tmp[i];
        }
    }

    // 插入排序
    void insert_sort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            for(int j = i; j > 0 && nums[j] < nums[j - 1]; j--) {
                swap(nums[j - 1], nums[j]);
            }
        }
    }

    // 冒泡排序
    void bubble_sort(vector<int>& nums) {
        bool bubble;
        for(int i = 0; i < nums.size() - 1; i++) {
            bubble = false;
            for(int j = 0; j < nums.size() - 1 - i; j++) {
                if(nums[j] > nums[j + 1]){
                    swap(nums[j], nums[j + 1]);
                    bubble = true;
                }
            }
            if(!bubble) break;
        }
    }

    // 选择排序
    void select_sort(vector<int>& nums) {
        int min;
        for(int i = 0; i < nums.size() - 1; i++) {
            min = i;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] < nums[min]) {
                    min = j;
                }
            }
            if(min != i) swap(nums[i], nums[min]);
        }
    }

    void swap(int& num1, int& num2) {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    void print(vector<int> &vi) {
    printf("{");
    for(int i = 0; i < vi.size(); i++) {
        if(i == vi.size() - 1) {
            printf("%d", vi[i]);
        }else {
            printf("%d,", vi[i]);
        }
    }
    printf("}\n");
}
};

int main(int argc, char const *argv[])
{
    SortSolution solution;
    printf("===========std_sort===========\n");
    vector<int> nums{2, 3, 1, 8, 6, 7, 4, 5};
    sort(nums.begin(), nums.end());
    solution.print(nums);

    printf("===========quick_sort===========\n");
    vector<int> nums1{2, 3, 1, 8, 6, 7, 4, 5};
    solution.quick_sort(nums1, 0, nums.size());
    solution.print(nums1);

    printf("===========merge_sort===========\n");
    vector<int> nums2{2, 3, 1, 8, 6, 7, 4, 5};
    vector<int> tmp(nums2.size());
    solution.merge_sort(nums2, 0, nums.size(), tmp);
    solution.print(nums2);

    printf("===========insert_sort===========\n");
    vector<int> nums3{2, 3, 1, 8, 6, 7, 4, 5};
    solution.insert_sort(nums3);
    solution.print(nums3);

    printf("===========bubble_sort===========\n");
    vector<int> nums4{2, 3, 1, 8, 6, 7, 4, 5};
    solution.bubble_sort(nums4);
    solution.print(nums4);

    printf("===========select_sort===========\n");
    vector<int> nums5{2, 3, 1, 8, 6, 7, 4, 5};
    solution.select_sort(nums5);
    solution.print(nums5);
    return 0;
}



