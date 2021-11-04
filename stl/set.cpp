#include <stdio.h>
#include <set>
using namespace std;

/**
 * Associative Containers：set测试
 * 作用：1. 自动去重 2. 自动排序（从小到大的有序序列）
 * 底层：红黑树，一种特殊的平衡二叉查找树
 **/
int main(int argc, char const *argv[])
{
  // 定义一个set
  set<int> st;
  // 容器大小
  printf("before insert: set's size = %d\n", st.size());
  // 插入一个元素，自动去重和递增排序，时间复杂度O(log N)
  st.insert(3);
  st.insert(2);
  st.insert(1);
  st.insert(4);
  printf("after insert: set's size = %d\n", st.size());
  // 创建一个迭代器
  set<int>::iterator it = st.begin();
  // 删除迭代器指向的元素
  st.erase(it);
  printf("after remove: set's size = %d\n", st.size());
  // 迭代访问
  for(it = st.begin(); it != st.end(); it++) {
    printf("after remove by iterator: set's element = %d\n", *it);
  }
  // 删除指定值
  st.erase(3);
  // 迭代访问
  for(it = st.begin(); it != st.end(); it++) {
    printf("after remove by value: set's element = %d\n", *it);
  }
  // 删除区间[start, end)内的值
  st.erase(st.begin(), --st.end());
  for(it = st.begin(); it != st.end(); it++) {
    printf("after remove by 区间: set's element = %d\n", *it);
  }
  // 查找一个存在的元素，返回对应的迭代器
  it = st.find(4);
  printf("find by value: set's element = %d\n", *it);
  // 查找一个不存在的元素，则返回一个将指向集合中最后一个元素之后的位置的迭代器
  it = st.find(5);
  printf("iterator is null: %d\n", it == st.end());
  // 清空set
  st.clear();
  printf("after clear: set's size = %d\n", *it);
  return 0;
}