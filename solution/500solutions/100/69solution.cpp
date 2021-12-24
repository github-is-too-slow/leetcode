#include <vector>
using namespace std;

// 开平方, 方法1：二分查找
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return x;
        int left = 1, right = x, mid, sqrt;
        while(left <= right) {
            mid = ((long)left + right) / 2;
            // 避免越界，采用除法
            sqrt = x / mid;
            if(sqrt < mid) {
                right = mid - 1;
            } else if(sqrt > mid) {
                left = mid + 1;
            }else {
                return sqrt;
            }
        }
        return right;
    }
};

// 方法2：牛顿迭代法
class Solution {
public:
    int mySqrt(int x) {
        double xn = x;
        while(xn * xn > x) {
            xn = (xn + x / xn) / 2;
        }
        return (int)xn;
    }
};