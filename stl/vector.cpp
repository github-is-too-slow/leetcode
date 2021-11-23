#include <stdio.h>
#include <vector>
using namespace std;
/**
 * Sequence Containers： vector测试
 * 作用：存储不定长数据
 **/
int main(int argc, char** argv)
{
  // 定义一个容器
  vector<int> vi;
  // 定义一个嵌套容器，初始化为5个元素，并令嵌套容器的元素
  vector<vector<int>> vi2(5);
  for(int i = 0; i < vi2.size(); i ++) {
    // 
    printf("ele: %d\n", vi2[i].size());
  }
  
  // 求长度
  printf("before insert: vector's size = %d\n", vi.size());
  // 末尾添加一个元素
  vi.push_back(1);
  vi.push_back(2);
  vi.push_back(3);
  vi.push_back(4);
  printf("after insert: vector's size = %d\n", vi.size());
  // 末尾删除一个元素
  vi.pop_back();
  printf("after remove: vector's size = %d\n", vi.size());
  // 创建迭代器变量，并且初始化，指向第一个元素1
  vector<int>::iterator it = vi.begin();
  // 迭代器随机访问，指向第2个元素2
  it += 1;
  // 通过迭代器插入一个元素
  vi.insert(it, 5);
  // 利用迭代器循环遍历
  for(it = vi.begin(); it != vi.end(); it++) {
    // 利用迭代器访问对应元素
    printf("after insert: vector's element = %d\n", *it);
  }
  // 通过迭代器删除一个元素
  it = vi.begin() + 2;
  vi.erase(it);
  for(it = vi.begin(); it != vi.end(); it++) {
    // 利用迭代器访问对应元素
    printf("after erase: vector's element = %d\n", *it);
  }
  // 清空vector
  vi.clear();
  printf("after clear: vector's size = %d", vi.size());
  return 0;
}