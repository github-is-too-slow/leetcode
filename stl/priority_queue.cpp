#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

typedef struct fruit {
  string name;
  int price;

  // 定义友元函数，只需要重载 < 小于号(配合着内置比较类less)，底层通过< 或 > 比较返回bool返回值
  friend bool operator < (const fruit &f1, const fruit &f2) {
    // 返回true，将右值放入堆中，返回false，将左值放入堆中，因此总是返回最大值
    // return f1.price < f2.price;
    return f1.price > f2.price;   // 始终返回最小值
  }
} Fruit;

/**
 * Container Adaptors: priority_queue优先级队列测试
 * 底层：默认基于vector实现堆结构，这个可以修改
 * 作用：O(1)时间最大值/最小值先出
 **/
int main(int argc, char const *argv[])
{
  // 定义一个优先级队列
  priority_queue<int> pq;
  // 没有迭代器
  // 判空
  int empty = pq.empty();
  printf("is empty: %d\n", empty);
  // 元素个数
  printf("before insert: priority_queue's size = %d\n", pq.size());
  // 往堆里插入元素
  pq.push(4);
  pq.push(1);
  pq.push(3);
  pq.push(2);
  // 取堆首元素
  printf("the priority_queue's top = %d\n", pq.top());
  // 删除堆首元素
  pq.pop();
  printf("the priority_queue's top = %d\n", pq.top());

  // =====================自定义优先级===============================
  printf("==============================\n");
  priority_queue<Fruit, vector<Fruit>, less<Fruit>> custom_pq;
  Fruit f1 = {"aaa", 20}, f2 = {"bbb", 30}, f3 = {"ccc", 10}, f4 = {"ddd", 40};
  custom_pq.push(f1);
  custom_pq.push(f2);
  custom_pq.push(f3);
  custom_pq.push(f4);
  printf("custom_priority_queue's top: name = %s, price = %d\n", custom_pq.top().name.c_str(), custom_pq.top().price);
  return 0;
}
