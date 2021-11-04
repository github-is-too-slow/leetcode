#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;

/**
 * Associative Containers: set测试
 * 作用：对key自动去重；自动排序；判断大整数是否存在
 * 底层：元素为pair结构；红黑树
 **/
int main(int argc, char const *argv[])
{
  // 定义一个map
  map<string, int> mp;
  // 定义一个map迭代器
  map<string, int>::iterator it;
  // map大小
  printf("before insert map's size = %d\n", mp.size());
  // 插入元素
  // 形式1
  mp["aaa"] = 1;
  // 形式2
  mp.insert(make_pair("bbb", 3));
  // 形式3
  mp.insert(pair<string, int>("ccc", 4));
  mp["ddd"] = 4;
  // 通过key查询，返回对应的迭代器，指向对应的pair
  it = mp.find("bbb");
  printf("find result: %s = %d\n", it->first.c_str(), it->second);
  // 通过迭代器删除
  mp.erase(it);
  // 通过迭代器遍历
  for(it = mp.begin(); it != mp.end(); it++) {
    printf("map's element: %s = %d\n", it->first.c_str(), it->second);
  }
  // 清空map
  mp.clear();
  printf("after clear map's size = %d\n", mp.size());
  return 0;
}