#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node{
  int x;
  int y;
} Node;

// 自定义排序规则函数
bool cmp(Node node1, Node node2) {
  if(node1.x != node2.x) {
    //先按x从大到小排序
    return node1.x > node2.x;  // false时交换位置，从大到小
  }else {
    return node1.y < node2.y;  // false时交换位置，从小到大
  }
}

/**
 * 测试stl算法库
 **/
int main(int argc, char const *argv[])
{
  // 最大值
  cout << "1, 2, 3 max is " << max(1, max(2, 3)) << endl;
  // 最小值
  cout << "1, 2, 3 min is " << min(1, min(2, 3)) << endl;
  // 绝对值，只接受整数，小数的绝对值用math.h中的fabs函数
  cout << "-1 abs is " << abs(-1) << endl;
  // 交换值
  int a = 1;
  int b = 2;
  cout << "before swap: a = " << a << ", b = " << b << endl;
  swap(a, b);
  cout << "after swap: a = " << a << ", b = " << b << endl;
  // 通过数组指针或容器迭代器反转
  vector<int> vi;
  vi.push_back(1);
  vi.push_back(2);
  vi.push_back(3);
  vi.push_back(4);
  cout << "before reverse" << endl;
  for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++) {
    cout << "vector element is = " << *it << endl;
  }
  reverse(vi.begin(), vi.end());
  cout << "after reverse" << endl;
  for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++) {
    cout << "vector element is = " << *it << endl;
  }
  // 快速填充
  fill(vi.begin(), vi.end(), 0);
  cout << "after fill" << endl;
  for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++) {
    cout << "vector element is = " << *it << endl;
  }
  // 排序：规避了经典排序时间复杂度退化到O(n * n)的情况
  Node node1 = {1, 4}, node2 = {1, 2}, node3 {3, 4};
  vector<Node> vi_node;
  vi_node.push_back(node1);
  vi_node.push_back(node2);
  vi_node.push_back(node3);
  cout << "before sort" << endl;
  for(vector<Node>::iterator it = vi_node.begin(); it != vi_node.end(); it++) {
    cout << "vector element: x = " << (*it).x << ", y = " << (*it).y << endl;
  }
  sort(vi_node.begin(), vi_node.end(), cmp);
  cout << "after sort" << endl;
  for(vector<Node>::iterator it = vi_node.begin(); it != vi_node.end(); it++) {
    cout << "vector element: x = " << (*it).x << ", y = " << (*it).y << endl;
  }
  // 查找元素，返回数组指针或容器迭代器，前提是：有序
  vi.clear();
  vi.push_back(1);
  vi.push_back(2);
  vi.push_back(2);
  vi.push_back(3);
  vi.push_back(4);
  // low_bound下界：第一个大于等于value的元素位置
  vector<int>::iterator it;
  it = lower_bound(vi.begin(), vi.end(), 2);
  cout << "prev element is = " << *(it - 1) << endl;
  // upper_bound上界：第一个大于value的元素位置
  it = upper_bound(vi.begin(), vi.end(), 2);
  cout << "the element is = " << *it << endl;
  // 注：不存在查找值value时，lower_bound()和upper_bound()均返回插入该元素的位置指针或迭代器
  return 0;
}