#include <math.h>
using namespace std;


// 平方数之和
class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = (int)floor(sqrt(c));
        while(left <= right) {
            long sum = left * left + (long)right * right;
            if(sum < c) {
                left++;
            }else if(sum > c) {
                right--;
            }else{
                return true;
            }
        }
        return false;
    }
};