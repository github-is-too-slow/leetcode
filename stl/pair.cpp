#include <stdio.h>
#include <iostream>
#include <map>
// #include <utility>
using namespace std;

/**
 * 测试pair容器
 * 作用：替换成对数据结构
 **/
int main(int argc, char const *argv[])
{
  map<string, int> mp;
  // 定义形式1
  pair<string, int> pair1;
  // 定义形式2：初始化
  pair<string, int> pair2("hello", 1);
  pair<string, int> pair3("hello", 2);
  // 访问
  cout << "first = " << pair2.first << ", second = " << pair2.second << endl;
  // 定义形式3：匿名变量
  mp.insert(pair<string, int>("hello", 1));
  // 定义形式4：匿名变量
  mp.insert(make_pair("hello", 2));
  // 比较运算：先比较first成员，然后比较second成员
  int res1 = pair2 == pair3;
  int res2 = pair2 < pair3;
  cout << "res1 = " << res1 << endl;
  cout << "res2 = " << res2 << endl;
  return 0;
}
