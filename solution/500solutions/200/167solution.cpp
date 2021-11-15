#include <vector>
using namespace std;


// 167. 两数之和 II - 输入有序数组
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        int low = 0, high = numbers.size() - 1, sum;
        while(1) {
            sum = numbers[low] + numbers[high];
            if(sum > target) {
                high--;
            } else if(sum < target) {
                low++;
            }else {
                break;
            }
        }
        res[0] = low + 1;
        res[1] = high + 1;
        return res;
    }
};