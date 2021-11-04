#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

/**
 * Container Adaptors: stack测试
 * 底层：默认基于dequeue实现
 * 作用：模拟递归；单调栈
 **/
int main(int argc, char const *argv[])
{
  // 定义一个栈
  stack<int> st;
  // 没有迭代器
  // 判空
  int empty = st.empty();
  printf("is empty: %d\n", empty);
  // 大小
  printf("before insert stack's size = %d\n", st.size());
  // 压栈
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  // 出栈
  st.pop();
  // 栈顶元素
  printf("the stack's top = %d\n", st.top());
  return 0;
}
