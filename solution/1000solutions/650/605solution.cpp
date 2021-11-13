#include <vector>
using namespace std;

// 种花问题
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n <= 0) {
            return true;
        }
        // 空闲区域的长度,假设从第一个元素的前置元素为0，表示空闲
        int lenOfFree = 1;
        int lenOfFlowerbed = flowerbed.size();
        // 寻找空闲区域
        for (int i = 0; i < lenOfFlowerbed; i++) {
            // 空闲
            if(!flowerbed[i]) {
                lenOfFree++;
            } else { // 不空闲
                if(lenOfFree % 2) {// 长度为偶数，比如4，则只能中4 / 2 - 1颗花
                    n -= lenOfFree / 2;
                } else {// 比如5，可以中5 / 2颗花
                    n -= lenOfFree / 2 - 1;
                }
                // 重置长度
                lenOfFree = 0;
            }
            if(n <= 0) {// 提前退出
                return true;
            }
        }
        // 最后一个区域为空闲
        if(!flowerbed[lenOfFlowerbed - 1]) {
            lenOfFree++;
            if(lenOfFree % 2) {// 长度为偶数，比如4，则只能中4 / 2 - 1颗花
                n -= lenOfFree / 2;
            } else {// 比如5，可以中5 / 2颗花
                n -= lenOfFree / 2 - 1;
            }
        }
        if(n <= 0) {
            return true;
        } else {
            return false;
        }
    }

};
