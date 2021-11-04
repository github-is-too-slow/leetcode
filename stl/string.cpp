#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

/**
 * 字符串容器测试
 * 作用：动态存储字符串
 * 底层：动态字符数组
 **/
int main(int argc, char const *argv[])
{
  // 定义一个字符串，并初始化
  string str = "abcd";
  // 字符串输入，直接覆盖掉原串，enter结束输入
  cin >> str;
  // 字符串输出
  cout << "字符串内容：" << str << endl;
  // 获取字符数组指针并输出
  printf("字符串内容：%s\n", str.c_str());
  // 长度
  printf("字符串长度 = %d\n", str.length());
  // 创建一个字符串迭代器
  string::iterator it = str.begin();
  // 在指定int型位置插入一个字符串
  str.insert(0, "zzz");
  cout << "after insert by pos: " << str <<endl;
  // 通过迭代器插入一个字符串
  it = str.end();
  str.insert(it, str.begin(), str.begin() + 3);
  cout << "after insert by iterator: " << str <<endl;
  // 删除单元素
  it = str.begin();
  str.erase(it);
  cout << "after erase by iterator: " << str <<endl;
  // 删除一个区间(pos, length)
  str.erase(0, 2);
  cout << "after insert by pos and length: " << str <<endl;
  // 获取子串，不改变原串
  string substr = str.substr(0, 3);
  cout << "substr is: " << substr <<endl;
  // 模式匹配，时间复杂度O(m * n)
  int pos = str.find("cd");
  printf("pattern's pos = %d\n", pos);
  // 字符串替换，会改变原串
  str.replace(0, 2, "hhhhh");
  cout << "after replace by pos and length: " << str <<endl;
  str.replace(str.begin(), str.begin() + 5, "xxx");
  cout << "after replace by iterator: " << str <<endl;
  // 清空字符串
  str.clear();
  printf("字符串长度 = %d\n", str.length());
  return 0;
}
