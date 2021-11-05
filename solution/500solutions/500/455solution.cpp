#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    int count = 0;

    // 对胃口值和尺寸值从小到大排序
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    // 根据贪心策略依次求出最小胃口值的孩子的最小满足饼干尺寸值
    vector<int>::iterator g_it = g.begin();
    vector<int>::iterator s_it = s.begin();
    for(; g_it != g.end(); g_it++) {
      // 从饼干中挑选能够满足当前孩子胃口的最小尺寸的饼干
      for(; s_it != s.end(); s_it++) {
        if(*s_it >= *g_it) {
          count++;
          s_it++;
          break;
        }
      }
      // 如果没有可用饼干了，直接返回
      if(s_it == s.end()) {
        break;
      }
    }
    
    return count;
  }

  // 解法2
  int findContentChildren2(vector<int>& g, vector<int>& s) {
    // 排序
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    // 贪心策略
    int children = 0, cookies = 0;
    while(children < g.size() && cookies < s.size()) {
      // 如果当前饼干尺寸满足当前孩子，则children数量加1
      if(g[children] <= s[cookies]) 
        children++;
      // 尺寸不满足或满足，均指向下一个饼干
      cookies++;
    }
    return children;
  }
};