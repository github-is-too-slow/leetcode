#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

/**
 * Container Adaptors适配器: queue测试
 * 作用：先进先出；广度优先遍历
 * 底层：默认基于queue实现（循环数组）
 **/
int main(int argc, char const *argv[])
{
  // 定义一个queue
  queue<int> q;
  // 没有队列迭代器，只能api操作两端元素
  // 判空
  int empty = q.empty();
  printf("is empty: %d\n", empty);
  // 大小
  printf("before insert queue's size = %d\n", q.size());
  // 往队尾插入
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  // 从队首删除
  q.pop();
  // 去队首和队尾的元素
  if(!q.empty()) {
    printf("queue's front = %d\n", q.front());
    printf("queue's back = %d\n", q.back());
  }
  return 0;
}
